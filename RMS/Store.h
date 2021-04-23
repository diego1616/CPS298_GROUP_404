#pragma once
#include <string>
#include <iostream>
//#include "C:\CPS298_GROUP_404\CPS298_GROUP_404\RMS\DB_Connect.h"
#include "D:\Documents\College\CPS 298\Project4\DB_Connect.h"

using namespace std;

class Store
{
private:

	string table_department = "department_table";
	string table_storage_loc = "storage_table";
	string table_sales_loc = "sales_location_table";
	string department_name;
	string storage_loc_name;
	string sales_loc_name;


public:

	Store(string d_n = "", string st_l_n = "", string sa_l_n = "");
	~Store();

	void print_Main_Store_Menu();
	void store_Choice();

	

    void print_Thing_Menu(string thing);
    void thing_Choice(string thing);
    void add_Thing(string thing, string table, string field);
    void change_Thing(string thing, string field, string table);
    void show_All_Thing(string table);
	void delete_thing(string type, string type_ID, string table);

	int getNumber();

}; 
