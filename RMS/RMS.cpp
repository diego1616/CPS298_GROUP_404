#include <iostream>
#include "DB_Connect.h"
#include "DB_Literals.h"
#include "Product.h"


//this function will prompt for a number, check it, clear the stream, then return the number. 
//if there is bad data, the user will be prompted again.  

int getNumber()
{
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
}



int main()
{
	//this created a connection to the database
	Product myProductAdder;

	//	DB_Connect::insertInto(table::products, "product_id,item_name,manufacturer_id","8765309,'barbie doll',37","");


	//const string product_id = "product_id";
	//const string item_name = "item_name";
	//const string manufacturer_id = "manufacturer_id";
	//const string manufacturer_product_id = "manufacturer_product_id";
	//const string manufacturer_price = "manufacturer_price";
	//const string retail_price = "retail_price";
	//const string department_id = "department_id";
	//const string low_stock_quantity = "low_stock_quantity";

//	"CREATE TABLE IF NOT EXISTS product_table ( \
//product_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, \
//item_name TEXT NOT NULL, \
//manufacturer_id INTEGER NOT NULL, \
//manufacturer_product_id	TEXT NOT NULL, \
//manufatcturer_price	REAL, \
//retail_price REAL, \
//department_id INTEGER, \
//low_stock_quantity INTEGER, \
//FOREIGN KEY (manufacturer_id) \
//REFERENCES manufacturer_table (manufacturer_id) \
//ON DELETE CASCADE \
//ON UPDATE NO ACTION, \
//FOREIGN KEY (department_id) \
//REFERENCES department_table (department_id) \
//ON DELETE CASCADE \
//ON UPDATE NO ACTION \
//); \n";

	// myProductAdder.insertInto(table::products, "item_name, manufacturer_id, manufacturer_product_id", "'Too Many Dolls',31,'TheCompanyCompany'");

	// string all = "*";
	// myProductAdder.queryFrom(table::products, all);

	// getline(cin, myString);

	// addquotes(myString);


	myProductAdder.someTestDanMade();
	system("pause");

	return 0;
}


