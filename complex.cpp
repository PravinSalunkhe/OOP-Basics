/*
PROBLEM STATEMENT::
Operator Overloading
WAP to design a class ‘Complex ‘with data members for real and imaginary
part. Provide default and parameterized constructors. Write a program to
perform arithmetic operations of two complex numbers using operator
overloading.
i. Addition and subtraction using friend functions.
ii. Multiplication and division using member functions.
NAME::Pravin Salunkhe
SE 10
23257
*/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class complex//create class
{
	float real;
	float imag;
public:
	void getdata();//for getting complex no's
	void display();//for displaying complex no's
	complex()
	{
		real=0;
		imag=0;
	}
	complex operator+(complex a);//add complex no's
	complex operator-(complex a);//sub complex  no's
	friend complex operator*(complex a,complex b);//multiply complex no's
	friend complex operator/(complex a,complex b);//divide compelex no's
};

int main()
{
	complex c1,c2,c3;//Declaring Objects
	int ch;
	cout<<"Enter the 1st complex no.\n";
	c1.getdata();
	c1.display();
	cout<<"Enter the 2nd complex no.\n";
	c2.getdata();
	c2.display();
	do
	{
		cout<<"MENU\n 1.ADD\n 2.SUBTRACT\n 3.MULTIPLY\n 4.DIVIDE\n 5.EXIT\n ENTER UR CHOICE::";
		cin>>ch;
		switch(ch)
		{
			case 1:	c3=c1+c2;
				cout<<"Addition is::";
				c3.display();
				break;
			case 2:	c3=c1-c2;
				cout<<"Subtraction is::";
				c3.display();
				break;
			case 3:	c3=c1*c2;
				cout<<"Multiplication is::";
				c3.display();
				break;
			case 4:	c3=c1/c2;
				cout<<"Division is::";
				c3.display();
				break;
		}
	}while(ch!=5);
}
void complex::getdata()
{
	cout<<"Enter real part::";
	cin>>real;
	cout<<"\n";
	cout<<"Enter imaginary part::";
	cin>>imag;
	cout<<"\n-->  ";
}
void complex::display()
{
	cout<<real<<"+("<<imag<<"i)\n";
}
complex complex::operator+(complex a)
{
	complex temp;
	temp.real=real+a.real;//real part of addition
	temp.imag=imag+a.imag;//imaginary part of addition
	return (temp);
}
complex complex::operator-(complex a)
{
	complex temp;
	temp.real=real-a.real;//real part of subtraction
	temp.imag=imag-a.imag;//imaginary part of subtraction
	return (temp);
}
complex operator*(complex a,complex b)
{
	complex temp;
	temp.real=(a.real*b.real)+(a.imag*b.imag*(-1));//real part of multiplication
	temp.imag=(a.real*b.imag)+(a.imag*b.real);//imaginary part of multiplication
	return temp;
}
complex operator/(complex a,complex b)
{
	complex temp;
	temp.real=((a.real*b.real)+(a.imag*b.imag))/(pow(b.real,2)-pow(b.imag,2)*(-1));//real part of division
	temp.imag=((a.real*b.imag*(-1))+(a.imag*b.real))/(pow(b.real,2)-pow(b.imag,2)*(-1));//imaginary part of division
	return temp;
}




/*
OUTPUT


Enter the 1st complex no.
Enter real part::2

Enter imaginary part::3

-->  2+(3i)
Enter the 2nd complex no.
Enter real part::3

Enter imaginary part::-2

-->  3+(-2i)
MENU
 1.ADD
 2.SUBTRACT
 3.MULTIPLY
 4.DIVIDE
 5.EXIT
 ENTER UR CHOICE::1
Addition is::5+(1i)
MENU
 1.ADD
 2.SUBTRACT
 3.MULTIPLY
 4.DIVIDE
 5.EXIT
 ENTER UR CHOICE::2
Subtraction is::-1+(5i)
MENU
 1.ADD
 2.SUBTRACT
 3.MULTIPLY
 4.DIVIDE
 5.EXIT
 ENTER UR CHOICE::3
Multiplication is::12+(5i)
MENU
 1.ADD
 2.SUBTRACT
 3.MULTIPLY
 4.DIVIDE
 5.EXIT
 ENTER UR CHOICE::4
Division is::0+(13i)
MENU
 1.ADD
 2.SUBTRACT
 3.MULTIPLY
 4.DIVIDE
 5.EXIT
 ENTER UR CHOICE::5
a3-402-18@a340218-OptiPlex-3010:~/23257$ 
*/

