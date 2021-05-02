#pragma once
#include <string>
#include <iostream>
//#include "C:\CPS298_GROUP_404\CPS298_GROUP_404\RMS\DB_Connect.h"
#include "DB_Connect.h"

using namespace std;

class Manufacturer:
	public DB_Connect, public Menu
{

private:
	
	//DB_Connect db;
	string table = "manufacturer_table";
	string manufacturer_name;
	string contact_name;
	string contact_email;
	string street_address;
	string street_name;
	string city;
	int zip_code;
	string string_zip_code;
	string state;
	string country;
	int phone_number;
	string string_phone_number;

	string fields = "";
	string values = "";


public:
	void add_Manufacturer();
	void print_Menu();
	void print_Change_Menu();

	void change_Manufacturer_Info();
	void search_for_Manufacturer();
	void show_All_Manufacturers();
	void main_choice();
	bool check_zip(int z = 0);
	bool check_phone(int p = 0);

	//this method was defined in Manufacturer.cpp but not listed in Manufacturer.h so I simply added the line. 
	void delete_Manufacturer();


	int getNumber();


	Manufacturer(string m_n = "", string c_n = "", string c_e = "", string s_num = "", string s_n = "", string cit = "", int z_c = 0, string st = "", string coun = "", int p_n = 0);
	~Manufacturer();
};

