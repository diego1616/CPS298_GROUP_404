#include <string>
#include <iostream>
//#include "C:\CPS298_GROUP_404\CPS298_GROUP_404\RMS\DB_Connect.h"
#include "DB_Connect.h"
#include <string>
#include "Store.h"


Store::Store(string d_n, string st_l_n, string sa_l_n ) {
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

    print_Main_Store_Menu();


    cout << "Please choose the number option: ";
    choice = getNumber();

    do {

        switch (choice) {

        case 1:
            d_choice();
            break;
        case 2:
            sales_Loc_choice();
            break;
        case 3:
            storage_Loc_choice();
            break;
        case 4:
            break;
        }

    } while ((choice != 4));

};




void Store::print_D_Menu() {

    // this is used to create a menu of for user class options.

    cout << "1.  Add a department." << endl;
    cout << "2.  Change a deparment's name." << endl;
    cout << "3.  Show all departments." << endl;
    cout << "4.  Back." << endl;
};

void Store::d_choice() {
    int choice;

    print_D_Menu();


    cout << "Please choose the number option: ";
    choice = getNumber();

    do {

        switch (choice) {

        case 1:
            add_Department();
            break;
        case 2:
            change_Department_Name();
            break;
        case 3:
            show_All_Departments();
            break;
        case 4:
            break;

        }

    } while ((choice != 4));




};

void Store::add_Department() {

    DB_Connect dbc_add;

    string fields;
    string values;
    string sql;
    string conditions;

    string yesno = "no";
    do {
        cout << "Please enter the dpartment's name: ";
        getline(cin, department_name);
        cout << endl;

       

        cout << "Is this information correct? yes/no ";
        getline(cin, yesno);

    } while (yesno == "no");



    fields = "dparment_name";
    values = department_name;

    dbc_add.insertInto(table_department, fields, values);

    conditions = "department_name = " + department_name;


    dbc_add.queryFrom(table_department, "*", conditions);

    d_choice();
};

void Store::change_Department_Name() {
    DB_Connect dbc_change;
    string department_name;
    string yesno = "no";
    int choice = 0;

    string new_depart_name;
       
    string fields_and_values;
    string sql;


    cout << "Please enter the department name: ";
    getline(cin, department_name);

    do {
       



        cout << "Please enter the new name: ";
        getline(cin, new_depart_name);
        cout << endl;
        cout << "Is this correct? yes/no: ";
        getline(cin, yesno);

    } while (yesno != "yes");


            fields_and_values = "dpartment_name = " + new_depart_name;

            sql = dbc_change.createUpdateString(table_department, fields_and_values, department_name);
            dbc_change.dbUpdate(sql);


            d_choice();
    
       

};

void Store::show_All_Departments() {
    DB_Connect dbc_show_all;

    dbc_show_all.queryFrom(table_department, "*", "");

    d_choice();

};





void Store::print_Sales_Loc_Menu() {

    // this is used to create a menu of for user class options.

    cout << "1.  Add a sales location." << endl;
    cout << "2.  Change a sales locations." << endl;
    cout << "3.  Show all sales locations." << endl;
    cout << "4.  Back." << endl;
};

void Store::sales_Loc_choice() {
    int choice;

    print_Sales_Loc_Menu();


    cout << "Please choose the number option: ";
    choice = getNumber();

    do {

        switch (choice) {

        case 1:
            add_Sales_Location();
            break;
        case 2:
            change_Sales_Location();
            break;
        case 3:
            show_All_Sales_Locations();
            break;
        case 4:
            break;

        }

    } while ((choice != 4));

    store_Choice();


}

void Store::add_Sales_Location() {

    DB_Connect dbc_add;

    string fields;
    string values;
    string sql;
    string conditions;

    string yesno = "no";
    do {
        cout << "Please enter the sale's location: ";
        getline(cin, sales_loc_name);
        cout << endl;



        cout << "Is this information correct? yes/no ";
        getline(cin, yesno);

    } while (yesno == "no");



    fields = "sales_loc_name";
    values = sales_loc_name;

    dbc_add.insertInto(table_sales_loc, fields, values);

    conditions = "sales_loc_name = " + sales_loc_name;


    dbc_add.queryFrom(table_department, "*", conditions);

    sales_Loc_choice();
};

void Store::change_Sales_Location() {
    DB_Connect dbc_change;
    string sales_name;
    string yesno = "no";
    int choice = 0;

    string new_sales_name;

    string fields_and_values;
    string conditions;
    string sql;


    cout << "Please enter the sales location: ";
    getline(cin, sales_loc_name);

    do {

        cout << "Please enter the new name: ";
        getline(cin, new_sales_name);
        cout << endl;
        cout << "Is this correct? yes/no: ";
        getline(cin, yesno);

    } while (yesno != "yes");


    fields_and_values = "sales_loc_name = " + new_sales_name;

    conditions = "sales_loc_name = " + sales_loc_name;
    sql = dbc_change.createUpdateString(table_sales_loc, fields_and_values, conditions);
    dbc_change.dbUpdate(sql);


    dbc_change.queryFrom(table_sales_loc, "*", conditions);

    sales_Loc_choice();

};

void Store::show_All_Sales_Locations() {
    DB_Connect dbc_show_all;

    dbc_show_all.queryFrom(table_sales_loc, "*", "");

    sales_Loc_choice();

};




void Store::print_Storage_Loc_Menu() {

    // this is used to create a menu of for user class options.

    cout << "1.  Add a storage location." << endl;
    cout << "2.  Change a storage location." << endl;
    cout << "3.  Show all storeage locations." << endl;
    cout << "4.  Back." << endl;
};

void Store::storage_Loc_choice() {
    int choice;

    print_Storage_Loc_Menu();


    cout << "Please choose the number option: ";
    choice = getNumber();

    do {

        switch (choice) {

        case 1:
            add_Storage_Location();
            break;
        case 2:
            change_Storage_Location();
            break;
        case 3:
            show_Storage_Location();
            break;
        case 4:
            break;

        }

    } while ((choice != 4));

    store_Choice();


}


void Store::add_Storage_Location() {

    DB_Connect dbc_add;

    string fields;
    string values;
    string sql;
    string conditions;

    string yesno = "no";
    do {
        cout << "Please enter the storage location: ";
        getline(cin, storage_loc_name);
        cout << endl;



        cout << "Is this information correct? yes/no ";
        getline(cin, yesno);

    } while (yesno == "no");



    fields = "storage_loc_name";
    values = storage_loc_name;

    dbc_add.insertInto(table_storage_loc, fields, values);

    conditions = "storage_loc_name = " + storage_loc_name;


    dbc_add.queryFrom(table_storage_loc, "*", conditions);

    storage_Loc_choice();
};

void Store::change_Storage_Location() {
    DB_Connect dbc_change;
    string storage_loc_name;
    string yesno = "no";
    int choice = 0;

    string new_storage_name;

    string fields_and_values;
    string sql;


    cout << "Please enter the department name: ";
    getline(cin, storage_loc_name);

    do {

        cout << "Please enter the new name: ";
        getline(cin, new_storage_name);
        cout << endl;
        cout << "Is this correct? yes/no: ";
        getline(cin, yesno);

    } while (yesno != "yes");


    fields_and_values = "storage_loc_name = " + new_storage_name;

    sql = dbc_change.createUpdateString(table_storage_loc, fields_and_values, storage_loc_name);
    dbc_change.dbUpdate(sql);

    storage_Loc_choice();


};

void Store::show_Storage_Location() {
    DB_Connect dbc_show_all;

    dbc_show_all.queryFrom(table_storage_loc, "*", "");
    storage_Loc_choice();
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