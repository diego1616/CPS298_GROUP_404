#pragma once
#include "Menu.h"
#include "DB_Connect.h"
#include "MainMenu.h"

#define BAD_CREDENTIALS(X) "USER ID " + (string)X + " LOGIN ATTEMPT FAILED" 

class UserLogIn :
    public Menu, public DB_Connect
{
    string userName;
    string password;
    string userID;
    string acessLevel;
    void allowAccess();

public:

    UserLogIn(); //constructor, it initiates the log in process
    void dbSearch(string sql, string &data); //overridden function from the DB_Connect class.  pass data by ref to have it overridden. 
    void getData();
    bool validateData();
   


};

