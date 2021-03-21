#include "User.h"


//please use getline instead of cin
//fix constructor name

User::User() {

	

}


void User::set_Values(string f_n, string l_n, int jb_id, int de_id, string psswrd, int per_id) {

	//this sets the constructors
	this->l_name = l_n;
	this->job_id = jb_id;
	this->department_id = de_id;
	this->password = psswrd;
};

void User::add_User() {

	//this adds a new user

	find_User_By_Name();

	string yesno = "no";
	do {
		cout << "Please enter the user's job identification number: " ;
		cin >> job_id;
		cout << endl;

		cout << "Please enter the user's department identification number: ";
		cin >> department_id;
		cout << endl;

		cout << "Please enter the user's permissions level: ";
		cin >> permissions_id;
		cout << endl;

		cout << "Is this information correct? yes/no";
		cin >> yesno;

	} while (yesno == "no");

	cout << "Your password is \"default\".  Please change your password now.";
		change_User_Password();

		//add code to clear the stream in case someone uses getline
};

void User::find_User_By_Name() {

	//this is used to get a user's name, to add a new user or find an existing user.

	bool checkFName = false;
	bool checkLName = false;

	string yesno = "no";

	do {
		cout << enter_First;
		cin >> f_name;
		cout << endl;
		cout << enter_Last;
		cin >> l_name;
		cout << endl;

		cout << "Is " << f_name << " " << l_name << " the correct employee? yes/no";
			cin >> yesno;
		cout << endl;

	} while (yesno == "no");

	//add code to clear the stream in case someone uses getline

	//the code below is not perfect, it has some erros.  needs to be fixed. 
	//checkFName = db.generalQuery(this->f_name, "User");
	//checkLName = db.generalQuery(this->l_name, "User");

	//if (checkFName && checkLName)
	//	cout << " this user already exist";
};

void User::remove_User() {

	//this is used to remove an existing user

	find_User_By_Name();

};

void User::change_User_Information() {

	//this is used to change information about a user

	int number_Option = 0;
	string yesno = "no", new_f_name;

	cout << "What would you like to do?" << endl;
	
	this->print_Menu();
	
	cout << "Please choose the number option: ";
	
	cin >> number_Option;
	
	cout << endl;

	switch(number_Option) {
		case 1:
			do {
				cout << "Please enter the new first name: ";
					cin >> new_f_name;
				cout << endl;
				cout << "Is this correct? yes/no: ";
					cin >> yesno;
			} while (yesno == "no");

				f_name = new_f_name;
			add_To_DB_Table();

			break;
		case 2:
			do {
				cout << "Please enter the new last name: "
					cin >> new_l_name;
				cout << endl;
				cout << "Is this correct? yes/no: "
					cin >> yesno;
			} while (yesno = "no")

				l_name = new_l_name;
			add_To_DB_Table();

			break;
		case 3:
			do {
				cout << "Please enter the new job number: "
					cin >> new_job_id;
				cout << endl;
				cout << "Is this correct? yes/no: "
					cin >> yesno;
			} while (yesno = "no")

				job_id = new_job_id;
			add_To_DB_Table();

			break;
		case 4:
			what_Are_You_Changing = "department_id_num";

			do {
				cout << "Please enter the new department number: "
					cin >> new_department_id;
				cout << endl;
				cout << "Is this correct? yes/no: "
					cin >> yesno;
			} while (yesno = "no")

				department_id = new_department_id;
			add_To_DB_Table();

			break;
		case 5:
			do {
				cout << "Please enter the new permission level: "
					cin >> new_permission_id;
				cout << endl;
				cout << "Is this correct? yes/no: "
					cin >> yesno;
			} while (yesno = "no")

				permission_id = new_permission_id;
			add_To_DB_Table();

			break;
		case 6:
			change_User_Password();
			break;

		case 7:
			add_User();
			break;

		case 8:
			return;

	};


	change_User_Information();

};

void User::change_User_Password() {

	//this is used to create a new password or change an existing one.

	string user_Entered_Password = "";
	string new_Password_1;
	string new_Password_2;

	do {
		cout << "Please enter your old password: ";
		cin >> user_Entered_Password;
		endl;
	} while (password != user_Entered_Password);

	do {
		cout << "Please enter your new password: ";
		cin >> new_Password_1;
		endl;

		cout << "Please enter it again: ";
		cin >> new_Password_2;
		endl;

		if (new_Password_1 != new_Password_2) {
			cout << "Your passwords do not match.  Please try again."
		};


	} while (new_Password_1 != new_Password_2)

		password = new_Password_1;
	add_To_DB_Table();

};

void User::add_To_DB_Table() {

	//this is used to commit changes to the database


};

void User::find_In_DB_Table() {
	//this is used to search the database for a user

};

void User::print_Menu() {

	//this is used to create a menu of for user class options.

	cout << "1.  Change user's first name." << endl;
	cout << "2.  Change user's last name." << endl;
	cout << "3.  Change user's job." << endl;
	cout << "4.  Change user's department." << endl;
	cout << "5.  Change user's permissions." << endl;
	cout << "6.  Change user's password." << endl;
	cout << "7.  Create a new user." << endl;
	cout << "8.  Log out." << endl;

};

String::~User() { delete[] user_id, f_name, string l_name, job_id, department_id, string password, permissions_id, enter_First, enter_Last; }

//do I use commas or semicolons??