#include "AddProduct.h"


void AddProduct::viewingEnviroment()
{
	
    int counter(-1);
    char key(0);
   
    while (true)
    {
           
        //the first thing is go to clear the areas occupied by the menus.
        //Otherwise, you get some overlapping text when resizing windows, which can look very odd. 
        gotoxy(MARGIN_0, positions[0] + POS_OFFSET );
        clearLine((sizeof(menus) / sizeof(string) )*2);

        //Monitor the position of the counter and output the key that was pressed
        setColor(BLUE);
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

                //The following three lines are replaced by outoutMsg();
                //gotoxy(MARGIN_0, POS_MESSAGES);
                //clearLine(positions[0] + POS_OFFSET);
                //gotoxy(MARGIN_0, POS_MESSAGES);

                //Some test
                //insertInto(table::products,
                //    addComma(product_table::item_name) + addComma(product_table::manufacturer_id) + addComma(product_table::retail_price) + product_table::low_stock_quantity,
                //            addQuotes(storedInMenu[0]) + addQuotes(storedInMenu[1]) + addComma(storedInMenu[2]) + storedInMenu[3]);

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
