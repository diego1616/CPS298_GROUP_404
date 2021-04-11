#include <string>
#include <iostream>
#include "User.h"
#include "DB_Connect.h"



User::User(string f_n, string l_n, int jb_id, int de_id, string psswrd, int per_id) {
    this->f_name = f_n;
    this->l_name = l_n;
    this->job_id = jb_id;
    this->department_id = de_id;
    this->password = psswrd;
    this->permissions_level = per_id;

};

void User::add_User() {
    // this adds a new user

    DB_Connect dbc_add;
    string full_name;

    full_name = find_User_By_Name();

    string yesno = "no";
    do {
        cout << "Please enter the user's job identification number: ";
        job_id = getNumber();
        string_job_id = to_string(job_id);
        cout << endl;

        cout << "Please enter the user's department identification number: ";
        department_id = getNumber();
        string_department_id = to_string(department_id);
        cout << endl;

         cout << "Please enter the user's permissions level: ";
         permissions_level = getNumber();
         string_permissions_level = to_string(permissions_level);
         cout << endl;
 
         cout << "Is this information correct? yes/no";
         getline(cin, yesno);
 
     } while (yesno == "no");

     fields = "f_name, l_name, job_id, department_id, permissions_level, password";
     values = full_name + ", " + string_department_id + ", " + string_permissions_level + ", default";
     
     dbc_add.insertInto(table, fields, values);

 
     cout << "Your password is \"default\".  Please change your password now.";
     change_User_Password();


 
      // add code to clear the stream in case someone uses getline
 };
 
 string User::find_User_By_Name() {
 
      //this is used to get a user's name, to add a new user or find an existing user.
 
     bool checkFName = false;
     bool checkLName = false;
 
     string yesno = "no";
     string full_name;
 
     do {
         cout << enter_First;
         getline(cin, f_name);
         cout << endl;
         cout << enter_Last;
         getline(cin, l_name);
         cout << endl;
 
         cout << "Is " << f_name << " " << l_name << " the correct employee? yes/no";
         getline(cin, yesno);
         cout << endl;
 
     } while (yesno == "no");

 
     full_name = f_name + ", " + l_name;

     return full_name;

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
     string yesno = "no", new_f_name, new_l_name, what_Are_You_Changing;
     int new_job_id, new_department_id, new_permissions_level;
 
     do {

         

 
         print_Menu();
         cout << endl;

         cout << "Please choose the number option: ";
         number_Option = getNumber();

                      
         cout << endl;
 
         if ((number_Option != 1) && (number_Option != 2) && (number_Option != 3) && (number_Option != 4) && (number_Option != 5)
             && (number_Option != 6) && (number_Option != 7) && (number_Option != 8)) {
             cout << "That is not an option.  Please try again." << endl;
         }
 
 
     } while ((number_Option != 1) && (number_Option != 2) && (number_Option != 3) && (number_Option != 4) && (number_Option != 5)
         && (number_Option != 6) && (number_Option != 7) && (number_Option != 8));
 

     DB_Connect dbc;
     switch (number_Option) {
 
         case 1:

             
             do {
                 cout << "Please enter the new first name: ";
                 getline(cin, new_f_name);
                 cout << endl;
                 cout << "Is this correct? yes/no: ";
                 getline(cin, yesno);
             } while (yesno == "no");
 
             
             f_name = new_f_name;
             condition += string_userID;
            
             dbc.dbUpdate(table, "f_name", f_name, condition);
 
             break;
         case 2:
             do {

                 cout << "Please enter the new last name: ";
                     getline(cin, new_l_name);
                 cout << endl;
                 cout << "Is this correct? yes/no: ";
                     getline(cin, yesno);
             } while (yesno == "no");
 
             l_name = new_l_name;
             condition += string_userID;

             dbc.dbUpdate(table, "l_name", l_name, condition);
             break;
         case 3:
             do {
                 cout << "Please enter the new job number: ";
                     new_job_id = getNumber();
                 cout << endl;
                 cout << "Is this correct? yes/no: ";
                     getline(cin, yesno);
             } while (yesno == "no");
 
              job_id = new_job_id;
              string_job_id = to_string(job_id);
              condition += string_userID;

              dbc.dbUpdate(table, "job_id", string_job_id, condition);
 
             break;
         case 4:
 
             do {
                 cout << "Please enter the new department number: ";
                     new_department_id = getNumber();
                 cout << endl;
                 cout << "Is this correct? yes/no: ";
                     getline(cin, yesno);
             } while (yesno == "no");
 
                 department_id = new_department_id;
                 string_department_id = to_string(department_id);
                 condition += string_userID;

                 dbc.dbUpdate(table, "department_id", string_department_id, condition);
 
             break;
         case 5:
             do {
                 cout << "Please enter the new permission level: ";
                     new_permissions_level = getNumber();
                 cout << endl;
                 cout << "Is this correct? yes/no: ";
                     getline(cin, yesno);
             } while (yesno == "no");

             permissions_level = new_permissions_level;
             string_permissions_level = to_string(permissions_level);
             condition += string_userID;

             dbc.dbUpdate(table, "permissions_level", string_permissions_level, condition);

 
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
 
 };
 
 
 void User::change_User_Password() {
 
     //this is used to create a new password or change an existing one.
 
     string user_Entered_Password = "";
     string new_Password_1;
     string new_Password_2;

     DB_Connect dbc_pass;
 
     do {
         cout << "Please enter your old password: ";
          getline(cin, user_Entered_Password);
         cout << endl;
     } while (password != user_Entered_Password);
 
     do {
         cout << "Please enter your new password: ";
         getline(cin, new_Password_1);
         cout << endl;
 
         cout << "Please enter it again: ";
          getline(cin, new_Password_2);
         cout << endl;
 
         if (new_Password_1 != new_Password_2) {
             cout << "Your passwords do not match.  Please try again.";
         };
 
 
     } while (new_Password_1 != new_Password_2);
 
         password = new_Password_1;
        condition += string_userID;



        dbc_pass.dbUpdate(table, "password", password, condition);
 
 };
 
 void User::add_To_DB_Table() {
 
      //this is used to commit changes to the database
 
 
 };
 
 void User::find_In_DB_Table() {
      //this is used to search the database for a user
 
 };
 
 void User::print_Menu() {
 
     // this is used to create a menu of for user class options.
 
     cout << "1.  Change user's first name." << endl;
     cout << "2.  Change user's last name." << endl;
     cout << "3.  Change user's job." << endl;
     cout << "4.  Change user's department." << endl;
     cout << "5.  Change user's permissions." << endl;
     cout << "6.  Change user's password." << endl;
     cout << "7.  Create a new user." << endl;
     cout << "8.  Log out." << endl;
 
 };
 
 int User::getNumber() {
     while (true) {
         try {
 
             cin.clear();
 
            int temp(0);
            cin >> temp;

            cin.ignore(INT_MAX, '\n');

            if (!cin.good()) throw logic_error("Invalid data");

            return temp;
        }
        catch (exception e) {

            cin.clear();
            cin.ignore(INT_MAX, '\n');

            string answer("");

            cout << "something went wrong: " << e.what() << endl;
            cout << "would you like to try again? y/n : ";
            getline(cin, answer);

            if (answer[0] == 'y') { continue; }
            else break;

        }
    }
    return 0;
};

User::~User(void) {

};
