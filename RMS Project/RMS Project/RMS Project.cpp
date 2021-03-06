#include <iostream>
#include "DB_Connect.h"


int main()
{

	
//I looked up SQLite syntax.  Based on https://www.sqlitetutorial.net/sqlite-create-table/, I think the syntax here is wrong.  I wrote these tables based on that.
	
	//string myq = “CREATE TABLE [IF NOT EXISTS] product_table (
	//			product_id INTEGER PRIMARY KEY NOT NULL,
 //  				item_name TEXT NOT NULL,
	//			manufacturer_id INTEGER NOT NULL,
	//			manufacturer_product_id	TEXT	NOT NULL,
	//			manufatcturer_price	REAL,
	//			retail_price	REAL,
	//			department_id	INTEGER,
	//			low_stock_quantity INTEGER,
	//			FOREIGN KEY (manufacturer_id) 
 //     				REFERENCES manufacturer_table (manufacturer_id) 
 //        				ON DELETE CASCADE 
 //        				ON UPDATE NO ACTION,
	//			FOREIGN KEY (department_id) 
	//			REFERENCES department_table (department_id) 
	//				ON DELETE CASCADE 
	//				ON UPDATE NO ACTION,
	//		);

	//		CREATE TABLE [IF NOT EXISTS] manufacturer_table (
	//			manufacturer_id INTEGER PRIMARY KEY NOT NULL,
	//			manufacturer_name	TEXT	NOT NULL,
	//			contact_name	TEXT,
	//			contact_email	TEXT,
	//			street_address	TEXT,
	//			street name	TEXT,
	//			city		TEXT,
	//			zip_code	TEXT,
	//			state	TEXT,
	//			country	TEXT,
	//			phone_number	INTEGER,
	//		);


	//		CREATE TABLE [IF NOT EXISTS] department_table (
	//			department_id	INTEGER PRIMARY KEY NOT NULL,
	//			department_name TEXT,
	//		);



	//		CREATE TABLE [IF NOT EXISTS] inventory_amounts_table (
	//			inventory_id INTEGER PRIMARY KEY NOT NULL,
	//			product_id INTEGER NOT NULL,
	//			product_count	INTEGER,
	//		FOREIGN KEY (product_id) 
	//			REFERENCES product_table (product_id) 
	//				ON DELETE CASCADE 
	//				ON UPDATE NO ACTION,
	//		);


	//		CREATE TABLE [IF NOT EXISTS] keyword_table (
	//			keyword_id INTEGER PRIMARY KEY NOT NULL,
	//			keyword_name	TEXT	NOT NULL,
	//		);

	//		CREATE TABLE [IF NOT EXISTS] product_keyword_table (
	//			p_key_id INTEGER PRIMARY KEY NOT NULL,
	//			keyword_id	INTEGER NOT NULL,
	//			product_id	INTEGER	NOT NULL,
	//		FOREIGN KEY (product_id) 
	//			REFERENCES product_table (product_id) 
	//				ON DELETE CASCADE 

	//		FOREIGN KEY (keyword_id) 
	//			REFERENCES keyword_table (keyword_id) 
	//				ON DELETE CASCADE 
	//		);



	//		CREATE TABLE [IF NOT EXISTS] storage_table (
	//			storage_id INTEGER PRIMARY KEY NOT NULL,
	//			storage_name	TEXT	NOT NULL,
	//		);


	//		CREATE TABLE [IF NOT EXISTS] storage_location_table (
	//			storage_loc_id INTEGER PRIMARY KEY NOT NULL,
	//			storage_id	INTEGER	NOT NULL,
	//			product_id	INTEGER	NOT NULL,
	//		FOREIGN KEY (storage_id) 
	//			REFERENCES storage_table (storage_id) 
	//				ON DELETE CASCADE 

	//		FOREIGN KEY (product_id) 
	//			REFERENCES product_table (product_id) 
	//				ON DELETE CASCADE
	//		);


	//		CREATE TABLE [IF NOT EXISTS] sales_location_table (
	//			sales_loc _id INTEGER PRIMARY KEY NOT NULL,
	//			sales_loc_name	TEXT	NOT NULL,
	//		);


	//		CREATE TABLE [IF NOT EXISTS] product_sales_location_table (
	//			product_sales_loc_id INTEGER PRIMARY KEY NOT NULL,
	//			sales_loc_id	INTEGER	NOT NULL,
	//			product_id	INTEGER	NOT NULL,
	//		FOREIGN KEY (sales_loc_id) 
	//			REFERENCES storage_location_table (sales_loc_id) 
	//				ON DELETE CASCADE 
	//		FOREIGN KEY (product_id) 
	//			REFERENCES product_table (product_id) 
	//				ON DELETE CASCADE
	//		);

	//		CREATE TABLE [IF NOT EXISTS] user_table (
	//			user_id INTEGER PRIMARY KEY NOT NULL,
	//			f_name	TEXT	NOT NULL,
	//			l_name	TEXT	NOT NULL,
	//			job_id	INTEGER,
	//			department_id	INTEGER,
	//			password	TEXT,
	//		FOREIGN KEY (job_id) 
	//			REFERENCES job_table (job_id) 
	//				ON DELETE CASCADE 
	//		FOREIGN KEY (department_id) 
	//			REFERENCES department_table (department_id) 
	//				ON DELETE CASCADE 
	//		);


	//		CREATE TABLE [IF NOT EXISTS] job_table (
	//			job_id INTEGER PRIMARY KEY NOT NULL,
	//			job_name	TEXT	NOT NULL,
	//		);”


DB_Connect dataBase;
char* error = new char(), * error2 = new char();

string myq = "CREATE TABLE [IF NOT EXISTS] USERS(\
 		USER_ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
 		FIRST_NAME TEXT NOT NULL, \
 		LAST_NAME TEXT NOT NULL, \
 		TITLE_ID INTEGER NOT NULL,	\
 		DEPARTMENT_ID INTEGER NOT NULL,	\
 		PASSWORD TEXT NOT NULL);";

	sqlite3_exec(dataBase.sqLiteDB, myq.c_str(), NULL, NULL, &error);

	if (error != NULL)
		cout << "Error = " << error << endl;
	else
		cout << "Inserting went fine I guess" << endl;

	system("pause");

	dataBase.insertInto("USERS", "FIRST_NAME, LAST_NAME, TITLE_ID, DEPARTMENT_ID, PASSWORD", "'diego', 'perez', 123, 456, 'beer789'");

	//dataBase.insertInto("USERS", "FIRST_NAME", "'diego'");
	
	//dataBase.insertInto("user_table", "f_name, l_name, job_id, department_id, password", "diego, perez, 123, 456, beer789");

	system("pause");

	dataBase.queryFrom("USERS", "*");

	system("pause");


	return 0;
}


