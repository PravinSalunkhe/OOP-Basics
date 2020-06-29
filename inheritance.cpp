/*PROBLEM STATEMENT:
Design a base class with name, date of birth, blood group and another base class
consisting of the data members such as height and weight.
Design one more base class consisting of the insurance policy number and contact
address. The derived class contains the data members’ telephone numbers and
driving license number.
Write a menu driven program to carry out the following things:
i.Build a master table
ii.Display Record
iii.Insert a record
iv.Delete record
v.Edit record
vi.Search for a record

NAME-PRAVIN SALUNKHE
SE 10
23257
*/

#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class customer
{
	char name[20];
	char dob[15];
	char bgrp[15];
public:
	void getdata();
	void displaycus();	
	int search(char a[20],int count);
};
void customer::getdata()
{
	
	cout<<"\nEnter the name::";
	cin.getline(name,20);
	cout<<"Enter the Date of Birth(D-M-Y)::";
	cin.getline(dob,15);
	cout<<"Enter the blood grp::";
	cin.getline(bgrp,15);
}
void customer::displaycus()
{
	cout<<"|"<<setw(14)<<name<<"|"<<setw(14)<<dob<<"|"<<setw(14)<<bgrp;

}	
int customer :: search(char a[20],int count)
{
	int f1=0;
	if(strcmp(a,name)==0)
	{
		f1=1;
	}
	return f1;
}
class physical
{
	float height;
	float weight;
public:
	void getheight();
	void getweight();
	void displayphy();	
};
void physical :: getheight()
	{	
		cout<<"Enter the Height(in cm)::";
		cin>>height;
	}
void physical :: getweight()
	{
		cout<<"Enter the Weight(in kg)::";
		cin>>weight;
	}
void physical::displayphy()
{
	cout<<"|"<<setw(14)<<height<<"|"<<setw(14)<<weight;
}	
class policy
{
	int policyno;
	char *address;
	
public:
	policy()
	{
	address=new char[50];
	}
	~policy()
	{
	delete []address;
	}
	void getp();
	void geta();
	void displaypol();		
};
void policy :: getp()
	{
		cout<<"Enter the policy no.-";
		cin>>policyno;
	}
void policy :: geta()
	{
		cout<<"Enter the address::";
		cin.ignore();
		cin.getline(address,50);
	}
void policy::displaypol()
{
	cout<<"|"<<setw(24)<<policyno<<"|"<<setw(24)<<address;
}
class number : public customer,public physical,public policy
{
	long long int  telno;
	long long int license;
public:
	void gettel();
	void getlicense();
	void display();
};
	void number :: gettel()
	{
		getdata();
		getheight();
		getweight();
		getp();
		geta();
		cout<<"Enter the telephone no.::";
		cin>>telno;		
	}
	void number :: getlicense()
	{	

		cout<<"Enter the license no.::";
		cin>>license;
		
	}
	void number::display()
	{
		displaycus();
		displayphy();
		displaypol();
		cout<<"|"<<setw(14)<<telno<<"|"<<setw(14)<<license<<"\n";
	}
int main()
{
	static int count=0;
	number n[50];
	int ch,i=0,j,k,flag=0;
	char a[20];
	cout<<"DATABASE\n";
	do
	{
		cout<<"MENU\n1.INSERT A RECORD\n2.DISPLAY DATABASE\n3.EDIT A RECORD\n4.DELETE A RECORD\n5.SEARCH A RECORD\n6.EXIT\nENTER UR CHOICE::";
		cin>>ch;
	switch(ch)
	{
		case 1:
				
				cin.ignore();
				n[count].gettel();
				n[count].getlicense();
				++count;		
				break;
		case 2:		cout<<"\n"<<setw(15)<<setiosflags(ios::left)<<"|NAME"<<setw(15)<<"|DATE OF BIRTH"<<setw(15)<<"|BLOOD GROUP"<<setw(15)<<"|HEIGHT(cm)"<<setw(15)<<"|WEIGHT(kg)"<<setw(25)<<"|INSURANCE POLICY NO."<<setw(25)<<"|ADDRESS"<<setw(15)<<"|TELEPHONE NO."<<setw(15)<<"|LICENSE NO.\n";
				
					j=0;
					while(j<count)
				{
					cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------\n";
					
					n[j].display();
					j++;
				}
				break;
		case 3:		
				cout<<"Enter the name of the customer whose details are to be edited:";
				cin.ignore();
				cin.getline(a,20);
				for(j=0;j<count;j++)
				{
					flag=n[j].search(a,count);
					if(flag==1)
					{
						n[j].gettel();
						n[j].getlicense();
						cout<<"\nRecord Modified successfully\n";
						break;
					}
				}
					if(flag==0)
					{
						cout<<"RECORD NOT FOUND\n";
	
					}				
				 
				break;
		case 4:		
				cout<<"Enter the Name of the customer whose details are to be deleted";
				cin.ignore();
				cin.getline(a,20);
				for(j=0;j<count;j++)
				{
					flag=n[j].search(a,count);
					if(flag==1)
						{
							for(k=j;k<count;k++)
							{
								n[k]=n[k+1];	
							}
							count=count-1;
							cout<<"RECORD DELETED SUCCESSFULLY\n";	
							break;
						}
						
				}
				if(flag==0)
					{
						cout<<"RECORD TO BE DELETED NOT FOUND\n";
					}
														


				break;
		case 5:		cout<<"Enter the name of the customer whose details are to be searched:-";
				cin.ignore();
				cin.getline(a,20);
				for(j=0;j<count;j++)
				{
					flag=n[j].search(a,count);
					if(flag==1)
					{
						cout<<"RECORD FOUND\n";
						cout<<"Record Details::\n";
						cout<<"\n"<<setw(15)<<setiosflags(ios::left)<<"|NAME"<<setw(15)<<"|DATE OF BIRTH"<<setw(15)<<"|BLOOD GROUP"<<setw(15)<<"|HEIGHT(cm)"<<setw(15)<<"|WEIGHT(kg)"<<setw(25)<<"|INSURANCE POLICY NO."<<setw(25)<<"|ADDRESS"<<setw(15)<<"|TELEPHONE NO."<<setw(15)<<"|LICENSE NO.\n";
						n[j].display();
						
						break;
					}
				}
				if(flag==0)
				{
					cout<<"RECORD NOT FOUND\n";

				}
				break;
		case 6: break;		
		default : cout<<"PLEASE ENTER A VALID OPTION\n";
			  break;				
				 
				
	}
	}while(ch!=6);
return 0;
}		
			
/*OUTPUT:-

DATABASE
MENU
1.INSERT A RECORD
2.DISPLAY DATABASE
3.EDIT A RECORD
4.DELETE A RECORD
5.SEARCH A RECORD
6.EXIT
ENTER UR CHOICE::1

Enter the name::Pravin Salve
Enter the Date of Birth(D-M-Y)::4-4-2000
Enter the blood grp::a+
Enter the Height(in cm)::145
Enter the Weight(in kg)::111
Enter the policy no.-23
Enter the address::rahatani,pune-17
Enter the telephone no.::7687443334
Enter the license no.::23112233445
MENU
1.INSERT A RECORD
2.DISPLAY DATABASE
3.EDIT A RECORD
4.DELETE A RECORD
5.SEARCH A RECORD
6.EXIT
ENTER UR CHOICE::1

Enter the name::Yash Kode
Enter the Date of Birth(D-M-Y)::5-9-2009
Enter the blood grp::b-
Enter the Height(in cm)::156
Enter the Weight(in kg)::200
Enter the policy no.-44
Enter the address::phaltan,satara
Enter the telephone no.::4567331122
Enter the license no.::45674532123
MENU
1.INSERT A RECORD
2.DISPLAY DATABASE
3.EDIT A RECORD
4.DELETE A RECORD
5.SEARCH A RECORD
6.EXIT
ENTER UR CHOICE::2

|NAME            |DATE OF BIRTH     |BLOOD GROUP     |HEIGHT(cm)     |WEIGHT(kg)     |INSURANCE POLICY NO.  |ADDRESS     |TELEPHONE NO.     |LICENSE NO.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|Pravin Salve               |4-4-2000                 |a+               |145              |111              |23                  |rahatani,pune-17           |7687443334           |23112233445
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|Yash Kode               |5-9-2009                 |b-               |156              |200              |44                  |phaltan,satara           |4567331122           |45674532123
MENU
1.INSERT A RECORD
2.DISPLAY DATABASE
3.EDIT A RECORD
4.DELETE A RECORD
5.SEARCH A RECORD
6.EXIT
ENTER UR CHOICE::3
Enter the name of the customer whose details are to be edited:Yash Kode

Enter the name::Sagar Chaudhari
Enter the Date of Birth(D-M-Y)::2-2-1999
Enter the blood grp::a_
Enter the Height(in cm)::333
Enter the Weight(in kg)::46   
Enter the policy no.-12
Enter the address::Sanpada,Mumbai
Enter the telephone no.::5433226654
Enter the license no.::8976543211
MENU
1.INSERT A RECORD
2.DISPLAY DATABASE
3.EDIT A RECORD
4.DELETE A RECORD
5.SEARCH A RECORD
6.EXIT
ENTER UR CHOICE::2

|NAME            |DATE OF BIRTH     |BLOOD GROUP     |HEIGHT(cm)     |WEIGHT(kg)     |INSURANCE POLICY NO.  |ADDRESS     |TELEPHONE NO.     |LICENSE NO.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|Pravin Salve               |4-4-2000                 |a+               |145              |111              |23                  |rahatani,pune-17           |7687443334           |23112233445
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|Sagar Chaudhari               |2-2-1999                 |a_               |333              |46              |12                  |Sanpada,Mumbai           |5433226654           |8976543211
MENU
1.INSERT A RECORD
2.DISPLAY DATABASE
3.EDIT A RECORD
4.DELETE A RECORD
5.SEARCH A RECORD
6.EXIT
ENTER UR CHOICE::4
Enter the Name of the customer whose details are to be deletedSagar Chaudhari
MENU
1.INSERT A RECORD
2.DISPLAY DATABASE
3.EDIT A RECORD
4.DELETE A RECORD
5.SEARCH A RECORD
6.EXIT
ENTER UR CHOICE::2

|NAME            |DATE OF BIRTH     |BLOOD GROUP     |HEIGHT(cm)     |WEIGHT(kg)     |INSURANCE POLICY NO.  |ADDRESS     |TELEPHONE NO.     |LICENSE NO.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
|Pravin Salve               |4-4-2000                 |a+               |145              |111              |23                  |rahatani,pune-17           |7687443334           |23112233445
MENU
1.INSERT A RECORD
2.DISPLAY DATABASE
3.EDIT A RECORD
4.DELETE A RECORD
5.SEARCH A RECORD
6.EXIT
ENTER UR CHOICE::5
Enter the name of the customer whose details are to be searched:Yash
RECORD NOT FOUND
MENU
1.INSERT A RECORD
2.DISPLAY DATABASE
3.EDIT A RECORD
4.DELETE A RECORD
5.SEARCH A RECORD
6.EXIT
ENTER UR CHOICE::5
Enter the name of the customer whose details are to be searched:Pravin Salve
RECORD FOUND
MENU
1.INSERT A RECORD
2.DISPLAY DATABASE
3.EDIT A RECORD
4.DELETE A RECORD
5.SEARCH A RECORD
6.EXIT
ENTER UR CHOICE::6

*/		
			
