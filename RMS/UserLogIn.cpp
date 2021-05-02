#include "UserLogIn.h"


void UserLogIn::allowAccess()
{ //routine to allow access.  this function should create an MainMenu Object, which would display different options based on its access level. 

	EventLog log;

	try {

		if (DB_Connect::setAcess(stoi(this->userAccessLevel), this->who)) {
			
			this->menu_options();
			
			clearUser();	//once it leaves the Menu_Options() loop, it will clear the user, and the data stored in the menus.
		}
		else
			clearUser();

	}
	catch (exception e)
	{
		//if you got to this point, its because everything was looking ok, but the user access level variable
		//in the DB is corrupted, causing this problem.  the function stoi() is prone to throwing exceptions. 
		//Becuse of that, I must use the try and catch blocks. 

		DB_Connect::setAcess(0, USER_LOG_EMPTY);
	}

}
UserLogIn::UserLogIn()
{
	this->clearUser(); //set all the values to initial before getting data
	this->getData();
	this->clearUser();	//the program should never exit the getData loop, but if it does, clear the user. 

}

void UserLogIn::dbSearch(string sql, string& data) {

	sqlite3_stmt* sql_statement;
	bool check = true;

	EventLog log(sql);
	int statement_length = (int)strlen(sql.c_str());

	int prep = sqlite3_prepare_v2(sqLiteDB, sql.c_str(), statement_length, &sql_statement, NULL);
	int step = 0; // new int(0)

	if (prep == SQLITE_OK) {

		step = sqlite3_step(sql_statement);

		if (step == SQLITE_ROW)
		{
			char* col_val = (char*)sqlite3_column_text(sql_statement, 0);

			if (sqlite3_column_type(sql_statement, 0) != SQLITE_NULL) { // NB: NULL cell values will break the function prematurely; those are handled below
				data = col_val;
				//log.logEvent(" The following data was found by UserLogIn::dbSearch() = " + data );
			}
			else {	//something was found, but it was NULL

				data = NULL_FIND;
				//log.logEvent(" The following data was found by UserLogIn::dbSearch() = " + data);
			}
		}
		else if (step == SQLITE_DONE) {	//this means nothing was found.  Nothing wrong with the query, just nothing found.
			data = NOT_FOUND;
			//log.logEvent(" The following data was found by UserLogIn::dbSearch() = " + data);
		}

	}
	else {
		const char* error_message = sqlite3_errmsg(this->sqLiteDB);
		log.logEvent(error_message);
	}
	sqlite3_finalize(sql_statement);

}

void UserLogIn::getData()
{
	string title = "Inventory Management System Log In Page. ";
	string instructions = "Please enter your credentials";

	int counter(-1);
	char key(0);

	//this array contains the fields where the data will be stored in the database. 
	string fields[3] = { user_table::user_id, user_table::f_name, user_table::password };

	//change this array to alter the menus
	string menus[3] = { "USER ID", "PASSWORD", "SUBMIT" };


	while (true)
	{
		//prepField(BAR_FIELD_POS - 3, 2);
		//setColor(BLUE);
		//cout << counter << endl << +key;

		printWhiteBar(BAR_FIELD_POS);

		//printing the title
		printMenuLine(title, instructions, MARGIN_2, MARGIN_2 + (int)title.length() + 5, TITLE_FIELD_POS, RED);

		//even if the printMenuLine clears each line, somethings there are resizing erros, so it is best to clear the menu field.
		prepField(MENU_FIELD_POS, MENU_FIELD);

		printMenuLine(menus[0], storedInMenu[0], MARGIN_1, MARGIN_2, positions[0] + MENU_FIELD_POS, Set[0]);
		printMenuLine(menus[1], "", MARGIN_1, MARGIN_2, positions[1] + MENU_FIELD_POS, Set[1]);
		printMenuLine(menus[2], "", MARGIN_1, MARGIN_2, positions[2] + MENU_FIELD_POS, Set[2]);                //this is an action menu, does not store data

		//if we could find  way to detect any key input, we could add some functionality and the program could become much more powerful.
		//for example, press F10 and do something else, or press q and go the the menu query.  etc. 
		//for now, we are stuck using the _getch() function. 

		key = _getch(); //function used to get a character from the console, but it doesnt echo.

		if (key == 72)          //up key
			counter--;
		else if (key == 80 || key == 9)     //down key or Tab
			counter++;
		//else if (key == '\r' || key == 77)   //carriage return and right arrow key
		else if ((key >= 48 && key <= 122) || (key == '\r' || key == 77))   //carriage return and right arrow key
		{
			setColor(GREEN);

			if (counter == 0)
			{
				getMenuLine(storedInMenu[counter], MARGIN_2, positions[counter] + MENU_FIELD_POS);
				storedInMenu[counter] = checkInput(storedInMenu[counter], noCheck);
				counter++;

			}
			else if (counter == 1)
			{
				getMenuLine(storedInMenu[counter], MARGIN_2, positions[counter] + MENU_FIELD_POS);
				storedInMenu[counter] = checkInput(storedInMenu[counter], noCheck);
				counter++;
			}
			else if (counter == 2)
			{
				if (validateData())
				{
					allowAccess();
				}
				else {

					EventLog log(USER_LOG_BAD(storedInMenu[0]));
				}
				counter++;
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

bool UserLogIn::validateData()
{
	EventLog log;

	//used to search through user_table and find accessLevel 
	string credentials_search = "SELECT " + user_table::permissions_level + " FROM " + table::users +
												" WHERE " + user_table::user_id + "=" + storedInMenu[0] + " AND " +
														user_table::password + "=" + addQuotes(storedInMenu[1], false) + " LIMIT 1;";

	//sql to find user's first name
	string name_search = "SELECT " + user_table::f_name + " FROM " + table::users + " WHERE " + user_table::user_id + " = " + storedInMenu[0] + " LIMIT 1;";

	UserLogIn::dbSearch(credentials_search, this->userAccessLevel);


	if (this->userAccessLevel == NOT_FOUND || this->userAccessLevel == NULL_FIND || this->userAccessLevel == USER_LOG_EMPTY) {

		return false;
	}
	else {

		//get user name
		UserLogIn::dbSearch(name_search, this->who);

		return true;
	}
}

void UserLogIn::clearUser()
{
	who = USER_LOG_EMPTY;
	userAccessLevel = USER_LOG_EMPTY;
	DB_Connect::setAcess(0, USER_LOG_EMPTY);

	for (int i = 0; i < sizeof(storedInMenu) / sizeof(string); i++)
	{
		storedInMenu[i] = "";
	}
}
