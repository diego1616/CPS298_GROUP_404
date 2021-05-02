#include "AddProduct.h"


void AddProduct::viewingEnviroment()
{
	
    int counter(-1);
    char key(0);
    string title = "ENTER PRODUCT DATA";
    string instructions = "Use the arrow keys to navigate. Press ESC or - to return to previous menu.";
   
    while (true)
    {

        //Monitor the position of the counter and output the key that was pressed
        //setColor(BLUE);
        //gotoxy(MARGIN_0, positions[0] + POS_OFFSET - 2);
        //clearLine(2);
        //gotoxy(MARGIN_0, positions[0] + POS_OFFSET - 2);
        //cout << counter << endl << +key;

        prepField(BAR_FIELD_POS - 3 , 2);
        setColor(BLUE);
        cout << counter << endl << +key;

        printWhiteBar(BAR_FIELD_POS);
     
        //printing the title
        printMenuLine(title, instructions, MARGIN_2, MARGIN_2 + (int)title.length() + 5, TITLE_FIELD_POS, RED);

        //the first thing is go to clear the areas occupied by the menus.
         //Otherwise, you get some overlapping text when resizing windows, which can look very odd. 
         //gotoxy(MARGIN_0, positions[0] + POS_OFFSET );
         //clearLine((sizeof(menus) / sizeof(string) )*2);

        //even if the printMenuLine clears each line, somethings there are resizing erros, so it is best to clear the menu field.
        prepField(MENU_FIELD_POS, MENU_FIELD);

        printMenuLine(menus[0], storedInMenu[0], MARGIN_1, MARGIN_2, positions[0] + MENU_FIELD_POS, Set[0]);
        printMenuLine(menus[1], storedInMenu[1], MARGIN_1, MARGIN_2, positions[1] + MENU_FIELD_POS, Set[1]);
        printMenuLine(menus[2], storedInMenu[2], MARGIN_1, MARGIN_2, positions[2] + MENU_FIELD_POS, Set[2]);
        printMenuLine(menus[3], storedInMenu[3], MARGIN_1, MARGIN_2, positions[3] + MENU_FIELD_POS, Set[3]);
        printMenuLine(menus[4], "", MARGIN_1, MARGIN_2, positions[4] + MENU_FIELD_POS, Set[4]);                //this is an action menu, does not store data
        printMenuLine(menus[5], "", MARGIN_1, MARGIN_2, positions[5] + MENU_FIELD_POS, Set[5]);               //this is an action menu, does not store data
     
        //if we could find  way to detect any ey input, we could add some functionallyti and the program would become much more powerful.
        //for example, press F10 and do something else, or press q and go the the menu query.  etc. 
        //for now, we are stuckk using the _getch() function. 

        key = _getch(); //function used to get a character from the console, but it doesnt echo.
        
        if (key == '\b' || key == 45) { //ESC or - pressed.  Clear and break. 
            
            system("cls");
            setColor(WHITE);
            break;
        }
        else if (key == 72)          //up key
            counter--;
        else if (key == 80)     //down key
            counter++;
        else if (key == '\r' || key == 77)   //carriage return and right arrow key
        {
            setColor(GREEN);
           
            if (counter == 0)
            {
                getMenuLine(storedInMenu[counter], MARGIN_2, positions[counter] + MENU_FIELD_POS);
                storedInMenu[counter] = checkInput(storedInMenu[counter],checkNames);
 
            }
			else if (counter == 1)
			{
                getMenuLine(storedInMenu[counter], MARGIN_2, positions[counter] + MENU_FIELD_POS);
                storedInMenu[counter] = checkInput(storedInMenu[counter], checkPartNumbers);

			}
            else if (counter == 2)
			{
                getMenuLine(storedInMenu[counter], MARGIN_2, positions[counter] + MENU_FIELD_POS);
                storedInMenu[counter] = checkInput(storedInMenu[counter],checkMoney);

            }
            else if (counter == 3)
            {
                getMenuLine(storedInMenu[counter], MARGIN_2, positions[counter] + MENU_FIELD_POS);
                storedInMenu[counter] = checkInput(storedInMenu[counter],checkMoney);
            }
            else if (counter == 4)
            {
                //outputMsg("");

                insertInto(table::products,
                                    buildFields(fields,
                                        sizeof(fields)/sizeof(string)),
                                            addQuotes(storedInMenu[0]) + addQuotes(storedInMenu[1]) + addComma(storedInMenu[2]) + storedInMenu[3]);
            }
            
            else if (counter == 5)
            {
                //gotoxy(MARGIN_0, positions[6] + POS_OFFSET);
                //clearLine(50);  //ideally, there would be a way to know how many results and clear up until then. For now I am guessing 50 lines. 
                //gotoxy(MARGIN_0, positions[6] + POS_OFFSET);

                //ideally, there would be a way to know how many results and clear up until then. For now I am guessing 60 lines. 
                prepField(QUERY_FIELD_POS, 60);

                //build a sql statement using new dbConnect Functions
                this->dbSearch("select * from "+ table::products + ";");
                gotoxy(MARGIN_0, QUERY_FIELD_POS);
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
