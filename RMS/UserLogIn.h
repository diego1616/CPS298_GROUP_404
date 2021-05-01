#pragma once
#include "Menu.h"
#include "DB_Connect.h"
#include "MainMenu.h"

class UserLogIn :
    public MainMenu
{
    string who;
    string userAccessLevel;

    //this array holds the values that will go in the fields.  Do not change this code, as it is automated based on the fields[] array.
    string storedInMenu[2]{ "" };

    //string acessLevel;    //this has been replaced by static variable accessLevel in the DB_Connect class
    void allowAccess(); //starts the Main_Menu Process

public:

    UserLogIn(); //constructor, it initiates the log in process
    void dbSearch(string sql, string &data); //overridden function from the DB_Connect class. gets the result from query to &data 
    void getData();
    bool validateData();
    void clearUser();

};

