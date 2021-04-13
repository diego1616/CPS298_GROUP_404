#pragma once
#include <string>
#include <iostream>
#include "C:\CPS298_GROUP_404\CPS298_GROUP_404\RMS\DB_Connect.h"

using namespace std;

class Store 
{
private:

	string table_department = "department_table";
	string table_storage_loc = "storage_location_table";
	string table_sales_loc = "sales_location_table";
	string department_name;
	string storage_loc_name;
	string sales_loc_name;


public:

	Store(string d_n = "", string st_l_n = "", string sa_l_n = "");
	~Store();

	void print_Main_Store_Menu();
	void store_Choice();

	void d_choice();
	void print_D_Menu();
	void add_Department();
	void change_Department_Name();
	void show_All_Departments();


	void print_Sales_Loc_Menu();
	void sales_Loc_choice();
    void add_Sales_Location();
	void change_Sales_Location();
	void show_All_Sales_Locations();

	void print_Storage_Loc_Menu();
	void storage_Loc_choice();
    void add_Storage_Location();
	void change_Storage_Location();
	void show_Storage_Location();
			
	int getNumber();
}; 