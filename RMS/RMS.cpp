#include <iostream>
#include "AddProduct.h"
#include "MainMenu.h"
#include "StockLevel.h"

using namespace std;


int main()
{
	//keep this line so everything displays right. 
	system("mode 1000");
	system("title Inventory Management System v1.0");

	//Diego's code for low level stock check starts.  Dont change until next comment line. It does not affect other code. Runs background
	
	StockLevel checkInBackground(1);

	//Diego's low level stock check test end. 


	MainMenu m_Menu;

	m_Menu.menu_options();





	//Query obj; //needs to be developed
	//	-searches everything
	// 
	//AddUser obj; //needs to be developed
	// 	   -to add users or mod info
	//Menu Class - already developed, but needs menu headers
	// 	   -also needs the loging of information
	// 
	// Login Class
	// 	   //
	//

	//For next week, develop the menu header, check with Katie on databases, double check the regex , add the number of query rows to the DB connect class.  
	//add the logs to the add product class before starting to copy everything. 



	
	return 0;
}
