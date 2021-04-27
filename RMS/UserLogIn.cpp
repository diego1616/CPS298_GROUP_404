#include "UserLogIn.h"


void UserLogIn::allowAccess()
{ //routine to allow access.  this function should create an MainMenu Object, which would display different options based on its access level. 
}
UserLogIn::UserLogIn()
{
	this->getData();
	this->validateData();
}

void UserLogIn::dbSearch(string sql, string& data) {

	sqlite3_stmt* sql_statement;
	bool check = true;

	EventLog log(sql);
	size_t statement_length = strlen(sql.c_str());

	int prep = sqlite3_prepare_v2(sqLiteDB, sql.c_str(), statement_length, &sql_statement, NULL);
	int step = 0; // new int(0)

	if (prep == SQLITE_OK) {

		log.logEvent("SQLITE_OK is ok, so it is 0 = " + to_string(SQLITE_OK));

		while (step != SQLITE_DONE)
		{
			step = sqlite3_step(sql_statement);

			if (step == SQLITE_ROW)
			{
				char* col_val = (char*)sqlite3_column_text(sql_statement, 0);

				if (sqlite3_column_type(sql_statement, 0) == SQLITE_NULL) // NB: NULL cell values will break the function prematurely; those are handled below
					data = col_val;
				else
					data = NULL_FIND;
			}
			else
			{
				//this means nothing was found.  Nothing wrong with the query, just nothing found.
				data = NOT_FOUND;
			}


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

	//this array holds the values that will go in the fields.  Do not change this code, as it is automated based on the fields[] array.
	string storedInMenu[2]{ "" };

	//change this array to alter the menus
	string menus[3] = { "USER ID", "PASSWORD", "SUBMIT" };


	while (true)
	{
		prepField(BAR_FIELD_POS - 3, 2);
		setColor(BLUE);
		cout << counter << endl << +key;

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
		else if (key == 80)     //down key
			counter++;
		else if (key == '\r' || key == 77)   //carriage return and right arrow key
		{
			setColor(GREEN);

			if (counter == 0)
			{
				getMenuLine(storedInMenu[counter], MARGIN_2, positions[counter] + MENU_FIELD_POS);
				storedInMenu[counter] = checkInput(storedInMenu[counter], noCheck);

			}
			else if (counter == 1)
			{
				getMenuLine(storedInMenu[counter], MARGIN_2, positions[counter] + MENU_FIELD_POS);
				storedInMenu[counter] = checkInput(storedInMenu[counter], noCheck);

			}
			else if (counter == 2)
			{
				userName = storedInMenu[0];
				password = storedInMenu[1];

				if (validateData())
					allowAccess();
				else {
					EventLog log(BAD_CREDENTIALS(storedInMenu[0]));
				}
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

	//string userName;
	//string password;
	//string userID;
	//string acessLevel;

	//NEED TO ADD AN USER ID FIELD, OR AN UNIQUE ID IDENTIFIER, FOR NOW JUST THE USER NAME
	string sql1 = "SELECT " + user_table::user_id + " FROM " + table::users +
		" WHERE " + user_table::f_name + " = " + addQuotes(this->userName, false) + " AND " +
		user_table::password + " = " + addQuotes(this->password, false) + " LIMIT 1;";

	//sql and and be to find access level and user's first name
	string sql2a = "SELECT ";
	string sql2b("TEST");
	string sql2c = " FROM " + table::users + " WHERE " + user_table::user_id + " = " + addQuotes(this->userID, false) + " LIMIT 1;";

	UserLogIn::dbSearch(sql1, userID);

	if (userID == NOT_FOUND || userID == NULL_FIND)
		return false;
	else {

		//get access level
		sql2b = user_table::permissions_level;
		UserLogIn::dbSearch(sql2a + sql2b + sql2c, this->acessLevel);

		//get user name
		sql2b = user_table::f_name;
		UserLogIn::dbSearch(sql2a + sql2b + sql2c, this->acessLevel);

		return true;
	}
}
