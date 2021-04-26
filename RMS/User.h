#pragma once
#include <string>
#include <iostream>
#include "DB_Connect.h"
using namespace std;


class User 
{
private:
	int user_id;
	string f_name;
	string l_name;
	int job_id;
	string string_job_id;
	int department_id;
	string string_department_id;
	string password;
	int permissions_level;
	string string_permissions_level;
	string enter_First = "Please enter the user's first name: ";
	string enter_Last = "Please enter the user's last name: ";
	DB_Connect db;
	string table = "user_table";
	string condition = "user_id = ";
	int int_userID;
	string string_userID;
	string fields = "";
	string values = "";
	string db_password;
	 

public:
	void add_User();
	void remove_User();
	void change_User_Information();
	void change_User_Password();
	void find_In_DB_Table();
	string find_User_By_Name();
	void print_Change_Menu();
	void see_All_Users();
	void user_Menu();
	void print_User_Menu();
	void dbSearch(string sql);
	int getNumber();
	User(string f_n = "", string l_n = "", int jb_id = 0, int de_id = 0, string psswrd = "", int per_id = 0);
	~User();
};
