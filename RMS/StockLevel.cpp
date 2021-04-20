#include "StockLevel.h"



void StockLevel::findLowStock()
{


	//string sql = "SELECT " + ID + " FROM " + table::products + " WHERE " +  ";";

	//string sql = "SELECT " + product_table::product_id + " FROM " + table::products + " WHERE " + product_table::stock + "<" + product_table::low_stock_quantity + " LIMIT 1;";
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
	int count = 0;

	while (true) {
		
		prod_id = "";

		findLowStock();

		if (prod_id != "")
		{
			orderRequest();
			outputMsg("TEST OF THIS THREAD");
		}
		else
		{
			outputMsg("SLEEP " + to_string(count));
			count++;
			//Sleep this thread until is needed again
			std::this_thread::sleep_for(std::chrono::minutes(this->interval));
			
		}
		
		//std::this_thread::sleep_for(std::chrono::minutes(this->interval));
		outputMsg("END OF LOOP - TEST AGAIN");
		
	}
}


//this is the old someTestDanMade function. 
void StockLevel::dbSearch(string sql, bool low_stock) {
	// TODO: pass arrays of columns and eventually search criteria into function for parsing and formatting (add '' and , where needed)
// "+product_table::product_id+","+product_table::item_name+"
	sqlite3_stmt* sql_statement;
	// string sql = "SELECT " + fields + " FROM " + table + " " + condition + ";";

	size_t statement_length = strlen(sql.c_str());

	int prep = sqlite3_prepare_v2(sqLiteDB, sql.c_str(), statement_length, &sql_statement, NULL);
	int step = 0; // new int(0)



	if (prep == SQLITE_OK) {

		// Print basic header row
		// another comment
		for (int header = 0; header < sqlite3_column_count(sql_statement); header++) {
			cout << left << setw(15) << sqlite3_column_name(sql_statement, header);
		}
		cout << endl;

		while (step != SQLITE_DONE) {
			step = sqlite3_step(sql_statement);
			if (step == SQLITE_ROW) {
				// print data row
				for (int cell = 0; cell < sqlite3_column_count(sql_statement); cell++) {
					if (char* col_val = (char*)sqlite3_column_text(sql_statement, cell)) { // NB: NULL cell values will break the function prematurely; those are handled below
						if (cell == 0 && low_stock) {
							
							prod_id = col_val;
							

						}
						cout << left << setw(15) << prod_id;
					}
					else if (sqlite3_column_type(sql_statement, cell) == SQLITE_NULL) {
						cout << left << setw(15) << "NULL";
					}
				}
				cout << endl;
				// end data row
			}
		}
	}
	else {
		const char* error_message = sqlite3_errmsg(this->sqLiteDB);
	}
	sqlite3_finalize(sql_statement);
}
