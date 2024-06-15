#pragma once
class Sell_Bill{
	char bill_date [30];
	int bill_number;
	double bill_total_price;
	double bill_discount;
	int customer_account_number;
public:
	Sell_Bill(void);
	~Sell_Bill(void);
	double add_bill(int customer_account_no);
	int get_bill_number();
	void update_bill();
	bool search_bill(double temp);
	double delete_bill(char file_name[],double temp);
	void display_bills();
	void display_bill();
	double get_bill_total_price(){ return bill_total_price; }
};

