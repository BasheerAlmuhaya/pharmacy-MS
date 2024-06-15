#pragma once
class Drug{
	double drug_amount;
	double drug_price;
	double drug_total_price;
	double drug_sell_price;
	char drug_id [10];
	char drug_company_name [20];
	char Type_of_drug [10];
	char drug_end_date [10];
	char drug_name [20];
public:
	Drug(void);
	~Drug(void);
	double add_drug(char bill_name []);
	bool update_drug(bool temp);
	void edit_drug();
	void display_drugs(char name[]);
	void display_drug();
	bool search_drug(bool tmp);
	void delete_drug(char drug_name3 [],char bill_name3 []);
	double sell_drug(char bill_name2 []);
	double delete_drug_from_bill(char bill_name4 [],char drug_name4 []);
	double get_drug_amount(){ return drug_amount; }
	double get_drug_total_price(){ return drug_total_price; }
	void daily_report();
};

