#pragma once
#include <string>

ref class User
{
private:
	int user_id;
	string f_name;
	string l_name;
	int job_id;
	int department_id;
	string password;
	int permissions_id;
	string enter_First = "Please enter the user's first name: ";
	string enter_Last = "Please enter the user's last name: ";"


public:
	void set_Values(string, string, int, int, string, int);
	void add_User();
	void remove_User();
	void change_User_Information();
	void change_User_Password();
	void add_To_DB_Table();
	void find_In_DB_Table();
	void print_Menu();
	


};

