#include <iostream>
#include "DB_Connect.h"
#include <string>
#include "Manufacturer.h"
#include "MainMenu.h"


Manufacturer::Manufacturer(string m_n, string c_n, string c_e, string s_num, string s_n, string cit, int z_c, string st, string coun, int p_n) {
    this->manufacturer_name = m_n;
    this->contact_name = c_n;
    this->contact_email = c_e;
    this->street_name = c_n;
    this->street_address = s_n;
    this->city = cit;
    this->zip_code = z_c;
    this->state = st;
    this->country = coun;
    this->phone_number = p_n;

};

void Manufacturer::print_Menu() {

    // this is used to create a menu of for user class options.
    
    //line added for display purposes
    //system("cls");
    bar_Title_Menu();
    
    cout << "1.  Add a manufacturer." << endl;
    cout << "2.  Change a manufacturer's information." << endl;
    cout << "3.  Find a manufacturer." << endl;
    cout << "4.  Show all manufactuers." << endl;
    cout << "5.  Delete a manufactuer." << endl;
    cout << "6.  Go back." << endl;
};

void Manufacturer::main_choice() {
     
    int choice;
    //MainMenu mm;


    do {

    print_Menu();

    cout << "Please choose the number option: ";

    choice = getNumber();


        switch (choice) {

            case 1:
                add_Manufacturer();
                
                //main_choice();

                break;
            case 2:
                change_Manufacturer_Info();

                //main_choice();
                break;
            case 3:
                search_for_Manufacturer();

                //main_choice();
                break;
            case 4:
                show_All_Manufacturers();

                //main_choice();
                break;

            case 5:
                delete_Manufacturer();
                //main_choice();
                break;
            case 6:
                
                //mm.menu_options();
                return;
                break;

        }

    } while ((choice != 5));

   


}


void Manufacturer::print_Change_Menu() {
    
    bar_Title_Menu();

    cout << "1.  Change manufactuer's name." << endl;
    cout << "2.  Change manufactuer's contact name." << endl;
    cout << "3.  Change manufactuer's contact email." << endl;
    cout << "4.  Change manufactuer's address." << endl;
    cout << "5.  Change manufactuer's phone number." << endl;
    cout << "6.  Back." << endl;


}

void Manufacturer::add_Manufacturer() {

    //DB_Connect dbc_add;
    
    string sql;
    string conditions;

    string yesno = "no";

    //system("cls");

    do {
        //line added for display purposes
        bar_Title_Menu();

        cout << "Please enter the manufacturer's name: ";
        getline(cin, manufacturer_name);
        cout << endl;

        cout << "Please enter the manufacturer's contact name: ";
        getline(cin, contact_name);
        cout << endl;


        cout << "Please enter the manufacturer's contact email: ";
        getline(cin, contact_email);
        cout << endl;

        cout << "Please enter the manufacturer's street number: ";
        getline(cin, street_address);
        cout << endl;

        cout << "Please enter the manufacturer's street name: ";
        getline(cin, street_name);
        cout << endl;

        cout << "Please enter the manufacturer's city: ";
        getline(cin, city);
        cout << endl;

        cout << "Please enter the manufacturer's zip code: ";
        zip_code = getNumber();
        string_zip_code = to_string(zip_code);
        cout << endl;

        cout << "Please enter the manufacturer's state: ";
        getline(cin, state);
        cout << endl;

        cout << "Please enter the manufacturer's country: ";
        getline(cin, country);
        cout << endl;

        cout << "Please enter the manufacturer's phone number: ";
        //phone_number = getNumber();

        getline(cin, string_phone_number);
        //string_phone_number = to_string(phone_number);
        cout << endl;

        cout << "Is this information correct? yes/no ";
        getline(cin, yesno);

    } while (yesno == "no");



    fields = "manufacturer_name, contact_name, contact_email, street_address, street_name, city, zip_code, state, country, phone_number";
   // values = manufacturer_name + ", " + contact_name + ", " + contact_email + ", " + street_address + ", " + street_name + ", " + city + ", " + string_zip_code + ", " + state + ", " + country + ", " 
      //  + string_phone_number;


    //values = "'" + full_name + "', " + string_job_id + ", " + string_department_id + ", " + string_permissions_level + ", 'default'";

    values = "'" + manufacturer_name + "', '" + contact_name + "', '" + contact_email + "', '" + street_address + "', '" + street_name + "', '" + city + "', " + string_zip_code + ", '" + state + "', '" +
        country + "', " + string_phone_number;

    cout << values;

    //dbc_add.insertInto(table, fields, values);
    insertInto(table, fields, values);

    //conditions = "manufacturer_name = " + manufacturer_name;


    //dbc_add.queryFrom(table, "*", conditions);

    //main_choice();


};

void Manufacturer::change_Manufacturer_Info() {

    //DB_Connect dbc_change;
    string man_ID;
    int choice = 0;
    string condition;

    //system("cls");

    search_for_Manufacturer();

    cout << "Please enter the manufacturer ID: ";
    getline(cin, man_ID);
    man_ID = "'" + man_ID + "'";

    condition = " manufacturer_id = " + man_ID;

    do {
        print_Change_Menu();

        string new_manufacturer_name;
        string new_contact_name;
        string new_contact_email;
        string new_street_address;
        string new_street_name;
        string new_city;
        string new_string_zip_code;
        string new_state;
        string new_country;
        string new_string_phone_number;

        string yesno = "no";
        string fields_and_values;
        string sql;

        cout << "Please choose the number option: ";
        choice = getNumber();


        switch (choice) {

            case 1:
                do {
                    cout << "Please enter the new name: ";
                    getline(cin, new_manufacturer_name);
                    new_manufacturer_name = "'" + new_manufacturer_name + "'";

                    cout << endl;
                    cout << "Is this correct? yes/no: ";
                    getline(cin, yesno);
                } while (yesno == "no");


                fields_and_values = "manufacturer_name = " + new_manufacturer_name;

                //sql = dbc_change.createUpdateString(table, fields_and_values, condition);
                //dbc_change.dbUpdate(sql);

                sql = createUpdateString(table, fields_and_values, condition);
                dbUpdate(sql);

                
                break;

            case 2:

                do {
                    cout << "Please enter the new contact name: ";
                    getline(cin, new_contact_name);
                    new_contact_name = "'" + new_contact_name + "'";

                    cout << endl;
                    cout << "Is this correct? yes/no: ";
                    getline(cin, yesno);
                } while (yesno == "no");


                fields_and_values = "contact_name = " + new_contact_name;

                //sql = dbc_change.createUpdateString(table, fields_and_values, condition);
                //dbc_change.dbUpdate(sql);

                sql = createUpdateString(table, fields_and_values, condition);
                dbUpdate(sql);

                break;


            case 3:

                do {
                    cout << "Please enter the new contact email: ";
                    getline(cin, new_contact_email);
                    new_contact_email = "'" + new_contact_email + "'";

                    cout << endl;
                    cout << "Is this correct? yes/no: ";
                    getline(cin, yesno);

                } while (yesno == "no");


                fields_and_values = "contact_email = " + new_contact_email;

                //sql = dbc_change.createUpdateString(table, fields_and_values, condition);
                //dbc_change.dbUpdate(sql);

                sql = createUpdateString(table, fields_and_values, condition);
                dbUpdate(sql);

                break;

            case 4:

                do {
                    cout << "Please enter the new contact street number: ";
                    getline(cin, new_street_address);
                    new_street_address = "'" + new_street_address + "'";

                    cout << endl;

                    cout << "Please enter the new contact street name: ";
                    getline(cin, new_street_name);
                    new_street_name = "'" + new_street_name + "'";
                    cout << endl;

                    cout << "Please enter the new city: ";
                    getline(cin, new_city);
                    new_city = "'" + new_city + "'";
                    cout << endl;

                    cout << "Please enter the new zip code: ";
                    getline(cin, new_string_zip_code);
                    new_string_zip_code = "'" + new_string_zip_code + "'";
                    cout << endl;

                    cout << "Please enter the new state: ";
                    getline(cin, new_state);
                    new_state = "'" + new_state + "'";
                    cout << endl;

                    cout << "Please enter the new country: ";
                    getline(cin, new_country);
                    new_country = "'" + new_country + "'";
                    cout << endl;


                    cout << "Is this correct? yes/no: ";
                    getline(cin, yesno);

                } while (yesno == "no");

                fields_and_values = "street_address = " + new_street_address + ", street_name = " + new_street_name + ", city = " + new_city + ", zip_code = " + new_string_zip_code + 
                    ", state = " + new_state + ", country = " + new_country;


                //sql = dbc_change.createUpdateString(table, fields_and_values, condition);
                //dbc_change.dbUpdate(sql);

                sql = createUpdateString(table, fields_and_values, condition);
                dbUpdate(sql);

                break;

            case 5:

                do {
                    cout << "Please enter the new phone number: ";
                    getline(cin, new_string_phone_number);
                    new_string_phone_number = "'" + new_string_phone_number + "'";

                    cout << endl;
                    cout << "Is this correct? yes/no: ";
                    getline(cin, yesno);

                } while (yesno == "no");


                fields_and_values = "phone_number = " + new_string_phone_number;

                //sql = dbc_change.createUpdateString(table, fields_and_values, condition);
                //dbc_change.dbUpdate(sql);

                sql = createUpdateString(table, fields_and_values, condition);
                dbUpdate(sql);

                break;

            case 6:
                break;
    
        }


    } while (choice != 6);
    
    main_choice();
 };


void Manufacturer::search_for_Manufacturer() {

    //system("cls");
    bar_Title_Menu();

    //DB_Connect dbc_search;
    string name;
    string condition; 
   
    cout << "Please enter the name of the manufacturer you wish to find: ";
    getline(cin, name);

    name = "'" + name + "'";

    cout << name;

    condition = " WHERE manufacturer_name = " + name;
    //dbc_search.queryFrom(table, "*", condition);

    queryFrom(table, "*", condition);
 
};

void Manufacturer::show_All_Manufacturers() {

    //system("cls");
    bar_Title_Menu();

    //DB_Connect dbc_show_all;

    //dbc_show_all.queryFrom(table, "*", "");

    queryFrom(table, "*", "");

    //system("pause");
};

void Manufacturer::delete_Manufacturer() {

    string man_ID;

    //DB_Connect dbc_delete;

    string sql;
    string condition;
    string conditiond;

    string yesno = "no";

    //system("cls");
    bar_Title_Menu();

    cout << "Please enter the manufacturer's ID: ";
    getline(cin, man_ID);

    man_ID = "'" + man_ID + "'";


    condition = " WHERE manufacturer_id = " + man_ID;

    
    //dbc_delete.queryFrom(table, "*", condition);

    queryFrom(table, "*", condition);
    bar_Title_Menu();
    cout << "Are you sure you want to delete this manufacturer? ";
    getline(cin, yesno);
    cout << endl;

    if (yesno == "yes")    
    {
        //conditiond = " manufacturer_id = " + man_ID;
        //sql = dbc_delete.createDeleteString(table, conditiond);
        //dbc_delete.dbUpdate(sql);
        //system("pause");

        sql = createDeleteString(table, conditiond);
        dbUpdate(sql);

    }

};

int Manufacturer::getNumber() {
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

bool Manufacturer::check_zip(int z) {
    if ((z >= 00501) && (z <= 99950)) {
        return true;
    }
    else
    {
        return false;
    }

};

bool Manufacturer::check_phone(int p) {
    if ((p <= 1000000000) && (p <= 9999999999)) {
        return true;
    }
    else {
        return false;

    }
};

Manufacturer::~Manufacturer(void) {};
