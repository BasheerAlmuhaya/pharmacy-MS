#include "Buy_Bill.h"
#include "Drug.h"
#include<iostream>
#include<fstream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
Buy_Bill::Buy_Bill(void){  bill_total_price=0.0; }
void Buy_Bill::add_bill(){
	Buy_Bill obj;
	int counter=0;;
	fstream fil;
	fil.open("Bills.dat", ios::in);
	while(fil.read((char*)&obj,sizeof(Buy_Bill)))
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
	char bill_name [20]="BBill";
	char tail [5]=".dat";
	char no [20];   //—ﬁ„ «·›« Ê—Â 
	sprintf(no,"%d",bill_number);  //      ÕÊÌ· —ﬁ„ «·›« Ê—Â „‰ œ»· «·Ï  ‘«— 
	strcat(bill_name,no);    //Bill 1,Bill 2   ‰”Œ «·—ﬁ„ «·„ÕÊ· «·Ï Ã«‰» «”„ «·›« Ê—… Ê–·ﬂ · Õ›Ÿ „Õ ÊÌ«  ›« Ê—… «·‘—«¡ œ«Œ· „·› »ÌﬂÊ‰    
	strcat(bill_name,tail);
	Drug objc;
	bill_total_price=objc.add_drug(bill_name);
	cout<<"Total price is : "<<bill_total_price;  
	system("pause");    system("cls");
	display_bill();
	fstream file;
	file.open("Bills.dat", ios::app);
	file.write((char*)this,sizeof(Buy_Bill));
	file.close();
}
Buy_Bill Buy_Bill::search_bill(){
	fstream file;
	 Buy_Bill tmp1;
	int bill_no;
	bool check=0;
	cout<<"Enter Bill number : ";   cin>>bill_no;
	file.open("Bills.dat",ios::in);
	while(file.read((char*)this,sizeof(Buy_Bill))){
		if (bill_number==bill_no){
			cout<<"Bill found\n";
			display_bill();
			check=1;tmp1=*this;//  return *this;
		}
	}
	file.close();
	if(check == 0){   
		cout<<"\n The Bill is not in the Pharmacy \n";
		Buy_Bill tmp;    return tmp;
	}return tmp1;
}
void Buy_Bill::delete_bill(){
	*this=search_bill();
	if (this->bill_number!=0){
		fstream file,file_temp;
		int num=bill_number;
		Drug obj;
		bool check=0;
		char bill_name [20]="BBill";
	    char tail [5]=".dat";
	    char no [20];   //—ﬁ„ «·›« Ê—Â 
	    sprintf(no,"%d",bill_number);  //      ÕÊÌ· —ﬁ„ «·›« Ê—Â „‰ œ»· «·Ï  ‘«— 
	    strcat(bill_name,no);    //Bill 1,Bill 2   ‰”Œ «·—ﬁ„ «·„ÕÊ· «·Ï Ã«‰» «”„ «·›« Ê—… Ê–·ﬂ · Õ›Ÿ „Õ ÊÌ«  ›« Ê—… «·‘—«¡ œ«Œ· „·› »ÌﬂÊ‰    
        strcat(bill_name,tail);
		file.open("Bills.dat",ios::in);
	    file_temp.open("temp.dat" , ios::out );
	    while(file.read((char*)this,sizeof(Buy_Bill))){
			if (bill_number==num)
				check=1;
			else
				file_temp.write((char*)this,sizeof(Buy_Bill));
		}
		file.close();
		file_temp.close();
		file.open("Bills.dat" , ios::out );
		file_temp.open("temp.dat" , ios::in );
		while(file_temp.read((char*)this,sizeof(Buy_Bill)))
			file.write((char*)this,sizeof(Buy_Bill));
		file.close();
		file_temp.close();
		cout<<"the Bill has been seccessfully deleted ";
		if (check==1){
			fstream fil;
	        fil.open(bill_name,ios::in);
	        while(fil.read((char*)&obj,sizeof(obj)))
				obj.update_drug(1);
	        fil.close();
	        fil.open(bill_name,ios::out);   fil.clear();
	        fil.close();
		}
	}
}
void Buy_Bill::display_bills(){
	fstream file;
	Drug obj;
	double price=0.0;
	file.open("Bills.dat",ios::in);
	while(file.read((char*)this,sizeof(Buy_Bill))){
		this->display_bill();
		price+=this->bill_total_price;
		cout<<"\nBills total price are : "<<price<<endl;
		system("pause");
	}
	file.close();
}
void Buy_Bill::display_bill(){
	fstream fil;
	Drug obj;
	cout<<"The Bill is : \n";
	cout<<"Bill number is : "<<bill_number;
    cout<<"\tBill Data is : "<<bill_date;
	cout<<"Your Elements in the Bill : \n";
	cout<<"Drug ID   Drug Name   Drug Amount   Price   Total Price   Company Name   Type of Drug   End Date   \n";
	char bill_name [20]="BBill";
	char tail [5]=".dat";
	char no [20];   //—ﬁ„ «·›« Ê—Â 
	sprintf(no,"%d",bill_number);  //      ÕÊÌ· —ﬁ„ «·›« Ê—Â „‰ œ»· «·Ï  ‘«— 
	strcat(bill_name,no);    //Bill 1,Bill 2   ‰”Œ «·—ﬁ„ «·„ÕÊ· «·Ï Ã«‰» «”„ «·›« Ê—… Ê–·ﬂ · Õ›Ÿ „Õ ÊÌ«  ›« Ê—… «·‘—«¡ œ«Œ· „·› »ÌﬂÊ‰    
    strcat(bill_name,tail);
	fil.open(bill_name,ios::in);
	while(fil.read((char*)&obj,sizeof(obj)))
		obj.display_drug();
	cout<<"\nTotal price is : "<<bill_total_price<<endl;
	system("pause");
	fil.close();
}
void Buy_Bill::update_bill(){
	*this=search_bill();
	if (this->bill_number!=0){
	    fstream file_b,file_t;
	    double bill_no;
		bill_no=bill_number;
		char bill_name [20]="BBill";
	    char tail [5]=".dat";
	    char no [20];   //—ﬁ„ «·›« Ê—Â 
	    sprintf(no,"%d",bill_number);  //      ÕÊÌ· —ﬁ„ «·›« Ê—Â „‰ œ»· «·Ï  ‘«— 
	    strcat(bill_name,no);    //Bill 1,Bill 2   ‰”Œ «·—ﬁ„ «·„ÕÊ· «·Ï Ã«‰» «”„ «·›« Ê—… Ê–·ﬂ · Õ›Ÿ „Õ ÊÌ«  ›« Ê—… «·‘—«¡ œ«Œ· „·› »ÌﬂÊ‰    
        strcat(bill_name,tail);
		file_b.open("Bills.dat",ios::in);
		file_t.open("temp.dat", ios::out);
		while(file_b.read((char*)this,sizeof(Buy_Bill))){
			if (bill_number==bill_no){
				int enter;
				cout<<"Enter 1- to add a drug to the bill\n\t 2- to delete a specific drug from the bill\n";  cin>>enter;
				switch (enter){
				case 1:{
						Drug obj;
						double total_price;
						total_price=obj.add_drug(bill_name);
						bill_total_price+=total_price; 
						cout<<"Total price is : "<<bill_total_price;  
	                    system("pause");    system("cls");
	                    display_bill();
	                    file_t.write((char*)this,sizeof(Buy_Bill));
						break;  }
				case 2:{
						Drug obj;
						double total_price;
						char name[20];
	                    cout<<"Enter Drug name : ";    cin>>name;
						obj.delete_drug(name,bill_name);
						total_price=obj.delete_drug_from_bill(name,bill_name);
						bill_total_price-=total_price;
						cout<<"Total price is : "<<bill_total_price;  
	                    system("pause");    system("cls");
	                    display_bill();
	                    file_t.write((char*)this,sizeof(Buy_Bill));
						break; }
				default:   break;
				}
			}
			else
				file_t.write((char*)this,sizeof(Buy_Bill));
		}
		file_t.close();
		file_b.close();
		file_b.open("Bills.dat",ios::out);
	    file_t.open("temp.dat", ios::in);
		while(file_t.read((char*)this,sizeof(Buy_Bill)))
			file_b.write((char*)this,sizeof(Buy_Bill));
		file_t.close();
		file_b.close();
	
	}
}

Buy_Bill::~Buy_Bill(void){ }