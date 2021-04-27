#include <string>
#include <iostream>
#include "MainMenu.h"
#include "User.h"
#include "AddProduct.h"
#include "Manufacturer.h"
#include "Store.h"


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

    //Katie, this code is just fine, but I had to move it.  This is because creating the object stablished a connection to database.  too many connections basically. 
    // My fix was to move each and single one to the switch statement.
    //AddProduct ap;
    //Product ap;
    //User u;
    //Manufacturer m;
    //Store s;

    string title = "What would you like to work with?";
    string instructions = "";

    do {

 
        //this line gets replaced by the printMEnuLine()
        //cout << "What would you like to work with?" << endl;

        //********************* Line used to ensure display is right.  To use, each class must inherit from Menu.h *****************************

        //this function takes up to two functional arguments.  if you want to print a title, just pass a string, or two.  
        bar_Title_Menu();

        //**************************************************************************************************************************************

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
        {
            //system("cls");
            //ap.viewingEnviroment();
            Product ap;
            ap.displayMainMenu();
        }
            break;
        case 2:
        {
            int int_user_id;

            //system("cls");
            //int_user_id = u.get_User_ID();
            //u.change_User_Information(); Katie, I commented this line out, because I think you mean user_Menu();  if it is not the case, change it back please. 
            User u;
            u.user_Menu();
        }
            break;
        case 3:
        {
            //system("cls");
            Manufacturer m;
            m.main_choice();
        }
            break;
        case 4:
        {
            //system("cls");
            Store s;
            s.store_Choice();
        }
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
