#include "StockLevel.h"

void StockLevel::findLowStock()
{

	string sql = "SELECT "+ product_table::product_id +" FROM "+ table::products +" WHERE "+ product_table::stock +" < "+ product_table::low_stock_quantity +" AND "+product_table::reorder+" = 0 LIMIT 1;";

	StockLevel::dbSearch(sql, true);

}

void StockLevel::orderRequest() {

	//build sql statement here

	string tmp = prod_id;
	string sql = "UPDATE "+table::products+" SET "+product_table::reorder+" = true WHERE "+product_table::product_id+" = " + tmp + ";";

	this->dbUpdate(sql);
}

void StockLevel::checkLoop()
{
	EventLog log;

	while (true) {
		
		prod_id = "";

		findLowStock();

		if (prod_id != "")
		{
			orderRequest();
			log.logEvent("PRODUCT ID " + prod_id + " PLACED IN AUTO ORDERING LIST");
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::minutes(this->interval));
			
		}

	}
}


void StockLevel::dbSearch(string sql, bool low_stock) {

	sqlite3_stmt* sql_statement;

	size_t statement_length = strlen(sql.c_str());

	int prep = sqlite3_prepare_v2(sqLiteDB, sql.c_str(), (int)statement_length, &sql_statement, NULL);
	int step = 0;

	if (prep == SQLITE_OK) {

		while (step != SQLITE_DONE) {
			step = sqlite3_step(sql_statement);
			if (step == SQLITE_ROW) {
				// print data row
				for (int cell = 0; cell < sqlite3_column_count(sql_statement); cell++) {
					if (char* col_val = (char*)sqlite3_column_text(sql_statement, cell)) { // NB: NULL cell values will break the function prematurely; those are handled below
						if (cell == 0 && low_stock) {
							
							prod_id = col_val;
						}
						
					}
					else if (sqlite3_column_type(sql_statement, cell) == SQLITE_NULL) {

					}
				}
			}
		}
	}
	else {
		const char* error_message = sqlite3_errmsg(this->sqLiteDB);
	}
	sqlite3_finalize(sql_statement);
}
