#pragma once
#include "DB_Connect.h"
#include <iostream>
#include "DB_Connect.h"
#include "DB_Literals.h"
#include "AddProduct.h"
#include "Menu.h"

using namespace std;

class AddProduct :
    public DB_Connect,
        public Menu
{

public:

    //const string item_name = "item_name";
    //const string manufacturer_id = "manufacturer_id";
    //const string retail_price = "retail_price";
    //const string low_stock_quantity = "low_stock_quantity";

    //change this array to alter the menus
    string menus[6] = { "Product Name", "Mfg ID", "Retail Price\t$", "Low Stock Qty.","Submmit", "Query" };

    //this array contains the fields where the data will be stored in the database. 
    string fields[4] = { product_table::item_name, product_table::manufacturer_id, product_table::retail_price, product_table::low_stock_quantity };

    //this array holds the values that will go in the fields.  Do not change this code, as it is automated based on the fields[] array.
    string storedInMenu[4]{ "" };
 
    //function to start the display
    void viewingEnviroment();



};

