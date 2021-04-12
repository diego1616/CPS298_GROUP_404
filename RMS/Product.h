#pragma once
#include "DB_Connect.h"

using namespace std;

class Product :
    public DB_Connect
{

public:

	void displayMainMenu();
    void add();
    void search();
    void update();
    void confirmAndDelete();

};

