#include <iostream>
#include "DB_Connect.h"
#include "DB_Literals.h"
#include "AddProduct.h"

//#define WIN32_LEAN_AND_MEAN     //the header windows.h defines a lot of data types, which causes conflict. This line fixes that. 
//#include <windows.h>
//#include <conio.h>	//bad word here.......NSFW.  Give me a safe word. 
//#include <string>
//#include <functional> //allows passing functions as arguments

using namespace std;

//enum colors { WHITE = 7, BLUE = 9, GREEN = 10, RED = 12 };


int main()
{
	//keep this line so everything displays right. 
	system("mode 1000");

	AddProduct obj;
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


	obj.viewingEnviroment();
	
	return 0;
}

//
//void gotoxy(int x, int y)
//{
//    COORD c;
//    c.X = x;
//    c.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
//}
//
//void setColor(int color)
//{
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}
//
////this function will prompt for a number, check it, clear the stream, then return the number. 
////if there is bad data, the user will be prompted again.  
////this function should not be needed in our application, but we'll see!
//int getNumber()
//{
//    while (true) {
//        try {
//
//            cin.clear();
//
//            int temp(0);
//            cin >> temp;
//
//            cin.ignore(INT_MAX, '\n');
//
//            if (!cin.good()) throw logic_error("Invalid data");
//
//            return temp;
//        }
//        catch (exception e) {
//
//            cin.clear();
//            cin.ignore(INT_MAX, '\n');
//
//            string answer("");
//
//            cout << "something went wrong: " << e.what() << endl;
//            cout << "would you like to try again? y/n : ";
//            getline(cin, answer);
//
//            if (answer[0] == 'y') { continue; }
//            else break;
//
//        }
//    }
//    return 0;
//}
//
//string addComma(string data) {
//
//    data += ",";
//
//    return data;
//}
//
//string addQuotes(string data, bool comma = true) {
//
//    data = "'" + data + "'";
//
//    if (comma == true)
//        data = addComma(data);
//
//    return data;
//}
//
//string removeChars(string str,string chars=" ") {
//
//    int index(0);
//    
//    cout << "removeChars() input string: " << '\"' + str + '\"' << endl;
//	while (index >= 0)
//	{	
//        index = (int)str.find_first_of(chars);
//        
//        if(chars.length() > 0 && index >= 0)
//            str.erase(index, 1);
//	}
//    cout << "removeChars() output string: " << '\"'+ str +'\"' << endl;
//    return str;
//}
//
//bool onlyNumbers(string str) {
//    //returns true if the string only contains numbers. 
//    
//    //cout << "onlyNumbers() input string: " << str << endl;
//    for (int i = 0; i < str.length(); i++)
//    {
//        if (str[i] < 48 || str[i]>57)
//        {
//            //cout << "something besides a number was detected: " << str[i] << endl;
//            return false;
//        }
//    }
//
//    return true;
//}
//
//string onlyLetters(string str, string allowThese = " ") {
//    //return true if the string only contains letters.  
//    //It allows spaces by default, unless a second argument is passed. 
//
//    string tempStr = str;
//   
//    //cout << "onlyLetter() - input string : " << '\'' + str + '\'' << endl;
//    
//    tempStr = removeChars(tempStr,allowThese);
//    
//    //cout << "nonlyLetter() - string after allowed characters removed : " + '\'' + str + '\'' << endl;
//
//    char temp;
//    for (int i = 0; i < tempStr.length(); i++)
//    {
//        //check all un upper case form to avoid too much code
//        temp = toupper(str[i]);
//
//        if (temp < 65 || temp > 90) {
//            //out << "onlyLetters() - bad character detected at: " <<  temp  << endl;
//            return "invalid data";
//        }
//    }
//
//    return str;
//
//}
//
////use this function to conver a double/float like string to int.  Money should always be store in int to avoid rounding
//string dollarToCents(string dollars) {
//    
//    int first_occurance(-1), second_occurance(-1);
//
//    first_occurance = (int)dollars.find_first_of(".");
//    second_occurance = (int)dollars.rfind(".");
//
//    //remove everything behind two characters past the dot.
//    if (first_occurance == second_occurance) {
//        dollars.resize(first_occurance + 3);
//        dollars.erase(first_occurance, 1);
//    }
//    
//    //check the remaining string for anything but a number. 
//    if(onlyNumbers(dollars))
//        return dollars;
//    else return "invalid data";
//}
//
//string clearLine(int howManyLines = 1) {
//
//    string temp("");
//    int lineWidth = 180;
//
//    for (int i = 0; i < lineWidth; i++)
//        temp += " ";
//
//    for (int i = 0; i < howManyLines; i++)
//        cout << temp << endl;
//
//    return temp;
//
//}
//
//void menuLine(string& menuText, string storedInput, int margin, int margin2, int position, int color) {
//    gotoxy(margin, position);
//    setColor(color);
//    cout << menuText;
//    gotoxy(margin2, position);
//    cout << storedInput;
//}
//
////the third parameter is a pointer to a function to check the data is correct before accepting it.
//void getMenuLine(string &data, int margin, int position, function<string (string)> validateData) {
//
//    gotoxy(margin,position);
//    clearLine(1);
//    gotoxy(margin, position);
//    getline(cin, data);
//    data = validateData(data);
//    gotoxy(margin, position);
//    cout << data;
//}
//
//void getMenuLine(string& data, int margin, int position) {
//
//    gotoxy(margin, position);
//    clearLine(1);
//    gotoxy(margin, position);
//    getline(cin, data);
//    gotoxy(margin, position);
//    cout << data;
//}
//
//string buildFields(string fields[], int size) {
////add a comma at the end of each field, but it does not do it to the final field.
//
//    string sqFields("");
//
//    for (int i = 0; i < size; i++)
//    {
//        if (i < size - 1)
//            sqFields += addComma(fields[i]);
//        if(i==size -1)
//            sqFields += fields[i];
//    }
//
//    return sqFields;
//}
//
//string buildData(string data[], int size) {
//    //adds a quotes AND commas at the end of each field, but it does not do it to the final field.
//
//    string sqFields("");
//
//    for (int i = 0; i < size; i++)
//    {
//        if (i < size - 1)
//            sqFields += addQuotes(data[i]);
//        if (i == size - 1)
//            sqFields += addQuotes(data[i],false);   //false means dont add the comma
//    }
//
//    return sqFields;
//
//}
//
//#define MARGIN_0 0
//#define MARGIN1 5
//#define MARGIN2 MARGIN1 + 20
//#define POS_OFFSET 5
//#define POS_MESSAGES 0
//#define POS_QUERY POS_OFFSET + 20

//int main()
//{
//    int Set[] = { WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE,WHITE }; // DEFAULT COLORS
//    int counter(-1);
//    char key(0);
//
//    //this set of strings is not longer used. replace by array storedInMenu
//    string productID(""), productName(""), MFG_ID(""), MFG_PN(""), price("");
//    
//    /*string dollars("1.23456"), cents(""), letterCheck1("this is just a test"), letterCheck2("this test should+ fail");
//    cents = dollarToCents(dollars);
//    
//    system("@timeout 1");
//    cout << dollars + " dollars converted to cents is " + cents << endl;
//
//    cout << boolalpha;
//    system("@timeout 1");
//    cout << "Letter characters test: " + letterCheck1 + " \tresult= " << endl << onlyLetters(letterCheck1) << endl;
//    system("@timeout 1");
//    cout << "Letter characters test2: " + letterCheck2 + " \tresult= " << endl << onlyLetters(letterCheck2) << endl;
//
//    cout << endl << endl << endl;
//
//    system("timeout 3");*/
//   
//    //most keep this command, so that the window is properly sizes. Otherwise the line count may change and menus will look bad. 
//    //Update, I may have found a way around this issue. 
//    system("mode 1000");
//
//    AddProduct myProductAdder;
//      
//    //change this array to alter the menus
//    string menus[] = { "Product ID" , "Product Name", "Mfg ID", "Mfg Part Number", "Retail Price\t$", "Submmit", "Query" };
//
//    //this array contains the fields where the data will be stored in the database. 
//    string fields[] = { product_table::product_id, product_table::item_name, product_table::manufacturer_id, product_table::manufacturer_product_id, product_table::retail_price };
//
//    //this array holds the values that will go in the fields.  Do not change this code, as it is automated based on the fields[] array.
//    string storedInMenu[sizeof(fields) / sizeof(string)]  { "" };
//
//    //this is the menus line position.
//    int positions[] = { 5, 7, 9, 11, 13, 15, 17, 19, 21 }, position_offset = 5;
//
//    while (true)
//    {
//        //the first thing is go to clear the areas occupied by the menus.
//        //Otherwise, you get some overlapping text when resizing windows, which can look very odd. 
//        gotoxy(MARGIN_0, positions[0] + position_offset - 2 );
//        clearLine(17);
//
//        //Monitor the position of the counter and output the key that was pressed
//        gotoxy(MARGIN_0, positions[0] + position_offset - 2);
//        cout << counter << endl << +key;
//
////*****************************************Third version, does not work, so went back to version 2 *******************************************
//
//        /*for (int i = 0 ; i < sizeof(menus)/sizeof(string); i++)
//        {
//            menuLine(menus[i], storedInMenu[i], MARGIN1, MARGIN2, positions[i] , Set[0]);
//        }*/
//
//
////*****************************************Second version of the menus, best solution so far ************************************
//
//        menuLine(menus[0], storedInMenu[0], MARGIN1, MARGIN2, positions[0] + position_offset, Set[0]);
//        menuLine(menus[1], storedInMenu[1], MARGIN1, MARGIN2, positions[1] + position_offset, Set[1]);
//        menuLine(menus[2], storedInMenu[2], MARGIN1, MARGIN2, positions[2] + position_offset, Set[2]);
//        menuLine(menus[3], storedInMenu[3], MARGIN1, MARGIN2, positions[3] + position_offset, Set[3]);
//        menuLine(menus[4], storedInMenu[4], MARGIN1, MARGIN2, positions[4] + position_offset, Set[4]);
//        menuLine(menus[5], "", MARGIN1, MARGIN2, positions[5] + position_offset, Set[5]);               //this is an action menu, does not store data
//        menuLine(menus[6], "", MARGIN1, MARGIN2, positions[6] + position_offset, Set[6]);               //this is an action menu, does not store data
//
//
////****************************************First version of the menus, it works but the code is rather long, and it has display glitches ***********************************
//       /* gotoxy(MARGIN1, POS1);
//        setColor(Set[0]);
//        cout << "Product ID"; 
//
//        gotoxy(MARGIN1, POS2);
//        setColor(Set[1]);
//        cout << "Product Name";
//
//        gotoxy(MARGIN1, POS3);
//        setColor(Set[2]);
//        cout << "Mfg ID";
//
//        gotoxy(MARGIN1, POS4);
//        setColor(Set[3]);
//        cout << "Mfg Part Number";
//
//        gotoxy(MARGIN1, POS5);
//        setColor(Set[4]);
//        cout << "Retail Price\t$"; 
//
//        gotoxy(MARGIN1, POS6);
//        setColor(Set[5]);
//        cout << "Submmit";
//
//        gotoxy(MARGIN1, POS7);
//        setColor(Set[6]);
//        cout << "Query";*/
//
//
//        //if we could find  way to detect any ey input, we could add some functionallyti and the program would become much more powerful.
//        //for example, press F10 and do something else, or press q and go the the menu query.  etc. 
//        //for now, we are stuckk using the _getch() function. 
//
//        key = _getch(); //function used to get a character from the console, but it doesnt echo.
//
//        //if (key == 72 && (counter > 0 && counter <= sizeof(menus) / sizeof(string)))
//        //{
//        //    counter--;
//        //}
//        //if (key == 80 && (counter >= 0 && counter  < sizeof(menus) / sizeof(string)))
//        //{
//        //    counter++;
//        //}
//
//
//        if (key == 72)          //up key
//            counter--;
//        else if (key == 80)     //down key
//            counter++;
//        else if (key == '\r')   //carriage return
//        {
//            setColor(GREEN);
//
//            if (counter == 0)
//            {
//                // if enter is click and highlight is on 1 the program will run the code here
//                
//                getMenuLine(storedInMenu[counter], MARGIN2, positions[counter] + position_offset);
//
////*******************************************This was a test before creating the getMenuLine function,  It works but the code is too lenghty.  It corrects some display glitches
//                //gotoxy(MARGIN2, POS1);
//                //clearLine(1);
//                //gotoxy(MARGIN2, POS1);
//                //std::getline(cin, productID);
//                //gotoxy(MARGIN2, POS1);
//                //cout << productID;
//            }
//			if (counter == 1)
//			{
//				getMenuLine(storedInMenu[counter], MARGIN2, positions[counter] + position_offset);
//
//				/*             gotoxy(MARGIN2, POS2);
//							 std::getline(cin, productName);*/
//			}
//			if (counter == 2)
//			{
//				getMenuLine(storedInMenu[counter], MARGIN2, positions[counter] + position_offset);
//				//gotoxy(MARGIN2, POS3);
//				//std::getline(cin, MFG_ID);
//            }
//            if (counter == 3)
//            {
//                getMenuLine(storedInMenu[counter], MARGIN2, positions[counter] + position_offset);
//                //gotoxy(MARGIN2, POS4);
//                //std::getline(cin, MFG_PN);
//            }
//            if (counter == 4)
//            {
//                getMenuLine(storedInMenu[counter], MARGIN2, positions[counter] + position_offset);
//                //gotoxy(MARGIN2, POS5);
//                //std::getline(cin, price);
//            }
//
//            if (counter == 5)
//            {
//                gotoxy(MARGIN_0, POS_MESSAGES);
//                clearLine(5);
//                gotoxy(MARGIN_0, POS_MESSAGES);
//
//				myProductAdder.insertInto(table::products,
//					addComma(product_table::product_id) + addComma(product_table::item_name) + addComma(product_table::manufacturer_id) + addComma(product_table::manufacturer_product_id) + product_table::retail_price,
//					    addQuotes(storedInMenu[0]) + addQuotes(storedInMenu[1]) + addQuotes(storedInMenu[2]) + addQuotes(storedInMenu[3]) + storedInMenu[4]);
//
//
//            }
//
//            if (counter == 6)
//            {
//                gotoxy(MARGIN_0, POS_QUERY);
//                cout << clearLine(50);  //ideally, there would be a way to know how many results and clear up until then. For now I am guessing 50 lines. 
//                gotoxy(MARGIN_0, POS_QUERY);
//                myProductAdder.someTestDanMade();
//                gotoxy(MARGIN_0, POS_QUERY);
//
//            }
//             
//        }
//
//        //set all of the lines to white
//        for (int i = 0; i < sizeof(Set) / sizeof(int) - 1; i++)
//            Set[i] = WHITE;
//
//   /*     Set[0] = 7;
//        Set[1] = 7;
//        Set[2] = 7;
//        Set[3] = 7;
//        Set[4] = 7;
//        Set[5] = 7;
//        Set[6] = 7;*/
//
//    //dont change these two if statements, a weird glitch will happen.          
//        if (counter < 0)
//            counter = (sizeof(menus) / sizeof(string)) - 1;
//
//        else if (counter >= (sizeof(menus) / sizeof(string)))
//            counter = 0;
//
//        //set the line in which the counter is pointing to a different color
//        Set[counter] = RED;
//
//  /*     if (counter == 1)
//        {
//            Set[0] = 12;
//        }
//        if (counter == 2)
//        {
//            Set[1] = 12;
//        }
//        if (counter == 3)
//        {
//            Set[2] = 12;
//        }
//        if (counter == 4)
//        {
//            Set[3] = 12;
//        }
//        if (counter == 5)
//        {
//            Set[4] = 12;
//        }
//        if (counter == 6)
//        {
//            Set[5] = 12;
//        }
//        if (counter == 7)
//        {
//            Set[6] = 12;
//        }*/
//
//
//
//
//    }
//}

