//this class is used to create a thread and look for items where the stock level < min stock level.
//If it find an item, it flags it for reordering, and looks for the next one. 
//If it doesnt find anything, it sleeps for one minute and it does it all over again. 
//The entire process is automated, and all you have to do is build the object with an integer argument used for search interval. 

#pragma once
#include "DB_Connect.h"
#include <thread>
#include "Menu.h"


class StockLevel : 
	public DB_Connect,
		public Menu
{
	int interval;
	void checkLoop();
	void findLowStock();
	void orderRequest();
	thread thread1;
	void dbSearch(string sql, bool low_stock = false);
	string prod_id;
	
	StockLevel();	//made this one private so it can't be called.  Must use overloaded one. 

public:

	StockLevel(int number) {
	
		this->interval = number;
		thread1 = thread(&StockLevel::checkLoop, this);
		
	}
	
	~StockLevel() {

		thread1.join();
	}

};

