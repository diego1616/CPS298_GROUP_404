#pragma once
#include "DB_Connect.h"
#include "Events.h"

class LogIn : public DB_Connect
{
		//DB_Connect db;

public:
	LogIn();
	void aut();

	void dbSearch(string sql);
	string level;

};

