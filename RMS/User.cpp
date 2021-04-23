#include <string>
#include <iostream>
#include "User.h"
#include "DB_Connect.h"
#include "MainMenu.h"


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
 
         cout << "Is this information correct? yes/no ";
         getline(cin, yesno);
 
     } while (yesno == "no");

     fields = "f_name, l_name, job_id, department_id, permissions_level, password";
     values = "'" + full_name + "', " + string_job_id + ", " + string_department_id + ", " + string_permissions_level + ", 'default'";

     

     dbc_add.insertInto(table, fields, values);

     //string return_info = "'" + table + "'*'" + 
     //dbc_add.dbSearch();
 
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
 
         cout << "Is " << f_name << " " << l_name << " the correct employee? yes/no ";
         getline(cin, yesno);
         cout << endl;
 
     } while (yesno == "no");


 
     full_name = f_name + "', '" + l_name;

     return full_name;

 };
 
 void User::remove_User() {
 
     //this is used to remove an existing user
 
     find_User_By_Name();
 
 };
 
 void User::change_User_Information() {
 
     //this is used to change information about a user
 
     MainMenu mm;
 
     int number_Option = 0;
     string yesno = "no", new_f_name, new_l_name, what_Are_You_Changing;
     string fields_and_values;
     string condition;
     string sql;
     int new_job_id, new_department_id, new_permissions_level;

     //condition = u_ID;
 
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
             //new_contact_name = "'" + new_contact_name + "'";
             
             do {
                 cout << "Please enter the new first name: ";
                 getline(cin, new_f_name);
                 new_f_name =  "'" + new_f_name + "'";

                 cout << endl;
                 cout << "Is this correct? yes/no: ";
                 getline(cin, yesno);
             } while (yesno == "no");
 
             
             
             fields_and_values = "f_name = " + new_f_name;

             sql = dbc.createUpdateString(table, fields_and_values, condition);
             dbc.dbUpdate(sql);
            

             break;

         case 2:
             do {

                 cout << "Please enter the new last name: ";
                     getline(cin, new_l_name);
                     new_l_name = "'" + new_l_name + "'";

                 cout << endl;
                 cout << "Is this correct? yes/no: ";
                     getline(cin, yesno);
             } while (yesno == "no");
 
             fields_and_values = "l_name = " + new_l_name;

             sql = dbc.createUpdateString(table, fields_and_values, condition);
             dbc.dbUpdate(sql);

             break;
         case 3:
             do {
                 cout << "Please enter the new job number: ";
                     new_job_id = getNumber();
                     

                 cout << endl;
                 cout << "Is this correct? yes/no: ";
                     getline(cin, yesno);
             } while (yesno == "no");
 
             fields_and_values = "job_id = " + new_job_id;

             sql = dbc.createUpdateString(table, fields_and_values, condition);
             dbc.dbUpdate(sql);
             break;
         case 4:
 
             do {
                 cout << "Please enter the new department number: ";
                     new_department_id = getNumber();

                 cout << endl;
                 cout << "Is this correct? yes/no: ";
                     getline(cin, yesno);
             } while (yesno == "no");
 
             fields_and_values = "department_id = " + new_department_id;

             sql = dbc.createUpdateString(table, fields_and_values, condition);
             dbc.dbUpdate(sql);
             break;
         case 5:
             do {
                 cout << "Please enter the new permission level: ";
                     new_permissions_level = getNumber();

                 cout << endl;
                 cout << "Is this correct? yes/no: ";
                     getline(cin, yesno);
             } while (yesno == "no");

             fields_and_values = "permissions_level = " + new_permissions_level;

             sql = dbc.createUpdateString(table, fields_and_values, condition);
             dbc.dbUpdate(sql);
             break;

         case 6:
             change_User_Password();
             break;
 
         case 7:
             add_User();

             break;
 
         case 8:
             mm.menu_options();
             break;
 
     };
 
 };
 
 
 void User::change_User_Password() {
 
     //this is used to create a new password or change an existing one.
 
     string user_Entered_Password = "";
     string new_Password_1;
     string new_Password_2;

     string fields_and_values;
     string condition;
     string sql;

     DB_Connect dbc_pass;
 
     do {
         cout << "Please enter your old password: ";
          getline(cin, user_Entered_Password);
         cout << endl;
         //dbSearch(sqltrial);
     } while (db_password != user_Entered_Password);
 
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

     new_Password_1 = "'" + new_Password_1 + "'";
 
     fields_and_values = "password = " + new_Password_1;

     sql = dbc_pass.createUpdateString(table, fields_and_values, condition);
     dbc_pass.dbUpdate(sql);
 
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
     cout << "8.  Back." << endl;
 
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

/*
 void User::dbSearch(string sql) {
     // TODO: pass arrays of columns and eventually search criteria into function for parsing and formatting (add '' and , where needed)
 // "+product_table::product_id+","+product_table::item_name+"
     sqlite3_stmt* sql_statement;
     // string sql = "SELECT " + fields + " FROM " + table + " " + condition + ";";

     size_t statement_length = strlen(sql.c_str());

     int prep = sqlite3_prepare_v2(sqLiteDB, sql.c_str(), statement_length, &sql_statement, NULL);
     int step = 0; // new int(0)



     if (prep == SQLITE_OK) {

         // Print basic header row
         // another comment
         for (int header = 0; header < sqlite3_column_count(sql_statement); header++) {
             cout << left << setw(15) << sqlite3_column_name(sql_statement, header);
         }
         cout << endl;

         while (step != SQLITE_DONE) {
             step = sqlite3_step(sql_statement);
             if (step == SQLITE_ROW) {
                 // print data row
                 for (int cell = 0; cell < sqlite3_column_count(sql_statement); cell++) {
                     if (char* col_val = (char*)sqlite3_column_text(sql_statement, cell)) { // NB: NULL cell values will break the function prematurely; those are handled below
                         if (cell == 0 && low_stock) {

                             db_password = col_val;


                         }
                         cout << left << setw(15) << prod_id;
                     }
                     else if (sqlite3_column_type(sql_statement, cell) == SQLITE_NULL) {
                         cout << left << setw(15) << "NULL";
                     }
                 }
                 cout << endl;
                 // end data row
             }
         }
     }
     else {
         const char* error_message = sqlite3_errmsg(this->sqLiteDB);
     }
     sqlite3_finalize(sql_statement);
 }
 */

User::~User(void) {

};
