#include "StockLevel.h"



string StockLevel::findLowStock()
{
	
	/*
	 These are different sqlite styatements that could work.  I need to compare data in two different tables. 
	
		SELECT* FROM SAMPLE_TABLE ORDER BY ROWID ASC LIMIT 1

		SELECT Table1.ID
		FROM Table1 NATURAL LEFT JOIN Table2
		WHERE Table2.ID IS NULL
	
		*/
	string ID = table::products + "." + product_table::product_id;

	string sql = "SELECT " + ID + " FROM " + table::products + " WHERE " +  ";";

	//for now, just for testing.  I reality it would have the product id of whatever is low and return it.
	string lowItem = "";

	if (!lowItem.empty())
		return lowItem;
	else return "";
}

void StockLevel::orderItem(string Item) {

	//build sql statement here


}

void StockLevel::checkLoop()
{
	string item = "";

	while (true) {
		
		item = this->findLowStock();

		if (item != "" || !item.empty())
		{
			this->orderItem(item);
			outputMsg("TEST OF THIS THREAD");
		}
		else
		{
			outputMsg("SLEEP");
			
			//Sleep this thread until is needed again
			std::this_thread::sleep_for(std::chrono::minutes(this->interval));
			
		}
		
		outputMsg("END OF LOOP - TEST AGAIN");
			
	}
}