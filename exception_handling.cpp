/*
PRAVIN SALUNKHE
SE-10
G-10
23257
PROBLEM STATEMENT:-
Write a program in C++ which includes the code for following operations :
i. A function to read two double type numbers from keyboard
ii. A function to calculate the division of these two numbers
iii. A try block to detect and throw an exception if the condition
“divide-by-zero”occurs
iv. Appropriate catch block to handle the exceptions thrown
*/
#include<iostream>
using namespace std;

class division//class definition
{
		double no1;
		double no2;
		double ans;
		
	public:
		void getdata()
		{
				cout<<"\nENTER THE NUMBER 1::";
				cin>>no1;
				cout<<"\nENTER THE NUMBER 2::";
				cin>>no2;
			try
			{
				if(no2==0)
				throw 0;
			}		
			catch(int )
			{
				if(no2==0)
				{
					cout<<"\nCANNOT DIVIDE BY ZERO\nHENCE,DIVISION NOT POSSIBLE\n";
					return;
				}
			}
			ans=(no1/no2);
			cout<<"DIVISION IS :-"<<ans<<"\n";
			return;
		}		
};
int main()
{
	division d;
	char ch;
label1:	d.getdata();
	printf("DO U WANT TO CONTINUE(Y/N):-");
	cin.ignore();
label2:	scanf("%c",&ch);
	if(ch=='Y' || ch=='y')
	{
	goto label1;
	}
	else if(ch=='N'|| ch=='n')
	{
	return 0;
	}
	else
	{
	printf("\nPlease enter a valid choice:-");
	goto label2;
	}
}


/*OUTPUT:-

ENTER THE NUMBER 1::3

ENTER THE NUMBER 2::9
DIVISION IS :-0.333333
DO U WANT TO CONTINUE(Y/N):-Y

ENTER THE NUMBER 1::2

ENTER THE NUMBER 2::0

CANNOT DIVIDE BY ZERO
HENCE,DIVISION NOT POSSIBLE
DO U WANT TO CONTINUE(Y/N):-Y

ENTER THE NUMBER 1::4

ENTER THE NUMBER 2::0

CANNOT DIVIDE BY ZERO
HENCE,DIVISION NOT POSSIBLE
DO U WANT TO CONTINUE(Y/N):-N
admin1@pravin-27:~/se10/oopl$ 
*/	
