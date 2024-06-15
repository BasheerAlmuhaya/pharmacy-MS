#include "Drug.h"
#include "Buy_Bill.h"
#include "Sell_Bill.h"
#include <iostream>
#include <fstream>
using namespace std;

Drug::Drug(void){
	drug_company_name [20]=' ';
	drug_end_date [10]=' ';
	Type_of_drug [10]=' ';
	drug_id [10]=' ';
	drug_amount=0.0;
	drug_price=0.0;
	drug_sell_price=0.0;
	drug_total_price=0.0;
}
double Drug::add_drug(char bill_name []){
	fstream file,fil;
	char ch;
	double total_price=0.0;
	file.open("Drugs.dat",ios::app );
	if (strcmp(bill_name," ")!=0)   //   «–« ﬂ«‰ «·»«—«„ — ›«—€ ·«Ì „ › Õ „·› »Â–« «·«”„ ÊÂ–« Ì⁄‰Ì «‰ «·„” Œœ„ ÌœŒ· «œÊÌÂ ··„Œ“‰ Ê·Ì” «·Ï ›« Ê—Â
		fil.open(bill_name,ios::app );
	do{
		char name [20];
		cout<<"Enter the Drug ID :";  cin>>drug_id;
		cout<<"Enter the Drug Name :";  cin>>name;   strcpy(drug_name,name);
		cout<<"Enter the Drug Amount :";  cin>>drug_amount;
		cout<<"Enter the Price :";          cin>>drug_price;    
		cout<<"Enter the Company Name :";      cin>>drug_company_name;
	    cout<<"Enter the Type of Drug :";        cin>>Type_of_drug;
		cout<<"Enter the End Date :";        cin>>drug_end_date;
		drug_total_price=drug_amount*drug_price;
		total_price+=drug_total_price;
		drug_sell_price=(drug_price)+(drug_price/10.0);
		if (update_drug(0)==0)
			file.write((char*)this,sizeof(Drug));
		if (strcmp(bill_name," ")!=0)
			fil.write((char*)this,sizeof(Drug));
		cout<<"Do you want to add another Drug [y , n] ?";  cin>>ch;
	}  while((ch=='y')||(ch=='Y'));
	file.close();
	if (strcmp(bill_name," ")!=0)
		fil.close();
	return total_price;
}
bool Drug::update_drug(bool temp){    //    «–« ﬂ«‰ «·»«—«„ — ÌÕ„· «·ﬁÌ„… ’›— ›Â–« Ì⁄‰Ì «÷«›Â Ê«·Ê«Õœ ··ÿ—Õ
	fstream file,file_temp;
	Drug obj;
	bool check=0;
	file.open("Drugs.dat" , ios::in );
	file_temp.open("temp.dat" , ios::out );
	while(file.read((char*)&obj,sizeof(Drug))){
		if((strcmp(obj.drug_id,drug_id)==0)&&(strcmp(obj.drug_name,drug_name)==0)&&(strcmp(obj.Type_of_drug,Type_of_drug)==0)){
			if (temp==0){    
				obj.drug_amount+=drug_amount;
				if (drug_price>obj.drug_price)
					obj.drug_price=drug_price;
			    obj.drug_total_price=obj.drug_amount*obj.drug_price;
			    obj.drug_sell_price=(drug_price)+(drug_price/10.0);
			    strcpy(obj.drug_company_name,drug_company_name);
				strcpy(obj.drug_end_date,drug_end_date);   }
			else{
				if (obj.drug_amount>=0){
					obj.drug_amount-=drug_amount;
			        obj.drug_total_price=obj.drug_amount*obj.drug_price;
				}
			}
	        if(obj.drug_amount!=0)
				file_temp.write((char*)&obj,sizeof(Drug));
			check=1;
		}
		else
			file_temp.write((char*)&obj,sizeof(Drug));
	}
	file.close();
	file_temp.close();
	file.open("Drugs.dat" , ios::out );
	file_temp.open("temp.dat" , ios::in );
	while(file_temp.read((char*)&obj,sizeof(Drug)))
		file.write((char*)&obj,sizeof(Drug));
	file.close();
	file_temp.close();
	if (check==1)  return 1;
	else return 0;
}
void Drug::edit_drug(){
	fstream file,file_temp;
	bool check = 0;
	char ch;
	char drug_info [10];
	cout<<"Enter the Drug ID or Drug Name :";  cin>>drug_info;
	file.open("Drugs.dat" , ios::in );
	file_temp.open("temp.dat" , ios::out );
	while(file.read((char*)this,sizeof(Drug))){
		if((!strcmp(drug_info,drug_id))||(!strcmp(drug_info,drug_name))){
			cout<<"The Drug is in the Pharmacy : ";
			cout<<"Drug ID   Drug Name   Drug Amount   Price   Total Price   Company Name   Type of Drug   End Date   \n";
			display_drug();
			cout<<"Note that editing drug information will replace the old one \n";
			cout<<"if you want to update Drug ID enter y : ";    cin>>ch;  
			if ((ch=='y')||(ch=='Y')){
				cout<<"Enter the new Drug ID : ";    cin>>drug_id;   }
			cout<<"if you want to update Drug Name enter y : ";    cin>>ch;  
			if ((ch=='y')||(ch=='Y')){
				cout<<"Enter the new Drug Name : ";      cin>>drug_name;   }
			cout<<"if you want to update Drug Amount enter y : ";    cin>>ch;  
			if ((ch=='y')||(ch=='Y')){
				cout<<"Enter the new Drug Amount : ";    cin>>drug_amount;   }
			cout<<"if you want to update Price enter y : ";    cin>>ch;  
			if ((ch=='y')||(ch=='Y')){
				cout<<"Enter the new Price : ";    cin>>drug_price;   }
			cout<<"if you want to update Company Name enter y : ";    cin>>ch;  
			if ((ch=='y')||(ch=='Y')){
				cout<<"Enter the new Company Name : ";    cin>>drug_company_name;   }
			cout<<"if you want to update Type of Drug enter y : ";    cin>>ch;  
			if ((ch=='y')||(ch=='Y')){
				cout<<"Enter the new Type of Drug : ";   cin>>Type_of_drug;   }
			cout<<"if you want to update End Date enter y : ";    cin>>ch;  
			if ((ch=='y')||(ch=='Y')){
				cout<<"Enter the new End Date : ";    cin>>drug_end_date;   }
		    drug_total_price=drug_amount*drug_price;
		    drug_sell_price=(drug_price)+(drug_price/10.0);
	        file_temp.write((char*)this,sizeof(Drug));    // Ì „ «” Œœ«„ «·„ƒ‘— –” ·Õ›Ÿ «·ﬂÌ«‰«  «·Œ«—Ã… „‰ «·„·›
		    check = 1;
	    }
		else
			file_temp.write((char*)this,sizeof(Drug));
	}
    file.close();
	file_temp.close();
	file.open("Drugs.dat" , ios::out );
	file_temp.open("temp.dat" , ios::in );
	while(file_temp.read((char*)this,sizeof(Drug))){
		file.write((char*)this,sizeof(Drug));
    }
	file.close();
	file_temp.close();
if(check == 0)   cout<<"\n The Drug is not in the Pharmacy \n";
}
bool Drug::search_drug(bool tmp){    //    «–« ﬂ«‰ «·»«—«„ — ÌÕ„· «·ﬁÌ„… ’›— ›Â–« Ì⁄‰Ì »ÕÀ Ê⁄—÷ Ê«·Ê«Õœ »ÕÀ Ê‰”Œ „Õ ÊÌ«  «·ﬂ«∆‰ „‰ «·„·› «·Ï œ«Œ· «·„ƒ‘—
	fstream file;
	Drug obj;
	bool check=0;
	char drug_info [20];
	strcpy(drug_info,drug_name);
	file.open("Drugs.dat" , ios::in );
	if(tmp==0){
		 cout<<"Enter the Drug Name :";  cin>>drug_info;
		cout<<"Drug ID   Drug Name   Drug Amount   Price   Total Price   Company Name   Type of Drug   End Date   \n";
	}
	while(file.read((char*)&obj,sizeof(obj))){
		if(strcmp(drug_info,obj.drug_name)==0){
			obj.display_drug();
			check = 1;
			*this=obj;
			break;
		}
	}
    file.close();
	if(check==0){
		cout<<" The Drug is not found in the Pharmacy : \n";
        return 0;
	}
	else
		return 1;
}
void Drug::display_drug(){
	cout<<drug_id<<"   "<<drug_name<<"   "<<drug_amount<<"   "<<drug_price<<"   "<<drug_sell_price<<"   "<<drug_total_price<<"   "<<drug_company_name<<"   "<<Type_of_drug<<"   "<<drug_end_date<<endl;
}
void Drug::display_drugs(char name[]){    //  «–« ﬂ«‰ «·»«—«„ — ÌÕ„· «·ﬁÌ„… ›—«€ ›Â–« Ì⁄‰Ì ⁄—÷ ﬂ· „Õ ÊÏ «·„·› Ê«·⁄ﬂ” ·⁄—÷ ⁄‰’— „Õœœ  
	fstream file;
	Drug obj;
	file.open("Drugs.dat", ios::in );
	if (strcmp(name," ")==0)  cout<<"Drug ID   Drug Name   Drug Amount   Price   Total Price   Company Name   Type of Drug   End Date   \n";
	else   cout<<"Drug Name   Drug Amount   Price   Total Price   Type of Drug\n";
	while(file.read((char*)&obj,sizeof(obj))){
	  if((!strcmp(name,obj.drug_name)))
		  cout<<drug_name<<"   "<<drug_amount<<"   "<<drug_sell_price<<"   "<<drug_total_price<<"   "<<Type_of_drug<<endl;
	  if(strcmp(name," ")==0){
		  obj.display_drug();
		  //system("pause");
	  }
	}
	file.close();
}
void Drug::delete_drug(char drug_name3 []=" ",char bill_name3 []=" "){
	fstream file,file_temp;
	bool check = 0;
	char drug_info [20];
	strcpy(drug_info,drug_name3);
	if (strcmp(drug_name3," ")==0){
		cout<<"Enter the Drug Name :";  
		cin>>drug_info;
	}
	file.open("Drugs.dat" , ios::in );
	file_temp.open("temp.dat" , ios::out );
	while(file.read((char*)this,sizeof(Drug))){
		if(strcmp(drug_info,drug_name)==0){
			if (strcmp(drug_name3," ")==0){
				cout<<"The Drug is in the Pharmacy : ";
			    cout<<"\nthe Drug ID : "<<drug_id;
		        cout<<"\nthe Drug Name : "<<drug_name;
		        cout<<"\nthe Drug Amount : "<<drug_amount;
		        cout<<"\nthe Price : "<<drug_price; 
			    cout<<"\nthe Total Price : "<<drug_total_price; 
		        cout<<"\nthe Company Name : "<<drug_company_name;
	            cout<<"\nthe Type of Drug : "<<Type_of_drug;
		        cout<<"\nthe End Date : "<<drug_end_date;
			}
			else{
				Drug obj;
				fstream fil;
				fil.open(bill_name3, ios::in);
				while (fil.read((char*)&obj,sizeof(Drug))){
					if(strcmp(drug_info,obj.drug_name)==0){
						if (obj.drug_amount!=drug_amount){
							if (bill_name3[0]=='B'){
							    drug_amount-=obj.drug_amount;
			                    drug_total_price=drug_amount*drug_price;
							}
							else{
								drug_amount+=obj.drug_amount;
			                    drug_total_price=drug_amount*drug_price;
							}
				            file_temp.write((char*)this,sizeof(Drug));
						}
					}
				}
			}
			cout<<"\nDrug has been deleted seccessfully \n";
		    check = 1;
	    }
		else
			file_temp.write((char*)this,sizeof(Drug));
	}
    file.close();
	file_temp.close();
	file.open("Drugs.dat" , ios::out );
	file_temp.open("temp.dat" , ios::in );
	while(file_temp.read((char*)this,sizeof(Drug))){
		file.write((char*)this,sizeof(Drug));
    }
	file.close();
	file_temp.close();
	if(check == 0)   
		cout<<"\n The Drug is not in the Pharmacy \n";
}
double Drug::sell_drug(char bill_name2[]=" "){
	fstream file;
	char ch;
	double amount;
	double total_price=0.0;
	file.open(bill_name2,ios::app );
	//cout<<"Drug ID   Drug Name   Drug Amount   Price   Total Price   Company Name   Type of Drug   End Date   \n";
	do{    
		cout<<"Enter the Drug Name :";  cin>>drug_name;
		if (search_drug(1)==1){
			amount=drug_amount;
			cout<<"Enter the Drug Amount :";      cin>>drug_amount;
			if (drug_amount>amount){   
				cout<<"Drug amount is not enough";
				cout<<"Enter the Drug Amount :";      cin>>drug_amount;
			}
	        cout<<"Enter the Type of Drug :";     cin>>Type_of_drug;
			drug_total_price=drug_amount*drug_sell_price;
			display_drugs(drug_name);     //   ·⁄—÷  ›«’Ì· «·œÊ«¡ Õ«· «·»Ì⁄ 
			total_price+=drug_total_price;
			update_drug(1);
			cout<<"Total price : "<<total_price;
			file.write((char*)this,sizeof(Drug));
		}
		cout<<"\nDo you want to add another Drug [y , n] ?";  cin>>ch;
	}  while((ch=='y')||(ch=='Y'));
	file.close();
	return total_price;
}
double Drug::delete_drug_from_bill(char drug_name4 [],char bill_name4 []){
	fstream file,fil;
	double price=0;
	char name[20];
	strcpy(name,drug_name4);
	if (strcmp(drug_name4," ")==0){
		cout<<"Enter Drug name : ";    
		cin>>name;
	}
	file.open(bill_name4, ios::in);
	fil.open("temp.dat", ios::out);
	while(file.read((char*)this,sizeof(Drug))){
		if (strcmp(name,drug_name)!=0){
			fil.write((char*)this,sizeof(Drug));
		}
		else
			price=drug_total_price;
	}
	file.close();
	fil.close();
	file.open(bill_name4, ios::out);
	fil.open("temp.dat", ios::in);
	while(fil.read((char*)this,sizeof(Drug)))
		file.write((char*)this,sizeof(Drug));
	file.close();
	fil.close();
	return price;
}
void Drug::daily_report(){
	fstream file;
	Buy_Bill bb;
	Sell_Bill sb;
	double price=0,amount=0;
	char bill_name [20];
	char tail [5]=".dat";
	char no [20];  
	cout<<"_______________________________________List of Buying Drugs____________________________________________"; 
	cout<<"\nDrug ID   Drug Name   Drug Amount   Price   Total Price   Company Name   Type of Drug   End Date   \n";
	cout<<"\n________________________________________________________________________________________________\n";
	file.open("Bills.dat",ios::in);
	while(file.read((char*)&bb,sizeof(Buy_Bill))){
		fstream fil;
		strcpy(bill_name,"BBill");
		sprintf(no,"%d",bb.get_bill_number());       
	    strcat(bill_name,no);       
	    strcat(bill_name,tail);
		fil.open(bill_name,ios::in);
		while(fil.read((char*)this,sizeof(Drug))){
			display_drug();
			price+=drug_total_price;
			amount+=drug_amount;
		}
		fil.close();
	}
	cout<<"\n________________________________________________________________________________________________\n";
	cout<<"                        "<<amount<<"                   "<<price<<endl;
	file.close();
	price=amount=0;
	system("pause");    system("cls");
	cout<<"_______________________________________List of Selling Drugs____________________________________________"; 
	cout<<"\nDrug ID   Drug Name   Drug Amount   Price   Total Price   Company Name   Type of Drug   End Date";
	cout<<"\n________________________________________________________________________________________________\n";
	file.open("Sells.dat",ios::in);
	while(file.read((char*)&sb,sizeof(Sell_Bill))){
		fstream fil;
		strcpy(bill_name,"SBill");
		sprintf(no,"%d",sb.get_bill_number());       
	    strcat(bill_name,no);       
	    strcat(bill_name,tail);
		fil.open(bill_name,ios::in);
		while(fil.read((char*)this,sizeof(Drug))){
				display_drug();
				price+=drug_total_price;
			    amount+=drug_amount;
		}
		fil.close();
	}
	cout<<"\n________________________________________________________________________________________________\n";
	cout<<"                        "<<amount<<"                   "<<price<<endl;
}

Drug::~Drug(){  }