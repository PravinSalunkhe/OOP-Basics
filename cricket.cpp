/*PROBLEM STATEMENT::Create a class CRICKET that holds Name of Player, Century Scored, Runs
Scored, Average, Economy, Wickets, and Catches etc. The constructor
initializes the fields with default values. Include a function that prompts the
user and sets values for each field so that you can override the default values.
Write a program that creates a report for ‘N’ number of Cricketers.
Name::Pravin Salunkhe
Se10
G10
23257*/

#include<iostream>
using namespace std;
class cricket
{
char name_of_player[20];
int century;
double runs;
float average;
float economy;
int wickets;
int catches;
public:
cricket();
void getdata(void);
void display(void);
};
cricket::cricket()
{
century=0;
runs=0;
average=0;
economy=6;
wickets=0;
catches=0;
}
void cricket::getdata(void)
{
cout<<"enter the player name";
cin>>name_of_player;
cout<<"enter the no of centueries";
cin>>century;
cout<<"enter the no of runs";
cin>>runs;
cout<<"enter the average and economy";
cin>>average;
cout<<"\t";
cin>>economy;
cout<<"enter the no of wickets and catches";
cin>>wickets;
cout<<"\t";
cin>>catches;
}
void cricket::display(void)
{
cout<<"\t"<<name_of_player;
cout<<"\t	"<<century;
cout<<"\t	"<<runs;
cout<<"\t	"<<average;
cout<<"\t	"<<economy;
cout<<"\t	"<<wickets;
cout<<"\t	"<<catches;
}
int main()
{
int ch,i,d,n;

cricket c[50];
 cout<<"\n CRICKET STATASTICS\n";
       do
       {
         cout<<"\n MAIN MENU";
         cout<<"\n 1.ENTER THE DATA";
         cout<<"\n 2.DISPLAY STATISTICS";
         cout<<"\n 3.EXIT";
         cout<<"\n   ENTER YOUR CHOICE";
         cin>>ch ;
         switch (ch)
         {
          case 1:
		cout<<"Enter the no. of players data u want to update";
		cin>>n;
		for(i=0;i<n;i++)
                        {
                         cout<<"\n";
                         c[i].getdata();
                        }
                 break;
          case 2:
cout<<"\nSr No.\tNAME OF PLAYER\t	CENTURY\t	RUNS\t	AVERAGE\t	ECONOMY\t	WICKETS\t	CATCHES";
                 cout<<"\n";
                 for(i=0;i<n;i++)
                        {
                         cout<<"\n"<<i+1;
                         cout<<"\t";
                         c[i].display();
                        }
                 break;
         case 3: break;
        }
       }while(ch!=3);
return 0;
}
/*
admin1@pravin-27:~/se10/oopl$ ./a.out

 CRICKET STATASTICS

 MAIN MENU
 1.ENTER THE DATA
 2.DISPLAY STATISTICS
 3.EXIT
   ENTER YOUR CHOICE1
Enter the no. of players data u want to update3

enter the player nameSachin
enter the no of centueries100
enter the no of runs2344
enter the average and economy45.5
	3.4
enter the no of wickets and catches23
	222

enter the player nameDravid
enter the no of centueries23
enter the no of runs2222
enter the average and economy56.6
	45.5
enter the no of wickets and catches34
	333

enter the player nameDhoni
enter the no of centueries23
enter the no of runs555
enter the average and economy34
	33
enter the no of wickets and catches34
	450

 MAIN MENU
 1.ENTER THE DATA
 2.DISPLAY STATISTICS
 3.EXIT
   ENTER YOUR CHOICE2

Sr No.	NAME OF PLAYER		CENTURY		RUNS		AVERAGE		ECONOMY		WICKETS		CATCHES

1		Sachin		100		2344		45.5		3.4		23		222
2		Dravid		23		2222		56.6		45.5		34		333
3		Dhoni		23		555		34		33		34		450
 MAIN MENU
 1.ENTER THE DATA
 2.DISPLAY STATISTICS
 3.EXIT
   ENTER YOUR CHOICE3
admin1@pravin-27:~/se10/oopl$ 
*/


