/*
PROBLEM STAEMENT::
Write a C++ program to perform String operations using Operator
Overloading
a) "==" String Equality Check
b) "<=" String Copy
c) "<<" Display String ( Using Friend Function )
d) "*" String concatenation (e.g. S1="PICT", S2="SCTR", S3=S1*S2
i.e. s3="PICTSCTR").

ROLL NO-23257
SE10
G10
*/

#include<iostream>
#include<string.h>
using namespace std;

class String
{
	char str[30];
public:
	
	void getstr();
	void display();
	void operator==(String a);
	void operator<=(String a);
	friend ostream& operator<<(ostream&,String&);
	friend String operator*(String a,String b);
}; 
int main()
{
	String s1,s2,s3;
	int ch,c;
	cout<<"Operator overloading in strings\n";
	cout<<"Enter the string 1:";
	s1.getstr();
	s1.display();
	cout<<"Enter the string 2::";
	s2.getstr();
	s2.display();
	do
	{	
		cout<<"MENU\n 1.EQUALITY CHECK\n 2.STRING COPY\n 3.DISPLAY STRING\n 4.STRING CONCATENATION\n 5.EXIT\n ENTER UR CHOICE\t";
		cin>>ch;
		switch(ch)
		{
		case 1:		
			s1==s2;
			break;
		case 2:	
			cout<<"DO u want to copy 1]string 2 to 1 or 2]string 1 to 2  ---->";
			cin>>c;
			switch(c)
			{	
			case 1:		s1<=s2;
					cout<<"String 1 is->";
					s1.display();
					cout<<"String 2 is->";
					s2.display();
					cout<<"\nSTRING COPIED SUCCESSFULLY\n";
					break;
			case 2:		s2<=s1;					
					cout<<"String 2 is->";
					s2.display();
					cout<<"String 1 is->";					
					s1.display();
					cout<<"\nSTRING COPIED SUCCESSFULLY\n";
					break;
			}
			break;
		case 3:	
			cout<<"String 1 is ::"<<s1<<"\n";
			cout<<"String 2 is ::"<<s2<<"\n";
			break;
		case 4:
			s3=s1*s2;
			cout<<"Concatenated String is::";	
			cout<<s3;
			cout<<"\n";
			break;
		}
	}while(ch!=5);
return 0;
}
void String::getstr()
{	
	cin.getline(str,30);
}
void String::display()
{
	cout<<str<<"\n";
}
void String::operator==(String a)
{	
	
	if(strcmp(str,a.str)==0)
	{
		cout<<"\nStrings are equal\n";
	}
	else
	{
		cout<<"\nStrings are not equal\n";
	}
}
void String :: operator<=(String a)
{
	strcpy(str,a.str);
	
}
ostream& operator<<(ostream& myout,String& a)
{
	myout<<a.str;
	return myout;
}
String operator*(String a,String b)
{
	String temp;
	strcat(a.str,b.str);
	strcpy(temp.str,a.str);
	return temp;
}


/*OUTPUT

Operator overloading in strings
Enter the string 1:Golden
Golden
Enter the string 2::Ball
Ball
MENU
 1.EQUALITY CHECK
 2.STRING COPY
 3.DISPLAY STRING
 4.STRING CONCATENATION
 5.EXIT
 ENTER UR CHOICE	1

Strings are not equal
MENU
 1.EQUALITY CHECK
 2.STRING COPY
 3.DISPLAY STRING
 4.STRING CONCATENATION
 5.EXIT
 ENTER UR CHOICE	3
String 1 is ::Golden
String 2 is ::Ball
MENU
 1.EQUALITY CHECK
 2.STRING COPY
 3.DISPLAY STRING
 4.STRING CONCATENATION
 5.EXIT
 ENTER UR CHOICE	4
Concatenated String is::GoldenBall
MENU
 1.EQUALITY CHECK
 2.STRING COPY
 3.DISPLAY STRING
 4.STRING CONCATENATION
 5.EXIT
 ENTER UR CHOICE	2
DO u want to copy 1]string 1 to 2 or 2]string 2 to 1::1
String 1 is->Ball
String 2 is->Ball

STRING COPIED SUCCESSFULLY
MENU
 1.EQUALITY CHECK
 2.STRING COPY
 3.DISPLAY STRING
 4.STRING CONCATENATION
 5.EXIT
 ENTER UR CHOICE	1

Strings are equal
MENU
 1.EQUALITY CHECK
 2.STRING COPY
 3.DISPLAY STRING
 4.STRING CONCATENATION
 5.EXIT
 ENTER UR CHOICE	2
DO u want to copy 1]string 1 to 2 or 2]string 2 to 1::2
String 2 is->Ball
String 1 is->Ball

STRING COPIED SUCCESSFULLY
MENU
 1.EQUALITY CHECK
 2.STRING COPY
 3.DISPLAY STRING
 4.STRING CONCATENATION
 5.EXIT
 ENTER UR CHOICE	5
 */
	
