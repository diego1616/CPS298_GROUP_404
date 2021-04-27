#pragma once
#include "DB_Connect.h"
#include <iostream>
#include "DB_Connect.h"
#include "DB_Literals.h"

#include <functional> //allows passing functions as arguments
#include "Menu.h"

#include <limits>

using namespace std;

class Product :
    public DB_Connect,
        public Menu
{

public:
 
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

