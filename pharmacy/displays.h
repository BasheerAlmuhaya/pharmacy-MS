#ifndef __DISPLAYS__H__INCLUDED__
#define __DISPLAYS__H__INCLUDED__
#include "Customer.h"
#include "Buy_Bill.h"
#include "Drug.h"
#include "Sell_Bill.h"
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include<string>
//#include<Windows.h>
//#include"banking.h"
//#include"display.h"
using namespace std;

void gotoxy(int x,int y){
	COORD coord;coord.X=x;coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);}

void setColor(int ForgC, int BackC = 15) {
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

int input_all,input_store,input_buy,input_sell,input_cos,input_cos_t;
int	sel_all=0,sel_store=0,sel_buy=0,sel_sell=0,sel_costum=0,sel_costum_trans=0;
int size_all=5,size_store=8,size_buy=7,size_sell=7,size_costum=8,size_costum_trans=7;
    string m_all[5] = { "Store", "Buy Bills", "Sell Bills", "Customers", "Quit" };
	string m_store[8]={"Add Drugs","display Drugs","search a Drug","edit a Drug","delete a Drug",
		"daily report","Return","Quit"};
	string m_buy[7] ={"Add a Bill","display Bills","search a Bill","edit a Bill","delete a Bill","Return","Quit"};
	string m_sell[7]={"Add a Bill","display Bills","search a Bill","edit a Bill","delete a Bill","Return","Quit"};
	string m_costum[8] = {"Add a Customer","display Customer","search a Customer",
		"edit a Customer","delete a Customer","transection a Customer","Return","Quit"};
	string m_costum_trans[7] ={"Add a Bill","display list of buys","display Bills","delete a Bill","Return",
		"Return to Main Menu","Quit" };
//===========================================================
//  THIS CLASS CONTAINS FUNCTIONS RELATED TO DRAW BOX ETC.
//===========================================================

void firstF(int c=5){
	char x = ' ';
	system("cls");
	system("color f0");
	setColor(c,c);
	gotoxy(0,0);
	for (int i = 0; i < 40; i++)cout << x;
	for (int i = 0; i < 25; i++){
		gotoxy(0, i);cout << x;}
	for (int i = 0; i < 25; i++){
		gotoxy(40, i);cout << x;}
	gotoxy(0, 25);
    for (int i = 0; i < 41; i++)cout << x;
	cout << endl;
}
//------------------------------------
void makeBackG(int x1, int y1,int x2,int y2, int c){ 
	setColor(c, c); gotoxy(x1, y1); 
	for (int j = y1; j <= y2; j++) 
		for (int i = x1; i <= x2; i++){ gotoxy(i, j);
cout <<" "; } }
//--------------------------------------
void format(int c=15){
	gotoxy(1, 1);
	setColor(c,c);
	for (int j = 1; j < 26; j++){
		for (int i = 0; i < 39; i++)
			cout <<" ";
		gotoxy(1, j);}
	}
//--------------------------------------
void printm(string m[],int size,int sel){
	int j = 8;//format();
	makeBackG(10,1,31,3,6);
	setColor(15,6);gotoxy(11, 2);
	cout << "PHARMACY MANAGEMENT";
	gotoxy(12,5);setColor(2);//cout<<"DATE:"<<__DATE__;
for (int i = 0; i < size; i++){
		setColor(0);
		gotoxy(15, j=j+2);
		if (sel == i)
		{setColor(15, 1);gotoxy(12,j);cout<<"-> ";}
		cout << m[i];}
	gotoxy(1, 27);
}
//-------------------------------------
void loading(){  
	format();
	gotoxy(14, 10); setColor(0);
	cout<<"Loading... \n";
	gotoxy(10, 13);
	setColor(7);
	for (int i = 0; i < 20; i++){cout << char(177);}//177 ÊØÈÚ ÝÑÇÛ ÇÈíÖ ÊÍÊ ÇáÇäÊÙÇÑ íãÑ ÏÇÎáå ÇáÎØ ÇáÇÎÖÑ
	for (int i = 0; i <= 20; i++){
		setColor(2,2);
		gotoxy(i+10, 13);
		Sleep(100);
		cout << " ";
		gotoxy(24, 10);
		setColor(4);
		cout << i * 5 << " %";}
	gotoxy(1, 27);
 }
//--------------------------------------
bool show(int x,int y){
		int in;int passlen=15,length=15;char passw[]="asd",input[15];int color=15;
		gotoxy(x,y);setColor(color, color);
		for (int i = 0; i < length; i++)cout << " ";
		gotoxy(x,y);setColor(0, color);int i;
		for (i = 0; i < passlen; i++){
			in = _getch();
			if (in == 13) break;
			cout << "*";input[i] =(char)in;
		}input[i]=NULL;
		if(strcmp(input,passw)==0){cout<<"true";getch();return 1;}else{ cout<<"false";getch();return 0;}
	}
void showpassword(){
	a:format(8);gotoxy(2, 7);setColor(0, 8);
	cout << "Enter Password name : ";
	int b=show(23,7);
	while(!b)goto a;
	
}
//--------------------------------------
void Main(){
	Drug d;
	Buy_Bill b;
	Customer c;
	Sell_Bill s;
	go_all:format();input_all=2;
	printm(m_all,size_all,sel_all);
	gotoxy(1, 27);
//---------------------------------
while (input_all != 13){
		input_all = _getch();
		gotoxy(1, 27);
		switch (input_all){
		case 80:if (sel_all==size_all-1)sel_all=-1;sel_all++;format();printm(m_all,size_all,sel_all);break;
		case 72:if (sel_all== 0) sel_all=size_all;sel_all--;format();printm(m_all,size_all,sel_all); break;}}
//;;;;;;;;;;;;;;;;;;;;;;;;;;
switch (sel_all){
case 0:{go_store:input_store=2;format();printm(m_store,size_store,sel_store);gotoxy(1, 27);//---------------------------------
	while (input_store != 13){
		input_store = _getch();gotoxy(1, 27);
		switch (input_store){
		case 80:if (sel_store== size_store-1) sel_store= -1;sel_store++;format();printm(m_store,size_store,sel_store); break;
		case 72:if (sel_store== 0) sel_store=size_store;sel_store--;format();printm(m_store,size_store,sel_store); break;}}
	switch(sel_store){
	case 0:system("cls");system("color 30");d.add_drug(" ");break;
	case 1:system("cls");system("color 30");d.display_drugs(" ");break;
	case 2:system("cls");system("color 30");d.search_drug(0);break;
	case 3:system("cls");system("color 30");d.edit_drug();break;
	case 4:system("cls");system("color 30");d.delete_drug(" "," ");break;
	case 5:system("cls");system("color 30");d.daily_report();break;
	case 6:goto go_all;
	case 7:exit(0); break;
	}getch();firstF();goto go_store; break;}
case 1:{go_buy:input_buy=2;format();printm(m_buy,size_buy,sel_buy);gotoxy(1, 27);//---------------------------------
	while (input_buy != 13){
		input_buy = _getch();gotoxy(1, 27);
		switch (input_buy){
		case 80:if (sel_buy== size_buy-1) sel_buy= -1;sel_buy++;format();printm(m_buy,size_buy,sel_buy); break;
		case 72:if (sel_buy== 0) sel_buy=size_buy;sel_buy--;format();printm(m_buy,size_buy,sel_buy); break;}}
	switch(sel_buy){
	case 0:system("cls");system("color 30");b.add_bill(); break;
	case 1:system("cls");system("color 30");b.display_bills(); break;
	case 2:system("cls");system("color 30");b.search_bill(); break;
	case 3:system("cls");system("color 30");b.update_bill(); break;
	case 4:system("cls");system("color 30");b.delete_bill(); break;
	case 5:goto go_all;
	case 6:exit(0); break;
	}getch();firstF();goto go_buy; break;}
case 2:{go_sell:input_sell=2;format();printm(m_sell,size_sell,sel_sell);gotoxy(1, 27);//---------------------------------
	while (input_sell != 13){
		input_sell = _getch();gotoxy(1, 27);
		switch (input_sell){
		case 80:if (sel_sell== size_sell-1) sel_sell= -1;sel_sell++;format();printm(m_sell,size_sell,sel_sell); break;
		case 72:if (sel_sell== 0) sel_sell=size_sell;sel_sell--;format();printm(m_sell,size_sell,sel_sell); break;}}
	switch(sel_sell){
	case 0:system("cls");system("color 30");s.add_bill(0); break;
	case 1:system("cls");system("color 30");s.display_bills(); break;
	case 2:system("cls");system("color 30");s.search_bill(0); break;
	case 3:system("cls");system("color 30");s.update_bill(); break;
	case 4:system("cls");system("color 30");s.delete_bill(" ",0); break;
	case 5:goto go_all;
	case 6:exit(0); break;
	}getch();firstF();goto go_sell;break;}
case 3:{go_costum:input_cos=2;format();printm(m_costum,size_costum,sel_costum);gotoxy(1, 27);//---------------------------------
	while (input_cos != 13){
		input_cos = _getch();gotoxy(1, 27);
		switch (input_cos){
		case 80:if (sel_costum== size_costum-1) sel_costum= -1;sel_costum++;format();printm(m_costum,size_costum,sel_costum); break;
		case 72:if (sel_costum== 0) sel_costum=size_costum;sel_costum--;format();printm(m_costum,size_costum,sel_costum); break;}} 
	switch(sel_costum){
	case 0:system("cls");system("color 30");c.add_customer(); break;
	case 1:system("cls");system("color 30");c.display_customers(); break;
	case 2:system("cls");system("color 30");c.search_customer(0); break;
	case 3:system("cls");system("color 30");c.update_customer(0); break;
	case 4:system("cls");system("color 30");c.delete_customer(); break;
	case 5:{go_costum_trans:input_cos_t=2;format();printm(m_costum_trans,size_costum_trans,sel_costum_trans);gotoxy(1, 27);//---------------------------------
		while (input_cos_t != 13){
		input_cos_t = _getch();gotoxy(1, 27);
		switch (input_cos_t){
		case 80:if (sel_costum_trans== size_costum_trans-1) sel_costum_trans= -1;
			sel_costum_trans++;format();printm(m_costum_trans,size_costum_trans,sel_costum_trans); break;
		case 72:if (sel_costum_trans== 0) sel_costum_trans=size_costum_trans;
			sel_costum_trans--;format();printm(m_costum_trans,size_costum_trans,sel_costum_trans); break;}} 
		switch(sel_costum_trans){
		case 0:system("cls");system("color 30");c.add_bill(); break;
		case 1:system("cls");system("color 30");c.display_customer_bills(); break;   
		case 2:system("cls");system("color 30");c.display_customer_buy_list(); break;
		case 3:system("cls");system("color 30");c.delete_bill(); break;
		case 4:goto go_costum;
		case 5:goto go_all;
		case 6:exit(0); break;
		}getch();firstF();goto go_costum_trans; break;}
	case 6:goto go_all;
	case 7:exit(0); break;
	}getch();firstF();goto go_costum;break;}
case 4:exit(0); break;
}
}

class display
{
   public :
	    void line_hor(int, int, int, char,int n=10);
	    void line_ver(int, int, int, char,int n=10);
	    void box(int,int,int,int,char,int n=10);
};
//===========================================================
//     FUNCTION TO DRAW HORIZONTAL LINE
//===========================================================
 
void display::line_hor(int column1,int column2,int row,char c,int n)
{
	if(column1<column2){for(column1;column1<=column2;column1++){
	 Sleep(n);gotoxy(column1,row);cout<<c;}}
else {for(column1;column1>=column2;column1--){
		Sleep(n);gotoxy(column1,row);cout<<c;}}
}
 
//===========================================================
//             FUNCTION TO DRAW VERTICAL LINE
//===========================================================
 
void display::line_ver(int row1,int row2,int column,char c,int n)
{
if(row1<row2){for(row1;row1<=row2;row1++){
		Sleep(n);gotoxy(column,row1);cout<<c;}}
else {for(row1;row1>=row2;row1--){
		Sleep(n);gotoxy(column,row1);cout<<c;}}

}
 
//============================================================
//              FUNCTION TO DRAW BOX LINE
//============================================================
 
void display::box(int column1,int row1,int column2,int row2,char c,int n)
{
char ch=218;  char c1,c2,c3,c4;   char l1=196,l2=179;
if(c==ch){
c1=218;c2=191;c3=192;c4=217;l1=196;l2=179;
}
else{
c1=c;c2=c;c3=c;c4=c;l1=c;l2=c;
}
gotoxy(column1,row1);cout<<c1;
gotoxy(column2,row1);cout<<c2;
gotoxy(column1,row2);cout<<c3;
gotoxy(column2,row2);cout<<c4;
column1++;column2--;
line_hor(column1,column2,row1,l1,n);
//line_hor(column1,column2,row2,l1,n);
column1--;column2++;
row1++;row2--;
line_ver(row1,row2,column2,l2,n);
row1--;row2++;
column1++;column2--;
line_hor(column2,column1,row2,l1,n);
column1--;column2++;
row1++;row2--;
line_ver(row2,row1,column1,l2,n);
}
#endif 
 
