#pragma once
#include "DB_Connect.h"
#include <iostream>
#include "DB_Connect.h"
#include "DB_Literals.h"

#include <functional> //allows passing functions as arguments
#include "Menu.h"

using namespace std;

class Product :
    public DB_Connect,
        public Menu
{

public:
    //change this array to alter the menus
    string menus[6] = { "Product Name", "Mfg ID", "Retail Price\t$", "Low Stock Qty.","Submit", "Query" };
    string title =  "ENTER PRODUCT DATA";
    string instructions = "Use the arrow keys to navigate, or ESC to return to previous menu.";

    //this array contains the fields where the data will be stored in the database. 
    string fields[4] = { product_table::item_name, product_table::manufacturer_id, product_table::retail_price, product_table::low_stock_quantity };

    //this array holds the values that will go in the fields.  Do not change this code, as it is automated based on the fields[] array.
    string storedInMenu[4]{ "" };
 
	void displayMainMenu();
    void add();
    void search();
    void returnAll();

    string getProductID(string update_or_delete);
    string getUpdateField();
    string getNewValue();
    void update();

    bool confirmPrompt();
    void confirmAndDelete();

};

