#include <iostream>
#include "AddProduct.h"
#include "MainMenu.h"
#include "StockLevel.h"
#include "Loginb.h"
#include "UserLogIn.h"

using namespace std;


int main()
{
	//Keep these two lines so everything displays right. 
	system("title Inventory Management System v1.0");
	system("mode 1000");

	//Background service to check for auto reordering.  It is independent from main thread. 
	//Argument is how often to check the entire database. Value represents minutes. 
	StockLevel checkInBackground(1);

	//all menus start here. 
	UserLogIn start;

	return 0;
}
