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
	
	StockLevel();	//make this one private so it can't be called.  Must use overloaded one. 

public:

	StockLevel(int number) {
	
		this->interval = number;
		thread1 = thread(&StockLevel::checkLoop, this);
		
	}
	
	~StockLevel() {

		thread1.join();
	}

};

