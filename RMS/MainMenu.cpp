#include <string>
#include <iostream>
#include "MainMenu.h"
#include "C:\CPS298_GROUP_404\CPS298_GROUP_404\RMS\User.h"
#include "C:\CPS298_GROUP_404\CPS298_GROUP_404\RMS\AddProduct.h"


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

            number_Option = getline();

            cout << endl;

            if ((number_Option != 1) && (number_Option != 2) && (number_Option != 3) && (number_Option != 4) && (number_Option != 5))
            {
                cout << "That is not an option.  Please try again." << endl;
            }



        } while ((number_Option != 1) && (number_Option != 2) && (number_Option != 3) && (number_Option != 4) && (number_Option != 5));



        switch (number_Option) {
        case 1:

            break;
        case 2:
 

            u.print_Menu();

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

