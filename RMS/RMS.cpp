#include <iostream>
#include "DB_Connect.h"
#include "DB_Literals.h"


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

	//Katie, first I will show you the problem we want to avoid.  The reason to go through so many hoops.

	//cin causes all kinds of trouble on its own, so I made a function to help.  It will also check for letters and bad data in general. 

	while (true) {

		int number1(0), number2(0);

		cout << "please enter the first number" << endl;
		
		number1 = getNumber();

		cout << "please enter the second number" << endl;

		number2 = getNumber();

		cout << "your numbers are " << number1 << " and " << number2 << endl;

		cout << "Thank you for playing!!\n" << endl;

	}

	DB_Connect dataBase;

	//printing the table names
	dataBase.getTables();
	
	


	return 0;
}


