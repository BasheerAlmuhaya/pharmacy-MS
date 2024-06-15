#include "Customer.h"
#include "Buy_Bill.h"
#include "Drug.h"
#include "Sell_Bill.h"
#include "displays.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
	system("cls");firstF();
	showpassword();
	loading();
	Main();
	gotoxy(1, 27);
	system("pause");

/*	Drug d;
	Buy_Bill b;
	Customer c;
	Sell_Bill s;
	int num,no;
	do{
	    system("cls");
		cout<<"Pharmacy Departments are : \n1- Store\n2- Buy Bills\n3- Sell Bills\n4- Customers\n0- to exit\n choose a department : ";   cin>>num;
		switch (num){
		case 1:{
			do{
				system("cls");
				cout<<"Store Departments are : \n1- Add Drugs\n2- display Drugs\n3- search a Drug\n4- edit a Drug\n5- delete a Drug\n6- daily report\n0- to exit\n choose a department : ";   cin>>no;
			    switch (no){
				case 0:   break;
			    case 1:   d.add_drug(" "); break;
			    case 2:   d.display_drugs(" "); break;
			    case 3:   d.search_drug(0); break;
			    case 4:   d.edit_drug(); break;
			    case 5:   d.delete_drug(" "," "); break;
				case 6:   d.daily_report(); break;
			    default:  cout<<"Error choose again "; system("pause"); cout<<endl;
			    }     system("pause");
			}while(no!=0); break;  system("pause");   
	    }
		case 2:{
			do{
				system("cls");
			    cout<<"Buy Bills Departments are : \n1- Add a Bill\n2- display Bills\n3- search a Bill\n4- edit a Bill\n5- delete a Bill\n0- to exit\n choose a department : ";   cin>>no;
			    switch (no){
				case 0:   break;
			    case 1:   b.add_bill(); break;
			    case 2:   b.display_bills(); break;
			    case 3:   b.search_bill(); break;
			    case 4:   b.update_bill(); break;
			    case 5:   b.delete_bill(); break;
			    default:  cout<<"Error choose again "; system("pause"); cout<<endl;
			    }    system("pause");
			}while(no!=0); break;   system("pause");   
	    }
		case 3:{
			do{
				system("cls");
			    cout<<"Sell Bills Departments are : \n1- Add a Bill\n2- display Bills\n3- search a Bill\n4- edit a Bill\n5- delete a Bill\n0- to exit\n choose a department : ";   cin>>no;
			    switch (no){
				case 0:   break;
			    case 1:   s.add_bill(0); break;
			    case 2:   s.display_bills(); break;
			    case 3:   s.search_bill(0); break;
			    case 4:   s.update_bill(); break;
			    case 5:   s.delete_bill(" ",0); break;
			    default:  cout<<"Error choose again "; system("pause"); cout<<endl;
			    }     system("pause");
			}while(no!=0); break;   system("pause");   
	    }
		case 4:{
			do{
				system("cls");
			    cout<<"Customer Departments are : \n1- Add a Customer\n2- display Customers\n3- search a Customer\n4- edit a Customer\n5- delete a Customer\n6- transection a Customer\n0- to exit\n choose a department : ";   cin>>no;
			    switch (no){
				case 0:   break;
			    case 1:   c.add_customer(); break;
			    case 2:   c.display_customers(); break;
			    case 3:   c.search_customer(0); break;
			    case 4:   c.update_customer(0); break;
			    case 5:   c.delete_customer(); break;
				case 6:{
					do{
				system("pause");  system("cls");
			    cout<<"transection Customer Departments are : \n1- Add a Bill\n2- display list of buys\n3- display bills\n4- delete a Bill\n0- to exit\n choose a department : ";   cin>>no;
			    switch (no){
				case 0:   break;
			    case 1:   c.add_bill(); break;
			    case 2:   c.display_customer_bills(); break;   
			    case 3:   c.display_customer_buy_list(); break;
				case 4:   c.delete_bill(); break;
			    default:  cout<<"Error choose again "; system("pause"); cout<<endl;
			    }    system("pause");
			}while(no!=0); break;   system("pause");  
				}
			    default:  cout<<"Error choose again "; system("pause"); cout<<endl;
			    }    system("pause");
			}while(no!=0); break;   system("pause");  
		}
		default :  cout<<"Error choose again "; system("pause"); cout<<endl;
		}
	}while(num!=0);    system("pause");    //*/

	//fstream f; f.open("Bills.dat",ios::out);  f.clear();    f.close();

	//s.add_bill(0);    system("pause");    system("cls");
	//s.display_bills();    system("pause");    system("cls");
	//s.search_bill(0);    system("pause");    system("cls");
	//s.delete_bill(" ",0);    system("pause");    system("cls");    
	//s.update_bill();    system("pause");    system("cls");          
	//s.display_bills();    system("pause");    system("cls");      

	//c.add_customer();    system("pause");    system("cls");
	//c.display_customers();   system("pause");    system("cls");
	//c.search_customer(0);    system("pause");    system("cls");
	//c.delete_customer();    system("pause");    system("cls");
	//c.update_customer(0);     system("pause");    system("cls");   
	//c.display_customers();   system("pause");    system("cls");
	//c.add_bill();     system("pause");    system("cls");
	//c.delete_bill();     system("pause");    system("cls");
	//c.display_customer_bills();     system("pause");    system("cls");
	//c.display_customer_buy_list();    system("pause");    system("cls");

	//b.add_bill();   system("pause");    system("cls");
	//b.display_bills();    system("pause");    system("cls");  
	//b.update_bill();   system("pause");    system("cls");    
	//b.search_bill();    system("pause");    system("cls");
	//b.delete_bill();    system("pause");    system("cls");  
	//b.display_bills();    system("pause");    system("cls");

	//d.daily_report();     system("pause");    system("cls");
	//d.add_drug(" ");    system("pause");    system("cls");
	//d.display_drugs(" ");    system("pause");    system("cls");
	//d.edit_drug();   system("pause");     system("cls");
	//d.search_drug(0);   system("pause");     system("cls");
	//d.delete_drug(" "," ");   system("pause");     system("cls");
	//d.display_drugs(" ");    system("pause");    system("cls");

	
}