/*
SE-10
PRAVIN SALUNKHE
23257
PROBLEM STATEMENT:-
Create employee bio-data using following classes
i.Personal record
ii.Professional record
iii.Academic record
Assume appropriate data members and member function to accept required
data & print bio-data. Create bio-data using multiple inheritance using C++.
*/
#include<iostream>
#include<string.h>
using namespace std;

class personal//base class 1
{
protected:
	char name[20];
	char dob[15];
 	long long int mobno;
public:
	void getdata();
	void display();
};
void personal::getdata()
{
	cout<<"\nEnter the Name::";
	cin.getline(name,20);
	cout<<"\nEnter the date of birth::";
	cin.getline(dob,15);
	cout<<"\nEnter the mobile no.::";
	cin>>mobno;
};
void personal::display()
{
	cout<<"\nNAME::"<<name<<"\n\nDATE OF BIRTH::"<<dob<<"\nMOBILE NO.::"<<mobno;
}		   
class professional//base class 2
{
protected:
	int exp;
	char company[20];
public:
	void  getdata();
	void display();
};
void professional::getdata()
{
	cout<<"\nEnter the past experience(IN YEARS)::";
	cin>>exp;
	cout<<"\nEnter the previous company name::";
	cin.ignore();
	cin.getline(company,20);
}
void professional::display()
{
	cout<<"\nPAST EXPEREINCE::"<<exp<<"\nPREVIOUS COMPANY::"<<company;
}		
class academic//base class 3
{
protected:
	float hsc;
	float ssc;
	float engg;
public:
	void getdata();
	void display();
};
void academic::display()
{
	cout<<"\nSSC PERCENTAGE::"<<ssc<<"\nHSC PERCENTAGE::"<<hsc<<"\nENGINEERING PERCENTAGE(AGGREGATE)::"<<engg<<"\n";
}
void academic::getdata()
{
	cout<<"\nEnter the SSC Percntage::";
	cin>>ssc;
	cout<<"\nEnter the HSC Percetage::";
	cin>>hsc;
	cout<<"\nEnter the ENGIEERING Percentage::";
	cin>>engg;
}		
class employee: public personal,public professional,public academic//derived class
{
public:
	void getdata();
	void display();
};
void employee::getdata()
{	//calling base class functions from derived class
	personal::getdata();
	professional::getdata();
	academic::getdata();
}
void employee::display()
{	//calling base class functions from derived class
	personal::display();
	professional::display();
	academic::display();
}

int main()
{
	int ch,i,n;
	employee *e[10];
	cout<<"\n EMPLOYEE BIO-DATA";
	cout<<"\n Enter no.of emloyees::";//getting no. of employees
	cin>>n;
	
	do
	{
		cout<<"\nMENU\n1.INSERT DATA\n2.DISPLAY DATA\n3.EXIT\nENTER UR CHOICE::";
		cin>>ch;
		switch(ch)
		{
			case 1:
				for(i=0;i<n;i++)
				{
					cout<<"ENTER THE DETAILS OF EMPLOYEE "<<i+1<<"\n";
					e[i]=new employee;
					cin.ignore();
					e[i]->getdata();
		
				}	
				break;
			case 2: 
				cout<<"\n EMPLOYEE BIO-DATA";
				for(i=0;i<n;i++)
				{
					e[i]->display();
					
				}	
				break;
			case 3: exit(0);
		}			
	}while(ch!=3);
return 0;					
}			 
	
/*
OUTPUT::
admin1@pravin-27:~/se10/oopl$ ./a.out

 EMPLOYEE BIO-DATA
 Enter no.of emloyees::2

MENU
1.INSERT DATA
2.DISPLAY DATA
3.EXIT
ENTER UR CHOICE::1
ENTER THE DETAILS OF EMPLOYEE 1

Enter the Name::YASH GHARAT

Enter the date of birth::27-08-1999

Enter the mobile no.::8765432152

Enter the past experience(IN YEARS)::3

Enter the previous company name::ALFALAVAL

Enter the SSC Percntage::67.65

Enter the HSC Percetage::65.44

Enter the ENGIEERING Percentage::56.76
ENTER THE DETAILS OF EMPLOYEE 2

Enter the Name::SAGAR CHAUDHARI

Enter the date of birth::09-09-1997

Enter the mobile no.::7643218732 

Enter the past experience(IN YEARS)::6

Enter the previous company name::RAUTEN 

Enter the SSC Percntage::87.32

Enter the HSC Percetage::87.43

Enter the ENGIEERING Percentage::67.90

MENU
1.INSERT DATA
2.DISPLAY DATA
3.EXIT
ENTER UR CHOICE::2

NAME::YASH GHARAT

DATE OF BIRTH::27-08-1999
MOBILE NO.::8765432152
PAST EXPEREINCE::3
PREVIOUS COMPANY::ALFALAVAL
SSC PERCENTAGE::67.65
HSC PERCENTAGE::65.44
ENGINEERING PERCENTAGE(AGGREGATE)::56.76

NAME::SAGAR CHAUDHARI

DATE OF BIRTH::09-09-1997
MOBILE NO.::7643218732
PAST EXPEREINCE::6
PREVIOUS COMPANY::RAUTEN
SSC PERCENTAGE::87.32
HSC PERCENTAGE::87.43
ENGINEERING PERCENTAGE(AGGREGATE)::67.9
MENU
1.INSERT DATA
2.DISPLAY DATA
3.EXIT
ENTER UR CHOICE::3
*/		
