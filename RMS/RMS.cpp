#include <iostream>
#include "DB_Connect.h"
#include "DB_Literals.h"

int main()
{
	DB_Connect dataBase;

	//printing the table names
	dataBase.getTables();
	

	return 0;
}


