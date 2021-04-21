#include "Product.h"
#include "MainMenu.h"

void Product::displayMainMenu() {
	MainMenu m;
	int user_input = 0;

	while (user_input < 1 || user_input > 5) {
		cout << "\nSelect an option (1-4):\n";
		cout << "\t1. Add product\n";
		cout << "\t2. Search products\n";
		cout << "\t3. Update product info\n";
		cout << "\t4. Delete product\n";
		cout << "\t5. [EXIT MENU]\n";
		
		cin >> user_input;

		switch (user_input) {
			case 1:
				system("cls");
				add();
				break;
			case 2:
				system("cls");
				search();
				break;
			case 3:
				system("cls");
				update();
				break;
			case 4:
				system("cls");
				confirmAndDelete();
				break;
			case 5:
				system("cls");
				m.menu_options();
				break;
			default:
				cout << "\nERROR: Please enter a number 1-5.\n";
				cin.clear();
				//cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.ignore(INT_MAX, '\n');
				break;
		}
	}
}

void Product::add() {
    int counter(-1);
    char key(0);
   
    while (true)
    {
           
        //the first thing is go to clear the areas occupied by the menus.
        //Otherwise, you get some overlapping text when resizing windows, which can look very odd. 
        gotoxy(MARGIN_0, positions[0] + POS_OFFSET );
        clearLine((sizeof(menus) / sizeof(string) )*2);

        //Monitor the position of the counter and output the key that was pressed
        gotoxy(MARGIN_0, positions[0] + POS_OFFSET - 2);
        clearLine(2);
        gotoxy(MARGIN_0, positions[0] + POS_OFFSET - 2);
        cout << counter << endl << +key;


        printWhiteBar(MARGIN_0, POS_BAR);
      
        menuLine(title, instructions, MARGIN2, MARGIN2 +title.length() + 5, POS_TITLE, RED);

        menuLine(menus[0], storedInMenu[0], MARGIN1, MARGIN2, positions[0] + POS_OFFSET, Set[0]);
        menuLine(menus[1], storedInMenu[1], MARGIN1, MARGIN2, positions[1] + POS_OFFSET, Set[1]);
        menuLine(menus[2], storedInMenu[2], MARGIN1, MARGIN2, positions[2] + POS_OFFSET, Set[2]);
        menuLine(menus[3], storedInMenu[3], MARGIN1, MARGIN2, positions[3] + POS_OFFSET, Set[3]);
        menuLine(menus[4], "", MARGIN1, MARGIN2, positions[4] + POS_OFFSET, Set[4]);                //this is an action menu, does not store data
        menuLine(menus[5], "", MARGIN1, MARGIN2, positions[5] + POS_OFFSET, Set[5]);               //this is an action menu, does not store data
     
        //if we could find  way to detect any ey input, we could add some functionallyti and the program would become much more powerful.
        //for example, press F10 and do something else, or press q and go the the menu query.  etc. 
        //for now, we are stuckk using the _getch() function. 

        key = _getch(); //function used to get a character from the console, but it doesnt echo.

        if (key == 72)          //up key
            counter--;
        else if (key == 80)     //down key
            counter++;
        else if (key == '\r' || key == 77)   //carriage return and right arrow key
        {
            setColor(GREEN);
           
            if (counter == 0)
            {
                getMenuLine(storedInMenu[counter], MARGIN2, positions[counter] + POS_OFFSET);
                storedInMenu[counter] = checkInput(storedInMenu[counter],checkNames);
 
            }
			else if (counter == 1)
			{
				getMenuLine(storedInMenu[counter], MARGIN2, positions[counter] + POS_OFFSET);
                storedInMenu[counter] = checkInput(storedInMenu[counter], checkPartNumbers);

			}
            else if (counter == 2)
			{
				getMenuLine(storedInMenu[counter], MARGIN2, positions[counter] + POS_OFFSET);
                storedInMenu[counter] = checkInput(storedInMenu[counter],checkMoney);

            }
            else if (counter == 3)
            {
                getMenuLine(storedInMenu[counter], MARGIN2, positions[counter] + POS_OFFSET);
                storedInMenu[counter] = checkInput(storedInMenu[counter],checkMoney);
            }
            else if (counter == 4)
            {
                outputMsg("");
                insertInto(table::products,
                                    buildFields(fields,sizeof(fields)/sizeof(string)),
                                            addQuotes(storedInMenu[0]) + addQuotes(storedInMenu[1]) + addComma(storedInMenu[2]) + storedInMenu[3]);
            }
            
            else if (counter == 5)
            {
                gotoxy(MARGIN_0, positions[6] + POS_OFFSET);
                cout << clearLine(50);  //ideally, there would be a way to know how many results and clear up until then. For now I am guessing 50 lines. 
                gotoxy(MARGIN_0, positions[6] + POS_OFFSET);

                //build a sql statement using new dbConnect Functions
                this->dbSearch("select * from "+ table::products + ";");
                gotoxy(MARGIN_0, positions[6] + POS_OFFSET);
            }
             
        } else if (key == 27) {
        	system("cls");
        	displayMainMenu();
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
	cout << "Enter a search term: ";
	cin >> user_input;
	string prepared_input = createSearchString("*", table::products, product_table::item_name, user_input);
	dbSearch(prepared_input);
	displayMainMenu();
}

void Product::returnAll() {
	string all_products = "SELECT * FROM " + table::products + ";";
	dbSearch(all_products);
}

////////// Update Functions //////////

string Product::getProductID(string update_or_delete) {
	string user_input = "";
	cout << "\n\nEnter the ID # of the product to " + update_or_delete + ": ";
	cin >> user_input;
	return user_input;
}

string Product::getUpdateField() {
	int user_input = 0;

	string field_to_update;

	while (user_input < 1 || user_input > 8) {
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
				displayMainMenu();
				break;
			default:
				cout << "\nERROR: Please enter a number 1-8.\n";
				cin.clear();
				//cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.ignore(INT_MAX, '\n');
				break;
		}
	}

	return field_to_update;
}

string Product::getNewValue() {
	string user_input = "";
	cout << "Enter a new value: ";
	cin >> user_input;
	return user_input;
}

void Product::update() {
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
	displayMainMenu();
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
		displayMainMenu();
	}
}