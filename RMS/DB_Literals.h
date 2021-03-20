#pragma once
#include <string>
using namespace std;

// Note: const implies static in this case
namespace product_table {
	const string product_id = "product_id";
  	const string item_name = "item_name";
	const string manufacturer_id = "manufacturer_id";
	const string manufacturer_product_id = "manufacturer_product_id";
	const string manufacturer_price = "manufacturer_price";
	const string retail_price = "retail_price";
	const string department_id = "department_id";
	const string low_stock_quantity = "low_stock_quantity";
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
	const string password = "password";
	const string permission_level_id = "permission_level_id";
}

namespace job_table {
	const string job_id = "job_id";
	const string job_name = "job_name";
}

namespace permission_level_table = 
	const string permission_level_id = "permission_level_id";
	const string permission_level_name = "permission_level_name";


//namespace DB_Literals {
//
//	using namespace product_table;
//	using namespace manufacturer_table;
//	using namespace department_table;
//	using namespace inventory_amounts_table;
//	using namespace keyword_table;
//	using namespace product_keyword_table;
//	using namespace storage_table;
//	using namespace storage_location_table;
//	using namespace sales_location_table;
//	using namespace product_sales_location_table;
//	using namespace user_table;
//	using namespace job_table;
//	using namepsace permission_level_table;
//
//
//}
