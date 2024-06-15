#include "Customer.h"
#include "Sell_Bill.h"
#include "Drug.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;
Customer_Information::Customer_Information(void){
	 customer_phone [15]=' ';
	 customer_id_card [15]=' ';
	 customer_name [20]=' ';
	 customer_address [20]=' ';
	 customer_type_job [15]=' ';
	 customer_type_card [15]=' ';
}
void Customer_Information::put_info(){
	cout<<"Enter customer information : \n";
	cout<<"Enter customer name : ";      cin>>customer_name;
	cout<<"Enter customer address : ";   cin>>customer_address;
	cout<<"Enter customer phone : ";   cin>>customer_phone;
	cout<<"Enter customer job : ";   cin>>customer_type_job;
	cout<<"Enter customer card type : ";   cin>>customer_type_card;
	cout<<"Enter customer card number : ";   cin>>customer_id_card;
}
void Customer_Information::update_info(){
	char check;
	cout<<"Enter customer update information : \n";
	cout<<"if you want to update name enter y : ";    cin>>check;  
	if ((check=='y')||(check=='Y'))
		cout<<"Enter customer new name : ";      cin>>customer_name;
	cout<<"if you want to update address enter y : ";    cin>>check;  
	if ((check=='y')||(check=='Y'))
		cout<<"Enter customer new address : ";   cin>>customer_address;
	cout<<"if you want to update phone enter y : ";    cin>>check;  
	if ((check=='y')||(check=='Y'))
		cout<<"Enter customer new phone : ";   cin>>customer_phone;
	cout<<"if you want to update job enter y : ";    cin>>check;  
	if ((check=='y')||(check=='Y'))
		cout<<"Enter customer new job : ";   cin>>customer_type_job;
	cout<<"if you want to update card type enter y : ";    cin>>check;  
	if ((check=='y')||(check=='Y')){
		cout<<"Enter customer new card type : ";   cin>>customer_type_card;
	    cout<<"Enter customer card number : ";   cin>>customer_id_card;
	}
}
void Customer_Information::dispaly_info(bool tmp=0){   //   «–« ﬂ«‰ «·»«—«„ — ÌÕ„· «·ﬁÌ„… ’›— ›ÌﬂÊ‰ ··⁄—÷ «· ›’Ì·Ì Ê«·Ê«Õœ ··⁄—÷ «·ﬁ«∆„…
	if (tmp==0){
		cout<<"Customer information is : ";
		cout<<"\nCustomer name is : "<<customer_name;
		cout<<"\nCustomer address is : "<<customer_address;
		cout<<"\nCustomer phone is : "<<customer_phone;
		cout<<"\nCustomer job is : "<<customer_type_job;
		cout<<"\nCustomer card type is : "<<customer_type_card;
		cout<<"\nCustomer ID card is : "<<customer_id_card;
	}
	else
		cout<<customer_name<<"   "<<customer_address<<"   "<<customer_phone<<"   "<<customer_type_job<<"   "<<customer_type_card<<"   "<<customer_id_card<<"   ";
}
Customer_Information::~Customer_Information(void){  }
Customer::Customer(void){
	info=Customer_Information();
	bills_number [100]=0.0;
	count=0;
	customer_account=0;
	Customer_debt=0.0;
	customer_debt_limit=0.0;
	customer_pay_way [10]=' ';
}
void Customer::add_customer(){
	Customer obj;
	int counter=0;;
	fstream fil;
	fil.open("customers.dat", ios::in);
	while(fil.read((char*)&obj,sizeof(Customer)))
		counter++;
	fil.close();
	customer_account=++counter;
	cout<<"the customer account nember is : "<<customer_account<<endl;
	info.put_info();
	cout<<"Enter customer debt limit : ";    cin>>customer_debt_limit;
	cout<<"Enter customer pay way : ";     cin>>customer_pay_way;
	fstream file;
	file.open("customers.dat", ios::app);
	file.write((char*)this,sizeof(Customer));
	file.close();
}
void Customer::update_customer(bool temp){
	if (temp==0)
		search_customer(temp);
	else{
	    fstream file,fil;
		Customer obj;
	    file.open("customers.dat", ios::in);
	    fil.open("temp.dat", ios::out);
	    while(file.read((char*)&obj,sizeof(Customer))){
			if (customer_account==obj.customer_account){
				if (temp==0){
					char check;
	                cout<<"Enter customer update information : \n";
	                cout<<"if you want to update customer information enter y : ";    cin>>check;  
	                if ((check=='y')||(check=='Y'))
						obj.info.update_info();
				    cout<<"if you want to update customer debt limit enter y : ";    cin>>check;  
				    if ((check=='y')||(check=='Y')){
						cout<<"Enter customer new debt limit : ";    cin>>obj.customer_debt_limit;  }
				        cout<<"if you want to update customer pay way enter y : ";    cin>>check;  
				    if ((check=='y')||(check=='Y')){
					    cout<<"Enter customer new pay way : ";    cin>>obj.customer_pay_way;   }
				}
				else{
					obj.Customer_debt=Customer_debt;
					obj.bills_number[count]=bills_number[count];
					obj.count++;
				}
			    fil.write((char*)&obj,sizeof(Customer));
			}
		    else
			    fil.write((char*)&obj,sizeof(Customer));
		}
		file.close();
	    fil.close();
	    file.open("customers.dat" , ios::out );
	    fil.open("temp.dat" , ios::in );
	    while(fil.read((char*)&obj,sizeof(Customer)))
		    file.write((char*)&obj,sizeof(Customer));
	    file.close();
	    fil.close();
	}
}
bool Customer::search_customer(bool temp){
	double no;
	no=customer_account;
	bool check=0;
	Customer obj;
	fstream file;
	file.open("customers.dat",ios::in);   
	cout<<"Enter customer account number : ";   cin>>no;
	while(file.read((char*)&obj,sizeof(Customer))){
		if (no==obj.customer_account){
			cout<<"customer found\n";
			if (temp==0){
			    cout<<"\ncustomer details is : \n";
			    obj.display_customer(0);    
			}
			*this=obj;
			check=1; 
			}
		}
	file.close();
	if (check==0){
		cout<<"cusomer is not found in the pharmacy \n";
	    return 0;
	}
	else
		return 1;
}
void Customer::display_customers(){
	fstream file;
	file.open("customers.dat",ios::in);
	cout<<"Account Number   Name   Adress   Phone number   Job   Card   ID Card   Bill Number   debt   Debt Limit   Pay Way   \n";
	while(file.read((char*)this,sizeof(Customer))){
		display_customer(1);
		// system("pause");
	}
	file.close();
}
void Customer::display_customer(bool temp=0){   //   «·ﬁÌ„… ’›— ··⁄—÷ «·„›’· Ê«·Ê«Õœ ··⁄—÷ «·ﬁ«∆„Ì
	if (temp==0){
		cout<<"\ncustomer account number is : "<<customer_account<<endl;
		info.dispaly_info();
		cout<<"\nBill Numbers : "<<count;
		cout<<"\ncustomer debt is : "<<Customer_debt;
		cout<<"\ncustomer debt limit is : "<<customer_debt_limit;
		cout<<"\ncustomer pay way is : "<<customer_pay_way<<endl;
	}
	else{
		cout<<customer_account<<"   ";
		info.dispaly_info(temp);    
		cout<<count<<"   "<<Customer_debt<<"   "<<customer_debt_limit<<"   "<<customer_pay_way<<endl<<endl;
	}
}
void Customer::delete_customer(){
	fstream file,fil;
	int no;
	char check;
	cout<<"Enter customer account number : ";   cin>>no;
	file.open("customers.dat", ios::in);
	fil.open("temp.dat", ios::out);
	while(file.read((char*)this,sizeof(Customer))){
		if (no==customer_account){
			display_customer();
			cout<<"Cusyomer has been seccessfully deleted ";
		}
		else
			fil.write((char*)this,sizeof(Customer));
	}
	file.close();
	fil.close();
	file.open("customers.dat" , ios::out );
	fil.open("temp.dat" , ios::in );
	while(fil.read((char*)this,sizeof(Customer)))
		file.write((char*)this,sizeof(Customer));
	file.close();
	fil.close();
}
void Customer::add_bill(){
	Sell_Bill objc;
	fstream file,fil;
	double total_price=0;
	search_customer(1);
	if (customer_account>0){
		total_price+=objc.add_bill(customer_account);
		if ((total_price+Customer_debt)>customer_debt_limit){
			cout<<"you have bought more than you have ( debt limit ) ";
			objc.delete_bill(" ",objc.get_bill_number());
		}
		else{
			cout<<"Total price is : "<<total_price;
			Customer_debt+=total_price;
			cout<<"\ncustomer debt after buying is : "<<Customer_debt;
			cout<<"\nif you want to pay for dept choose Y : ";  char ch;   cin>>ch;
	        if ((ch=='Y')||(ch=='y')){
				cout<<"Enter how much you will pay : ";   double pay;   cin>>pay;
				Customer_debt-=pay;
			}
			bills_number [count]=objc.get_bill_number();
			update_customer(1);
			Drug obj;
			char name_c [20]="customer",name_b [20]="SBill";
	        char tail [5]=".dat";
	        char no [20],no2 [20];   // 
	        sprintf(no,"%d",customer_account);  //     
	        strcat(name_c,no);      
            strcat(name_c,tail);
			sprintf(no,"%d",objc.get_bill_number());
			strcat(name_b,no);    //    
            strcat(name_b,tail);
			file.open(name_c, ios::app);   //    › Õ „·› · Œ“Ì‰ „‘ —Ì«  «·“»Ê‰
			fil.open(name_b,ios::in);    //    › Õ „·› „‘ —Ì«  «·›« Ê—… ·‰”ŒÂ« «·Ï „·› „‘ —Ì«  «·“»Ê‰
			while (fil.read((char*)&obj,sizeof(obj)))
				file.write((char*)&obj,sizeof(obj));
		    file.close();
		    fil.close();

		}
	}
}
void Customer::display_customer_buy_list(){
	if (search_customer(0)==1){
	fstream file;
	Drug obj;
	double num=0.0;
	char file_name [20]="customer";
	char tail [5]=".dat";
	char no [20];
	sprintf(no,"%d",customer_account);
	strcat(file_name,no);
	strcat(file_name,tail);
	file.open(file_name, ios::in);
	cout<<"Drug ID   Drug Name   Drug Amount   Price   Total Price   Company Name   Type of Drug   End Date   \n";
	while (file.read((char*)&obj,sizeof(obj))){
		obj.display_drug();
		num+=obj.get_drug_total_price();
	}
	if (num<=0.0) cout<<"\nthere is not any bills for the customer\n";
	else{
		cout<<"\ntotal price for bills : "<<num;
	    cout<<"\nyou have pay : "<<num-Customer_debt;
	    cout<<"\ntotal debt : "<<Customer_debt<<endl;
	}
		
	file.close();
	}
	else cout<<"this costumer not found";
}
void Customer::delete_bill(){
	if (search_customer(1)==1){
		double num;
		cout<<"\nwhat number of bill do you want to delete : ";   cin>>num;
		for (int i=0;i<count;i++){
			if (bills_number [i]==num){
				cout<<"bill found ";
				Sell_Bill obj;
				char file_name [10]="customer";
				char tail [5]=".dat";
			    char no [20];   
	            sprintf(no,"%d",customer_account);
			    strcat(file_name,no);
				strcat(file_name,tail);
				Customer_debt-=obj.delete_bill(file_name,num);
				update_customer(1);
			}
		}
	}
}
void Customer::display_customer_bills(){
	if (search_customer(0)==1){
		Sell_Bill obj;
		double price=0;
		for (int i=0;i<count;i++){
			if (obj.search_bill(bills_number[i])==1){
				price+=obj.get_bill_total_price();
		        cout<<"\nBills total price are : "<<price<<endl;
		        system("pause");
			}
		}
		cout<<"\ntotal price for bills : "<<price;
	    cout<<"\nyou have pay : "<<price-Customer_debt;
	    cout<<"\ntotal debt : "<<Customer_debt<<endl;
	}
	else
		cout<<"\nthere is not any bills for the customer\n";
}
double Customer::get_customer_account(){ return customer_account; }

Customer::~Customer(void){  }