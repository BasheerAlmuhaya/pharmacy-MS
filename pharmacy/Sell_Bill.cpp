#include "Sell_Bill.h"
#include "Drug.h"
#include<iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
Sell_Bill::Sell_Bill(void){
	 bill_total_price=0.0;
	 bill_discount=0.0;
	 customer_account_number=0;
}
double Sell_Bill::add_bill(int customer_account_no){                         //—ﬁ„ «·›« Ê—Â    
	customer_account_number=customer_account_no;
	Sell_Bill obj;
	int counter=0;;
	fstream fil;
	fil.open("Sells.dat", ios::in);
	while(fil.read((char*)&obj,sizeof(Sell_Bill)))
		counter++;
	fil.close();
	bill_number=++counter;
	cout<<"Bill number is : "<<bill_number;
	char* date;
	time_t now;
	now=time(NULL);
	date=ctime(&now);
	strcpy(bill_date,date);
	cout<<"\tBill Data is : "<<bill_date;
	cout<<"Enter Elements to the Bill : \n";
	char bill_name [20]="SBill";
	char tail [5]=".dat";
	char no [20];   //—ﬁ„ «·›« Ê—Â 
	sprintf(no,"%d",bill_number);  //      ÕÊÌ· —ﬁ„ «·›« Ê—Â „‰ œ»· «·Ï  ‘«— 
	strcat(bill_name,no);    //Bill 1,Bill 2   ‰”Œ «·—ﬁ„ «·„ÕÊ· «·Ï Ã«‰» «”„ «·›« Ê—… Ê–·ﬂ · Õ›Ÿ „Õ ÊÌ«  ›« Ê—… «·‘—«¡ œ«Œ· „·› »ÌﬂÊ‰    
	strcat(bill_name,tail);    
	Drug objc;
	bill_total_price=objc.sell_drug(bill_name);
	cout<<"\nTotal price of bill :"<<bill_total_price;
	cout<<"\nEnter a discount for this customer :";    cin>>bill_discount;   //    Œ’„
	bill_total_price-=bill_discount;
	cout<<"\nTotal price of bill after discount :"<<bill_total_price<<endl;
	fstream file;
	file.open("Sells.dat", ios::app);
	file.write((char*)this,sizeof(Sell_Bill));
	file.close();
	return bill_total_price;
}
bool Sell_Bill::search_bill(double temp){
    fstream file;
	Sell_Bill obj;
	int bill_no;
	bill_no=temp;
	if (temp==0){
		cout<<"Enter Bill number : ";   cin>>bill_no;
	}
	file.open("Sells.dat",ios::in);
	while(file.read((char*)&obj,sizeof(obj))){
		if (obj.bill_number==bill_no){
			obj.display_bill();
			*this=obj;
			return 1;
		}
	}
	file.close();  
	if (temp==0)   cout<<"\n The Bill is not in the Pharmacy \n";
	return 0;
}
void Sell_Bill::display_bills(){
	fstream file;
	Drug obj;
	double price=0;
	file.open("Sells.dat",ios::in);
	while(file.read((char*)this,sizeof(Sell_Bill))){
		display_bill();
		price+=bill_total_price;
		cout<<"\nBills total price are : "<<price<<endl;
		system("pause");
	}
	file.close();
}
void Sell_Bill::display_bill(){
	fstream fil;
	Drug obj;
	cout<<"The Bill is : \n";
	cout<<"Bill number is : "<<bill_number;
    cout<<"\tBill Data is : "<<bill_date;
	cout<<"Your Elements in the Bill : \n";
	cout<<"Drug ID   Drug Name   Drug Amount   Price   Total Price   Company Name   Type of Drug   End Date   \n";
	char bill_name [20]="SBill";
	char tail [5]=".dat";
	char no [20];   //—ﬁ„ «·›« Ê—Â 
	sprintf(no,"%d",bill_number);  //      ÕÊÌ· —ﬁ„ «·›« Ê—Â „‰ œ»· «·Ï  ‘«— 
	strcat(bill_name,no);    //Bill 1,Bill 2   ‰”Œ «·—ﬁ„ «·„ÕÊ· «·Ï Ã«‰» «”„ «·›« Ê—… Ê–·ﬂ · Õ›Ÿ „Õ ÊÌ«  ›« Ê—… «·‘—«¡ œ«Œ· „·› »ÌﬂÊ‰    
	strcat(bill_name,tail);
	fil.open(bill_name,ios::in);
	while(fil.read((char*)&obj,sizeof(obj)))
		obj.display_drug();
	cout<<"\ndiscount is : "<<bill_discount<<endl;
	cout<<"\nTotal price is : "<<bill_total_price<<endl;
	fil.close();
}
double Sell_Bill::delete_bill(char file_name[],double temp){
	if (search_bill(temp)==1){
		fstream file_b,file_t,file_sb,file_c,file_t2;
		int c_a_n=customer_account_number;
		Drug obj,arr[20];
		bool check=0;
		int count=0,bill_num;
		double price=0;
		bill_num=bill_number;
		char bill_name [20]="SBill";
	    char tail [5]=".dat";
	    char no [20];   //—ﬁ„ «·›« Ê—Â 
	    sprintf(no,"%d",bill_number);  //      ÕÊÌ· —ﬁ„ «·›« Ê—Â „‰ œ»· «·Ï  ‘«— 
	    strcat(bill_name,no);    //Bill 1,Bill 2   ‰”Œ «·—ﬁ„ «·„ÕÊ· «·Ï Ã«‰» «”„ «·›« Ê—… Ê–·ﬂ · Õ›Ÿ „Õ ÊÌ«  ›« Ê—… «·‘—«¡ œ«Œ· „·› »ÌﬂÊ‰    
	    strcat(bill_name,tail);
		file_b.open("Sells.dat",ios::in);
	    file_t.open("temp.dat" , ios::out );
	    while(file_b.read((char*)this,sizeof(Sell_Bill))){
			if (bill_number==bill_num){
				check=1;
				price=bill_total_price;
			}
			else
				file_t.write((char*)this,sizeof(Sell_Bill));
		}
		file_b.close();
		file_t.close();
		file_b.open("Sells.dat" , ios::out );
		file_t.open("temp.dat" , ios::in );
		while(file_t.read((char*)this,sizeof(Sell_Bill)))
			file_b.write((char*)this,sizeof(Sell_Bill));
		file_b.close();
		file_t.close();
		file_sb.open(bill_name,ios::in);
		if (check==1){
			while(file_sb.read((char*)&obj,sizeof(obj))){
					obj.update_drug(0);
					arr[count++]=obj;
				}
			file_sb.close();
			strcpy(file_name,"customer");
	        sprintf(no,"%d",c_a_n);
	        strcat(file_name,no);
	        strcat(file_name,tail);
			file_c.open(file_name,ios::in);
		    file_t2.open(bill_name,ios::out);
			while(file_c.read((char*)&obj,sizeof(obj))){
				for (int i=0;i<count;i++){
					if (arr[i].get_drug_amount()!=obj.get_drug_amount())              
						file_t2.write((char*)&obj,sizeof(obj));
				}
			}				
			file_c.close();     file_t2.close();
		}
	    file_sb.open(bill_name,ios::out);    file_sb.clear();    file_sb.close();
		file_c.open(file_name,ios::out);
		file_t2.open(bill_name,ios::in);
	    while(file_t2.read((char*)this,sizeof(Sell_Bill)))
			file_c.write((char*)this,sizeof(Sell_Bill));
		file_c.close();    file_t2.close();
		cout<<"the Bill has been seccessfully deleted ";
		return price;
	}
}
void Sell_Bill::update_bill(){
	if (search_bill(0)==1){
	    fstream file_b,file_t;
	    double bill_no;
		bill_no=bill_number;
		char bill_name [20]="SBill";
	    char tail [5]=".dat";
	    char no [20];   //—ﬁ„ «·›« Ê—Â 
	    sprintf(no,"%d",bill_number);  //      ÕÊÌ· —ﬁ„ «·›« Ê—Â „‰ œ»· «·Ï  ‘«— 
	    strcat(bill_name,no);    //Bill 1,Bill 2   ‰”Œ «·—ﬁ„ «·„ÕÊ· «·Ï Ã«‰» «”„ «·›« Ê—… Ê–·ﬂ · Õ›Ÿ „Õ ÊÌ«  ›« Ê—… «·‘—«¡ œ«Œ· „·› »ÌﬂÊ‰    
        strcat(bill_name,tail);
		file_b.open("Sells.dat",ios::in);
		file_t.open("temp.dat", ios::out);
		while (file_b.read((char*)this,sizeof(Sell_Bill))){
			if (bill_number==bill_no){
				int enter;
				cout<<"Enter 1- to edit discount\n\t 2- to add a drug to the bill\n\t 3- to delete a specific drug from the bill\n";  cin>>enter;
				switch (enter){
				case 1:{
					    double discount;
						cout<<"Enter a discount for this customer :";    cin>>discount;
						bill_total_price=(bill_total_price+bill_discount)-discount; 
					    bill_discount=discount; 
						cout<<"Total price after discount is : "<<bill_total_price;  
	                    system("pause");    system("cls");
	                    display_bill();
	                    file_t.write((char*)this,sizeof(Sell_Bill));
						break; }
				case 2:{
					    double total_price;
						Drug obj;
						total_price=obj.sell_drug(bill_name);
						bill_total_price+=total_price;
					    cout<<"Total price is : "<<bill_total_price;  
	                    system("pause");    system("cls");
	                    display_bill();
	                    file_t.write((char*)this,sizeof(Sell_Bill));
					   break;  }
				case 3:{
						Drug obj;
						double total_price;
						char name[20];
	                    cout<<"Enter Drug name : ";    cin>>name;
						obj.delete_drug(name,bill_name);
						total_price=obj.delete_drug_from_bill(name,bill_name);
						bill_total_price-=(total_price-bill_discount);
						cout<<"Total price is : "<<bill_total_price;  
	                    system("pause");    system("cls");
						if (bill_total_price==0)
							bill_discount=0;
						else
							file_t.write((char*)this,sizeof(Sell_Bill));
						display_bill();
						break; }
				default:   break;
				}
			}
		}
		file_t.close();
		file_b.close();
		file_b.open("Sells.dat",ios::out);
	    file_t.open("temp.dat", ios::in);
		while(file_t.read((char*)this,sizeof(Sell_Bill)))
			file_b.write((char*)this,sizeof(Sell_Bill));
		file_t.close();
		file_b.close();
	}
}

int Sell_Bill::get_bill_number(){   return bill_number;  }

Sell_Bill::~Sell_Bill(void){  }
