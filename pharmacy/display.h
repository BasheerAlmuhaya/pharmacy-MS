#include<iostream>
#include<fstream>
#include<Windows.h>
//#include<Windows.h>
//#include"banking.h"
//#include"display.h"
using namespace std;
//===========================================================
//  THIS CLASS CONTAINS FUNCTIONS RELATED TO DRAW BOX ETC.
//===========================================================
void gotoxy(int x,int y){
	COORD coord;coord.X=x;coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);}

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
 for(column1;column1<=column2;column1++)
    {
		Sleep(n);
    gotoxy(column1,row);
    cout<<c;
    }
}
 
//===========================================================
//             FUNCTION TO DRAW VERTICAL LINE
//===========================================================
 
void display::line_ver(int row1,int row2,int column,char c,int n)
{
for(row1;row1<=row2;row1++)
   {
		Sleep(n);
    gotoxy(column,row1);
    cout<<c;
   }
}
 
//============================================================
//              FUNCTION TO DRAW BOX LINE
//============================================================
 
void display::box(int column1,int row1,int column2,int row2,char c,int n)
{
char ch=218;
char c1,c2,c3,c4;
char l1=196,l2=179;
if(c==ch)
{
c1=218;
c2=191;
c3=192;
c4=217;
l1=196;
l2=179;
}
else
{
c1=c;
c2=c;
c3=c;
c4=c;
l1=c;
l2=c;
}
gotoxy(column1,row1);
cout<<c1;
gotoxy(column2,row1);
cout<<c2;
gotoxy(column1,row2);
cout<<c3;
gotoxy(column2,row2);
cout<<c4;
column1++;
column2--;
line_hor(column1,column2,row1,l1,n);
line_hor(column1,column2,row2,l1,n);
column1--;
column2++;
row1++;
row2--;
line_ver(row1,row2,column1,l2,n);
line_ver(row1,row2,column2,l2,n);
}
 
