#include <string>
#include <iostream>
#include "D:\Documents\College\CPS 298\Project4\DB_Connect.h"
#include <string>
#include "Store.h"
#include "D:\Documents\College\CPS 298\Project4\MainMenu.h"


Store::Store(string d_n, string st_l_n, string sa_l_n) {
    this->department_name = d_n;
    this->storage_loc_name = st_l_n;
    this->sales_loc_name = sa_l_n;

};



 void Store::print_Main_Store_Menu() {

    // this is used to create a menu of for user class options.

    cout << "1.  Work with departments." << endl;
    cout << "2.  Work with sales locations." << endl;
    cout << "3.  Work with storage locations." << endl;
    cout << "4.  Back." << endl;
};

void Store::store_Choice() {

    int choice;
    string thing;

    MainMenu mm;

    print_Main_Store_Menu();


    cout << "Please choose the number option: ";
    choice = getNumber();

    do {

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

            mm.menu_options();
            break;
        }

        thing_Choice(thing);

    } while ((choice != 4));


    


};




void Store::print_Thing_Menu(string thing) {

    system("cls");

    cout << "1.  Add a " << thing << "." << endl;
    cout << "2.  Change a " << thing << "." << endl;
    cout << "3.  Show all " << thing << "s" << "." << endl;
    cout << "4.  Delete a " << thing << "." << endl;
    cout << "5.  Back." << endl;
};

void Store::thing_Choice(string thing) {

    int choice;
    string table;
    string field;
    string field_ID;

    print_Thing_Menu(thing);


    if (thing == "department") {
        table = table_department;
        field = "department_name";
        field_ID = "department_id";
    }
    else if (thing == "sales location") {
        table = table_sales_loc;
        field = "sales_loc_name";
        field_ID = "sales_loc_id";
    }
    else if (thing == "storage location") {
        table = table_storage_loc;
        field = "storage_name";
        field_ID = "storage_id";
    }
    else {
        cout << "error." << endl;
    };

    cout << "Please choose the number option: ";
    choice = getNumber();

    do {

        switch (choice) {

        case 1:
            add_Thing(thing, table, field);
            thing_Choice(thing);
            break;
        case 2:
            change_Thing(thing, field, table);
            thing_Choice(thing);
            break;
        case 3:
            show_All_Thing(table);
            thing_Choice(thing);
            break;
        case 4:
            delete_thing(thing, field_ID, table);
            thing_Choice(thing);
            break;
        case 5:
            store_Choice();
            break;

        }

    } while ((choice != 5));
};

void Store::add_Thing(string thing, string table, string field) {
    DB_Connect dbc_add;

    system("cls");
        
    string value;
    string sql;
    string condition;

    string thing_name;

    string yesno = "no";
    do {
        cout << "Please enter the " << thing << "'s name: ";
        getline(cin, thing_name);
        thing_name = "'" + thing_name + "'";
        cout << endl;



        cout << "Is this information correct? yes/no ";
        getline(cin, yesno);

    } while (yesno != "yes");


    condition = " WHERE " + field + " = " + thing_name;
    
    value = thing_name;


    dbc_add.insertInto(table, field, value);
    dbc_add.queryFrom(table, "*", condition);

    system("pause");
};

void Store::change_Thing(string thing, string field, string table) {
    system("cls");

    DB_Connect dbc_change;
    string name;
    string yesno = "no";
    int choice = 0;

    string new_name;

    string fields_and_values;
    string fields_and_values2;
    string condition;
    string sql;


    cout << "Please enter the " << thing << " name: ";
    getline(cin, name);
    name = "'" + name + "'";

    do {

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

    sql = dbc_change.createUpdateString(table, fields_and_values, condition);
    dbc_change.dbUpdate(sql);
    dbc_change.queryFrom(table, "*", fields_and_values2);

    system("pause");


};

void Store::show_All_Thing(string table) {

    system("cls");

    DB_Connect dbc_show_all;

    dbc_show_all.queryFrom(table, "*", "");

    system("pause");
};


void Store::delete_thing(string thing, string field, string table) {


    string ID;
    DB_Connect dbc_delete;

    string condition;
    string conditiond;
    string yesno;
    string sql;


    cout << "Please enter the id of the " << thing << " you would like to delete: ";
    getline(cin, ID);

    condition = " WHERE " + field + " = " + ID;


    dbc_delete.queryFrom(table, "*", condition);

    cout << "Are you sure you want to delete this " << thing << " ? ";
    getline(cin, yesno);
    cout << endl;

    if (yesno == "yes")
    {
        conditiond = field + " = " + ID;
        sql = dbc_delete.createDeleteString(table, conditiond);
        dbc_delete.dbUpdate(sql);
        system("pause");
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
