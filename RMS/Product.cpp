#include "Product.h"
#include "DB_Connect.h"

void Product::displayMainMenu() {
	int user_input = 0;
	while (user_input != 1 && user_input != 2 && user_input != 3  && user_input != 4) {
		cout << "Select an option (1-4):\n";
		cout << "\t1. Add product\n";
		cout << "\t2. Search products\n";
		cout << "\t3. Update product info\n";
		cout << "\t4. Delete product\n";
		
		cin >> user_input;

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
			default:
				cout << "\nERROR: Please enter a number 1-4.\n";
				break;
		}
	}
}

void Product::add() {
		cout << "Made it to add!" << endl;
}

void Product::search() {
		string user_input = "";
		cout << "Enter a search term: ";
		cin >> user_input;
		DB_Connect::dbSearch(user_input);
}

void Product::update() {
		cout << "Made it to update!" << endl;
}

void Product::confirmAndDelete() {
		cout << "Made it to delete!" << endl;
}