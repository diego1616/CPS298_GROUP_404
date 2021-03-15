#include <iostream>
#include "DB_Connect.h"


int main()
{

	DB_Connect dataBase;

	//char* error = new char(), * error2 = new char();

	//DB_Tables tables;

	//sqlite3_exec(dataBase.sqLiteDB, tables.all_Tables.c_str(), NULL, NULL, &error);

	//	if (error != NULL)
	//		cout << "Error = " << error << endl;
	//	else
	//		cout << "The tables were created succesfully!" << endl;

	//system("pause");



	/* DELETE THIS ENTIRE COMMENT AFTER THE CODE HAS BEEN TESTED
	
	dataBase.insertInto("USERS", "FIRST_NAME, LAST_NAME, TITLE_ID, DEPARTMENT_ID, PASSWORD", "'diego', 'perez', 123, 456, 'beer789'");

	dataBase.insertInto("USERS", "FIRST_NAME", "'diego'");
	
	dataBase.insertInto("user_table", "f_name, l_name, job_id, department_id, password", "diego, perez, 123, 456, beer789");

	system("pause");

	dataBase.queryFrom("USERS", "*");

	system("pause");
	*/


	return 0;
}


