#include <iostream>
#include "AddProduct.h"
#include "MainMenu.h"
#include "StockLevel.h"
#include "Loginb.h"
#include "UserLogIn.h"

using namespace std;


int main()
{
	//keep this line so everything displays right. 
	system("title Inventory Management System v1.0");
	system("mode 1000");

	StockLevel checkInBackground(1);

	UserLogIn start;

	/*MainMenu start;
	start.menu_options();*/

	return 0;
}
