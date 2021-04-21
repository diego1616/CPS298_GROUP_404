#include <iostream>
#include "AddProduct.h"
#include "MainMenu.h"
#include "StockLevel.h"

using namespace std;


int main()
{
	//keep this line so everything displays right. 
	system("title Inventory Management System v1.0");
	system("mode 1000");

	//Diego's code for low level stock check starts.  Dont change until next comment line. It does not affect other code. Runs background
	
	StockLevel checkInBackground(1);

	//Diego's low level stock check test end. 


	MainMenu m_Menu;

	m_Menu.menu_options();



	return 0;
}
