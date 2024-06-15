#pragma once
class Buy_Bill{
	char bill_date [30];
	int bill_number;
	double bill_total_price;
public:
	Buy_Bill(void);
	~Buy_Bill(void);
	void add_bill();
	void update_bill();
	Buy_Bill search_bill();
	void delete_bill();
	void display_bills();
	void display_bill();
	int get_bill_number(){ return bill_number; }
};