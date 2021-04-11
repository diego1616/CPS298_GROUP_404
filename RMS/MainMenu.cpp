#include <string>
#include <iostream>
#include "MainMenu.h"
#include "User.h"
#include "AddProduct.h"


void MainMenu::print_main_menu() {

    //this is used to create a main menu.

    cout << "1.  Products" << endl;
    cout << "2.  Users" << endl;
    cout << "3.  Manufacturers" << endl;
    cout << "4.  Store information" << endl;
    cout << "5.  Logout" << endl;





};

void MainMenu::menu_options() {

    //this is used to pick what to do

    int number_Option = 0;

    do {

        AddProduct ap;
        User u;

        cout << "What would you like to work with?" << endl;

        this->print_main_menu();

        do {

            cout << "Please choose the number option: ";

            number_Option = getNumber();

            cout << endl;

            if ((number_Option != 1) && (number_Option != 2) && (number_Option != 3) && (number_Option != 4) && (number_Option != 5))
            {
                cout << "That is not an option.  Please try again." << endl;
            }



        } while ((number_Option != 1) && (number_Option != 2) && (number_Option != 3) && (number_Option != 4) && (number_Option != 5));



        switch (number_Option) {
        case 1:
            ap.viewingEnviroment();
            break;
        case 2:
            u.change_User_Information();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        };

    } while (number_Option != 5);
  
};

int MainMenu::getNumber() {
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
