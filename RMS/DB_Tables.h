
#pragma once
#include <vector>
#include <string>
#include "sqlite3.h"

class DB_Tables
{
	//I looked up SQLite syntax.  Based on https://www.sqlitetutorial.net/sqlite-create-table/

	std::string product_table =
		"CREATE TABLE IF NOT EXISTS product_table ( \
product_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
item_name TEXT NOT NULL, \
mfg_id INTEGER NOT NULL, \
mfg_part_no	TEXT, \
mfg_price	REAL, \
retail_price REAL, \
dpt_id INTEGER, \
min_stock INTEGER, \
stock INTEGER default 0, \
reorder BOOL default false \
); \n";

	std::string manufacturer_table =
		"CREATE TABLE IF NOT EXISTS manufacturer_table(	\
manufacturer_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,	\
manufacturer_name TEXT NOT NULL, \
contact_name TEXT, \
contact_email TEXT, \
street_address TEXT, \
street_name	TEXT, \
city TEXT, \
zip_code TEXT, \
state TEXT,	\
country	TEXT, \
phone_number INTEGER \
); \n";

	std::string department_table =
		"CREATE TABLE IF NOT EXISTS department_table( \
department_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
department_name TEXT \
); \n";

	std::string inventory_amounts_table =
		"CREATE TABLE IF NOT EXISTS inventory_amounts_table( \
inventory_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
product_id INTEGER NOT NULL, \
product_count INTEGER \
); \n";

	std::string keyword_table =
		"CREATE TABLE IF NOT EXISTS keyword_table( \
keyword_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
keyword_name TEXT NOT NULL \
); \n";

	std::string product_keyword_table =
		"CREATE TABLE IF NOT EXISTS product_keyword_table( \
p_key_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
keyword_id INTEGER NOT NULL, \
product_id INTEGER	NOT NULL \
); \n";


	std::string storage_table =
		"CREATE TABLE IF NOT EXISTS storage_table( \
storage_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
storage_name TEXT NOT NULL \
); \n";

	std::string storage_location_table =
		"CREATE TABLE IF NOT EXISTS storage_location_table( \
storage_loc_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
storage_id INTEGER	NOT NULL, \
product_id INTEGER	NOT NULL \
); \n";

	std::string sales_location_table =
		"CREATE TABLE IF NOT EXISTS sales_location_table( \
sales_loc_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
sales_loc_name TEXT NOT NULL \
); \n";

	std::string product_sales_location_table =
		"CREATE TABLE IF NOT EXISTS product_sales_location_table( \
product_sales_loc_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
sales_loc_id INTEGER NOT NULL, \
product_id INTEGER NOT NULL \
); \n";

	std::string user_table =
		"CREATE TABLE IF NOT EXISTS user_table( \
user_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
f_name TEXT NOT NULL, \
l_name TEXT NOT NULL, \
job_id	INTEGER, \
department_id INTEGER, \
password TEXT, \
permissions_level INTEGER \
); \n";

	

	std::string job_table =
		"CREATE TABLE IF NOT EXISTS job_table( \
job_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
job_name TEXT NOT NULL \
); \n";

	std::string permission_level_table =
		"CREATE TABLE IF NOT EXISTS permission_level_table( \
permission_level_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
permission_level_name TEXT NOT NULL \
); \n";

public:

	const std::string all_Tables = product_table + manufacturer_table + department_table + inventory_amounts_table +
		keyword_table + product_keyword_table + storage_table + storage_location_table +
		sales_location_table + product_sales_location_table + user_table + job_table + permission_level_table;


};

