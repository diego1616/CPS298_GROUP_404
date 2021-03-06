#include <string>
#include <iostream>
#include "DB_Connect.h"
#include <string>
#include "Store.h"
#include "MainMenu.h"


//This class is used to manage physical information about the store and store layout


Store::Store(string d_n, string st_l_n, string sa_l_n) {
    this->department_name = d_n;
    this->storage_loc_name = st_l_n;
    this->sales_loc_name = sa_l_n;

};


 void Store::print_Main_Store_Menu() {

     //system("cls");
     bar_Title_Menu();

    // this is used to create a menu of for user class options.

    cout << "1.  Work with departments." << endl;
    cout << "2.  Work with sales locations." << endl;
    cout << "3.  Work with storage locations." << endl;
    cout << "4.  Back." << endl;
};

void Store::store_Choice() {

    int choice;
    string thing;
    EventLog log;
    //MainMenu mm;
    do {

     
    print_Main_Store_Menu();


    cout << "Please choose the number option: ";
    choice = getNumber();


        switch (choice) {

        case 1:
            thing = "department";
            break;
        case 2:
            thing = "sales location";
            break;
        case 3:
            thing = "storage location";
            break;
        case 4:
            return;
            break;
        }

        if (choice != 4 && thing != "")
            thing_Choice(thing);

    } while ((choice != 4));

};




void Store::print_Thing_Menu(string thing) {

    bar_Title_Menu();

    cout << "1.  Add a " << thing << "." << endl;
    cout << "2.  Change a " << thing << "." << endl;
    cout << "3.  Show all " << thing << "s" << "." << endl;
    cout << "4.  Delete a " << thing << "." << endl;
    cout << "5.  Back." << endl;
};

void Store::thing_Choice(string thing) {

    EventLog log;
    int choice;
    string table;
    string field;
    string field_ID;

    do {

    print_Thing_Menu(thing);
    
    if (thing == "department") {
        table = table_department;
        field = department_table::department_name;
        field_ID = department_table::department_id;
    }
    else if (thing == "sales location") {
        table = table_sales_loc;
        field = sales_location_table::sales_loc_name;
        field_ID = sales_location_table::sales_loc_id;
    }
    else if (thing == "storage location") {
        table = table_storage_loc;
        field = storage_table::storage_name;
        field_ID = storage_table::storage_id;
    }
    else {
        cout << "error." << endl;
    };

    cout << "Please choose the number option: ";
    choice = getNumber();

        switch (choice) {

        case 1:
            add_Thing(thing, table, field);

            break;
        case 2:
            change_Thing(thing, field, table);

            break;
        case 3:
            show_All_Thing(table);
     
            break;
        case 4:
            delete_thing(thing, field_ID, table);
      
            break;
        case 5:
     
            return;
            break;

        }

    } while ((choice != 5));
};

void Store::add_Thing(string thing, string table, string field) {

    string value;
    string sql;
    string condition;
    
    string thing_name;

    string yesno = "no";
    do {
        bar_Title_Menu();

        cout << "Please enter the " << thing << "'s name: ";
        getline(cin, thing_name);
        thing_name = "'" + thing_name + "'";
        cout << endl;



        cout << "Is this information correct? yes/no ";
        getline(cin, yesno);

    } while (yesno != "yes");


    condition = " WHERE " + field + " = " + thing_name;
    
    value = thing_name;


    insertInto(table, field, value);
    queryFrom(table, "*", condition);

};

void Store::change_Thing(string thing, string field, string table) {

    string name;
    string yesno = "no";
    int choice = 0;

    string new_name;

    string fields_and_values;
    string fields_and_values2;
    string condition;
    string sql;

    do {

		bar_Title_Menu();

		cout << "Please enter the " << thing << " name: ";
		getline(cin, name);
		name = "'" + name + "'";


		cout << "Please enter the new name: ";
		getline(cin, new_name);
		new_name = "'" + new_name + "'";

		cout << endl;
		cout << "Is this correct? yes/no: ";
		getline(cin, yesno);

    } while (yesno != "yes");

    condition = field + " = " + name;
    fields_and_values = field + " = " + new_name;
    fields_and_values2 = " WHERE " + field + " = " + new_name;

    sql = createUpdateString(table, fields_and_values, condition);
    dbUpdate(sql);
    queryFrom(table, "*", fields_and_values2);

};

void Store::show_All_Thing(string table) {

    queryFrom(table, "*", "");

};


void Store::delete_thing(string thing, string field, string table) {

    string ID;
    string condition;
    string conditiond;
    string yesno;
    string sql;

    bar_Title_Menu();

    cout << "Please enter the id of the " << thing << " you would like to delete: ";
    getline(cin, ID);

    condition = " WHERE " + field + " = " + ID;

    queryFrom(table, "*", condition);

    bar_Title_Menu();
    cout << "Are you sure you want to delete this " << thing << " ? ";
    getline(cin, yesno);
    cout << endl;

    if (yesno == "yes")
    {
        conditiond = field + " = " + ID;
        sql = createDeleteString(table, conditiond);
        dbUpdate(sql);
     
        show_All_Thing(table);

    }
    else {
        return;
    }



};

int Store::getNumber() {
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

Store::~Store(void) {};
