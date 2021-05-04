#include "Product.h"
#include "MainMenu.h"

void Product::displayMainMenu() {
	
	
	int user_input = 0;

	while (user_input > 1 || user_input < 5) {

		bar_Title_Menu();

		cout << "\nSelect an option (1-4):\n";
		cout << "\t1. Add product\n";
		cout << "\t2. Search products\n";
		cout << "\t3. Update product info\n";
		cout << "\t4. Delete product\n";
		cout << "\t5. [EXIT MENU]\n";
		
		user_input = getNumber();

		switch (user_input) {
			case 1:
				
				add();
				break;
			case 2:
				
				search();
				break;
			case 3:
				
				update();
				break;
			case 4:
				
				confirmAndDelete();
				break;
			case 5:
				
				return;
				break;
			default:
				cout << "\nERROR: Please enter a number 1-5.\n";

				cin.clear();
				cin.ignore(INT_MAX, '\n');
				break;
		}
		
	}

}

void Product::add() {
	int counter(-1);
	char key(0);

	//this array contains the fields where the data will be stored in the database. 
	string fields[4] = { product_table::item_name, product_table::manufacturer_id, product_table::retail_price, product_table::low_stock_quantity };

	//this array holds the values that will go in the fields.  Do not change this code, as it is automated based on the fields[] array.
	string storedInMenu[4]{ "" };

	//change this array to alter the menus
	string menus[6] = { "Product Name", "Mfg ID", "Retail Price\t$", "Low Stock Qty.","Submit", "Query" };

	while (true)
	{
		bar_Title_Menu("ENTER PRODUCT DATA", "Use the arrow keys to navigate, or ESC/- to return to previous menu.");

		printMenuLine(menus[0], storedInMenu[0], MARGIN_1, MARGIN_2, positions[0] + MENU_FIELD_POS, Set[0]);
		printMenuLine(menus[1], storedInMenu[1], MARGIN_1, MARGIN_2, positions[1] + MENU_FIELD_POS, Set[1]);
		printMenuLine(menus[2], storedInMenu[2], MARGIN_1, MARGIN_2, positions[2] + MENU_FIELD_POS, Set[2]);
		printMenuLine(menus[3], storedInMenu[3], MARGIN_1, MARGIN_2, positions[3] + MENU_FIELD_POS, Set[3]);
		printMenuLine(menus[4], "", MARGIN_1, MARGIN_2, positions[4] + MENU_FIELD_POS, Set[4]);                //this is an action menu, does not store data
		printMenuLine(menus[5], "", MARGIN_1, MARGIN_2, positions[5] + MENU_FIELD_POS, Set[5]);               //this is an action menu, does not store data

		key = _getch(); //function used to get a character from the console, but it doesnt echo.

		if (key == '\b' || key == 45) { //ESC or - pressed.  Clear and break. 

			
			setColor(WHITE);
			break;
		}
		else if (key == 72)          //up key
			counter--;
		else if (key == 80 || key == 9)     //down key or Tab
			counter++;
		//else if (key == '\r' || key == 77)   //carriage return and right arrow key
		else if ((key >= 48 && key <= 122) || (key == '\r' || key == 77))   //carriage return and right arrow key
		{
			setColor(GREEN);

			if (counter == 0)
			{
				getMenuLine(storedInMenu[counter], MARGIN_2, positions[counter] + MENU_FIELD_POS);
				storedInMenu[counter] = checkInput(storedInMenu[counter], checkNames);
				counter++;
			}
			else if (counter == 1)
			{
				getMenuLine(storedInMenu[counter], MARGIN_2, positions[counter] + MENU_FIELD_POS);
				storedInMenu[counter] = checkInput(storedInMenu[counter], checkPartNumbers);
				counter++;
			}
			else if (counter == 2)
			{
				getMenuLine(storedInMenu[counter], MARGIN_2, positions[counter] + MENU_FIELD_POS);
				storedInMenu[counter] = checkInput(storedInMenu[counter], checkMoney);
				counter++;
			}
			else if (counter == 3)
			{
				getMenuLine(storedInMenu[counter], MARGIN_2, positions[counter] + MENU_FIELD_POS);
				storedInMenu[counter] = checkInput(storedInMenu[counter], checkMoney);
				counter++;
			}
			else if (counter == 4)
			{
				insertInto(table::products,
					buildFields(fields,
						sizeof(fields) / sizeof(string)),
					addQuotes(storedInMenu[0]) + addQuotes(storedInMenu[1]) + addComma(storedInMenu[2]) + storedInMenu[3]);
				counter++;
			}

			else if (counter == 5)
			{

				//build a sql statement using new dbConnect Functions
				this->dbSearch("select * from " + table::products + ";");
				counter++;
			}

		}

		//set all of the lines to white
		for (int i = 0; i < sizeof(Set) / sizeof(int) - 1; i++)
			Set[i] = WHITE;


		//dont change these two if statements, a weird glitch will happen.          
		if (counter < 0)
			counter = (sizeof(menus) / sizeof(string)) - 1;

		else if (counter >= (sizeof(menus) / sizeof(string)))
			counter = 0;

		//set the line in which the counter is pointing to a different color
		Set[counter] = RED;
	}


}

void Product::search() {
	string user_input = "";

	bar_Title_Menu();

	cout << "Enter a search term: ";
	cin >> user_input;
	string prepared_input = createSearchString("*", table::products, product_table::item_name, user_input);
	dbSearch(prepared_input);
	//displayMainMenu();
}

void Product::returnAll() {
	string all_products = "SELECT * FROM " + table::products + ";";
	dbSearch(all_products);
}

////////// Update Functions //////////

string Product::getProductID(string update_or_delete) {
	string user_input = "";

	bar_Title_Menu();

	cout << "\n\nEnter the ID # of the product to " + update_or_delete + ": ";
	cin >> user_input;
	return user_input;
}

string Product::getUpdateField() {
	int user_input = 0;

	string field_to_update;

	while (user_input < 1 || user_input > 8) {

			bar_Title_Menu();

		cout << "\n Select the field you want to update:\n";
		cout << "\t1. item_name\n";
		cout << "\t2. manufacturer_id\n";
		cout << "\t3. manufacturer_product_id\n";
		cout << "\t4. manufacturer_price\n";
		cout << "\t5. retail_price\n";
		cout << "\t6. department_id\n";
		cout << "\t7. low_stock_quantity\n";
		cout << "\t8. [EXIT MENU]\n";
		
		cin >> user_input;
	
		switch (user_input) {
			case 1:
				field_to_update = "item_name";
				break;
			case 2:
				field_to_update = "manufacturer_id";
				break;
			case 3:
				field_to_update = "manufacturer_product_id";
				break;
			case 4:
				field_to_update = "manufacturer_price";
				break;
			case 5:
				field_to_update = "retail_price";
				break;
			case 6:
				field_to_update = "department_id";
				break;
			case 7:
				field_to_update = "low_stock_quantity";
				break;
			case 8:

				cin.clear();
				cin.ignore(INT_MAX, '\n');

				return "";
				break;

			default:
				cout << "\nERROR: Please enter a number 1-8.\n";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				break;
		}
	}

	cin.clear();
	cin.ignore(INT_MAX, '\n');

	return field_to_update;
}

string Product::getNewValue() {
	string user_input = "";
	cout << "Enter a new value: ";
	getline(cin, user_input);
	return user_input;
}

void Product::update() {
	
	bar_Title_Menu();

	returnAll();
	string product_to_update = getProductID("update");
	string field_to_update = getUpdateField();
	string updated_value = getNewValue();
	if (field_to_update == "item_name" || field_to_update == "manufacturer_product_id") {
		updated_value = "'" + updated_value + "'";
	}
	string field_and_value = field_to_update + " = " + updated_value;
	string condition = product_table::product_id + " = " + product_to_update;
	string prepared_input = createUpdateString(table::products, field_and_value, condition);
	dbUpdate(prepared_input);
	Product::returnAll();

}

//////////////////////////////////////

bool Product::confirmPrompt() {
	string user_input = "";
	cout << "\nAre you sure you want to delete this item (y/n)? ";
	cin >> user_input;
	if (user_input != "y" && user_input != "Y") {
		return false;
	} else {
		return true;
	}
}

void Product::confirmAndDelete() {
	returnAll();
	string product_to_delete = getProductID("delete");
	string condition = product_table::product_id + " = " + product_to_delete;
	bool ruh_roh_raggy = confirmPrompt();
	if (ruh_roh_raggy) {
		string prepared_input = createDeleteString(table::products, condition);
		dbUpdate(prepared_input);
	} else {
		return;
	}
}


int Product::getNumber() {
	while (true) {
		try {

			cin.clear();

			int temp(0);
			cin >> temp;

			cin.ignore(INT_MAX, '\n');

			if (!cin.good()) throw logic_error("Invalid data");

			return temp;
		}
		catch (exception e) {

			cin.clear();
			cin.ignore(INT_MAX, '\n');

			string answer("");

			cout << "something went wrong: " << e.what() << endl;
			cout << "would you like to try again? y/n : ";
			getline(cin, answer);

			if (answer[0] == 'y') { continue; }
			else break;

		}
	}
	return 0;
};
