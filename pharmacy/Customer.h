#pragma once
class Customer_Information{
	char customer_phone [15];
	char customer_id_card [15];
	char customer_name [20];
	char customer_address [20];
	char customer_type_job [15];
	char customer_type_card [15];
public:
	Customer_Information();
    ~Customer_Information();
	void put_info();
	void update_info();
	void dispaly_info(bool tmp);
};
class Customer{
	Customer_Information info;
	int customer_account;
	double Customer_debt;   //    «·œÌÊ‰
	double customer_debt_limit;
	char customer_pay_way [10];
	double bills_number [100];   //    „’›Ê›… ·Õ›Ÿ «—ﬁ«„ ›Ê« Ì— «·⁄„Ì·
	int count;

public:
	Customer(void);
	~Customer(void);
	void add_customer();
	void update_customer(bool temp);
//	void edit_customer();
	bool search_customer(bool temp);
	void display_customer(bool temp);
	void display_customers();
	void delete_customer();
	void add_bill();
	void delete_bill();
	void display_customer_buy_list();
	void display_customer_bills();
	double get_customer_account();
};

