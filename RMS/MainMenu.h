#pragma once
#include <string>
#include <iostream>
#include "DB_Connect.h"
#include "Product.h"
using namespace std;


class MainMenu : 
	public Menu
{
private:

public:
	void print_main_menu();
	void menu_options();
	int getNumber();
};
