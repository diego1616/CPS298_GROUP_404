#pragma once
#include <string>
using namespace std;


namespace table {
	const string products = "product_table";
	const string manufacturers = "manufacturer_table";
	const string departments = "department_table";
	const string inventory = "inventory_amounts_table";
	const string keywords = "keyword_table";
	const string product_keywords = "product_keyword_table";
	const string storage = "storage_table";
	const string storage_locations = "storage_location_table";
	const string sales_locations = "sales_location_table";
	const string product_sales_locations = "product_sales_location_table";
	const string users = "user_table";
	const string jobs = "job_table";
}


// Note: const implies static in this case
namespace product_table {
	const string product_id = "product_id";
  	const string item_name = "item_name";
	const string manufacturer_id = "mfg_id";
	const string manufacturer_product_id = "mfg_part_no";
	const string manufacturer_price = "mfg_price";
	const string retail_price = "retail_price";
	const string department_id = "dpt_id";
	const string low_stock_quantity = "min_stock";
	const string stock = "stock";
	const string reorder = "reorder";
}


namespace manufacturer_table {
	const string manufacturer_id = "manufacturer_id";
	const string manufacturer_name = "manufacturer_name";
	const string contact_name = "contact_name";
	const string contact_email = "contact_email";
	const string street_address = "street_address";
	const string street_name = "street_name";
	const string city = "city";
	const string zip_code = "zip_code";
	const string state = "state";
	const string country = "country";
	const string phone_number = "phone_number";
}

namespace department_table {
	const string department_id = "department_id";
	const string department_name = "department_name";
}

namespace inventory_amounts_table {
	const string inventory_id = "inventory_id";
	const string product_id = "product_id";
	const string product_count = "product_count";
}

namespace keyword_table {
	const string keyword_id = "keyword_id";
	const string keyword_name = "keyword_name";
}

namespace product_keyword_table {
	const string p_key_id = "p_key_id";
	const string keyword_id = "keyword_id";
	const string product_id = "product_id";
}

namespace storage_table {
	const string storage_id = "storage_id";
	const string storage_name = "storage_name";
}

namespace storage_location_table {
	const string storage_loc_id = "storage_loc_id";
	const string storage_id = "storage_id";
	const string product_id = "product_id";
}

namespace sales_location_table {
	const string sales_loc_id = "sales_loc_id";
	const string sales_loc_name = "sales_loc_name";
}

namespace product_sales_location_table {
	const string product_sales_loc_id = "product_sales_loc_id";
	const string sales_loc_id = "sales_loc_id";
	const string product_id = "product_id";
}

namespace user_table {
	const string user_id = "user_id";
	const string f_name = "f_name";
	const string l_name = "l_name";
	const string job_id = "job_id";
	const string department_id = "department_id";
	const string permissions_level = "permissions_level";
	const string password = "password";

	//const string user_id = "user_id";
	//const string f_name = "f_name";
	//const string l_name = "l_name";
	//const string job_id = "job_id";
	//const string department_id = "department_id";
	//const string password = "password";
	//const string permission_level_id = "permission_level_id";

}

namespace job_table {
	const string job_id = "job_id";
	const string job_name = "job_name";
}

namespace permission_level_table {
	const string permission_level_id = "permission_level_id";
	const string permission_level_name = "permission_level_name";
}


namespace humanized {
	const string tables[][2] = {
		{table::products, "Products"},
		{table::manufacturers, "Manufacturers"},
		{table::departments, "Departments"},
		{table::inventory, "Inventory"},
		{table::keywords, "Keywords"},
		{table::product_keywords, "Product Keywords"},
		{table::storage, "Storage"},
		{table::storage_locations, "Storage Locations"},
		{table::sales_locations, "Sales Locations"},
		{table::product_sales_locations, "Product Sales Locations"},
		{table::users, "Users"},
		{table::jobs, "Jobs"}
	};

	const string product_fields[][2] = {
		{product_table::product_id, "Product ID"},
		{product_table::item_name, "Item Name"},
		{product_table::manufacturer_id, "Mfr. ID"},
		{product_table::manufacturer_product_id, "Mfr. Product ID"},
		{product_table::manufacturer_price, "Mfr. Price"},
		{product_table::retail_price, "Retail Price"},
		{product_table::department_id, "Dept ID"},
		{product_table::low_stock_quantity, "Low Stock Quantity"}
	};
}
