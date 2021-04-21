#include "LogIn.h"

LogIn::LogIn()
{
}

void LogIn::aut()
{
	EventLog log;

	//create code to log in, menus and such
	string stm = "sqlite statement goes here";
	
	log.logEvent("user sonso tried to hack us, whatc out for him",true);

	//db.query(stm);
	query(stm);
}



//this is the old someTestDanMade function. 
void LogIn::dbSearch(string sql) {
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
		//for (int header = 0; header < sqlite3_column_count(sql_statement); header++) {
		//	cout << left << setw(15) << sqlite3_column_name(sql_statement, header);
		//}
		//cout << endl;

		while (step != SQLITE_DONE) {
			step = sqlite3_step(sql_statement);
			if (step == SQLITE_ROW) {
				// print data row
				for (int cell = 0; cell < sqlite3_column_count(sql_statement); cell++) {
					if (char* col_val = (char*)sqlite3_column_text(sql_statement, cell)) { // NB: NULL cell values will break the function prematurely; those are handled below
						if (cell == 0) {

							level = col_val;


						}
						//cout << left << setw(15) << prod_id;
					}
					else if (sqlite3_column_type(sql_statement, cell) == SQLITE_NULL) {
						//cout << left << setw(15) << "NULL";
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
