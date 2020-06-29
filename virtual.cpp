/*
PRAVIN SALUNKHE
SE-10
G-10
23257
PROBLEM STATEMENT:-
Create a base class shape with two double type values and member functions to
input the data and compute_area() for calculating area of figure.
Derive two classes’ triangle and rectangle. Make compute_area() as a virtual
function and redefine this function in the derived class to suit their requirements.
Write a program that accepts dimensions of triangle/rectangle and display
calculated area.
*/
#include<iostream>
#include<string.h>
using namespace std;

class shape//abstract base class
{
	public:
			virtual void getdata()=0;//declaring pure virtual function
			virtual double compute_area()=0;//declaring pure virtual function
};

class rectangle:public shape//public derivation of derived class
{
		double length;
		double breadth;
	public:
		void getdata()//getting data of rectangle
		{
			cout<<"\nENTER THE LENGTH OF RECTANGLE::";
			cin>>length;
			cout<<"\nENTER THE BREADTH OF RECTANGLE::";
			cin>>breadth;
		}	
		double compute_area()//calculating area of rectangle
		{
			return (length*breadth);
		}	
};
class triangle:public shape//public derivation of triangle
{
		double base;
		double height;
	public:
		void getdata()//getting data of triangle
		{
			cout<<"\nENTER THE LENGTH OF BASE OF TRIANGLE::";
			cin>>base;
			cout<<"\nENTER THE LENGTH OF HEIGHT OF TRIANGLE::";
			cin>>height;
		}		
		double compute_area()
		{
			return(0.5*base*height);
		}
};				
		
int main()
{
	cout<<"\nAREA OF SHAPES";	
	shape *bp;//declaring base class pointer
	rectangle r;//object of derived class rectangle
	triangle t;//object of derived class triangle
	int ch;
	double area;
	do{
		cout<<"\nMENU\n1.AREA OF TRIANGLE\n2.AREA OF RECTANGLE\n3.EXIT\n->ENTER UR CHOICE::";
		cin>>ch;
		switch(ch)
		{
		case 1:
				bp=&t;//pointer points to object of triangle
				bp->getdata();
				area=bp->compute_area();//calling area function of triangle
				cout<<"\nAREA OF TRIANGLE IS ::"<<area;
				break;
		case 2:
				bp=&r;//pointer points to object of rectangle
				bp->getdata();
				area=bp->compute_area();//calling area function of rectangle
				cout<<"\nAREA OF RECTANGLE IS ::"<<area;
				break;			
		case 3:	
				break;					
		}
	}while(ch!=3);			
return 0;
}

/*OUTPUT::

pict@nllab-18:~/23257$ ./a.out

AREA OF SHAPES
MENU
1.AREA OF TRIANGLE
2.AREA OF RECTANGLE
3.EXIT
->ENTER UR CHOICE::1

ENTER THE LENGTH OF BASE OF TRIANGLE::3.5

ENTER THE LENGTH OF HEIGHT OF TRIANGLE::3.1

AREA OF TRIANGLE IS ::5.425
MENU
1.AREA OF TRIANGLE
2.AREA OF RECTANGLE
3.EXIT
->ENTER UR CHOICE::2

ENTER THE LENGTH OF RECTANGLE::2.2

ENTER THE BREADTH OF RECTANGLE::2.4

AREA OF RECTANGLE IS ::5.28
MENU
1.AREA OF TRIANGLE
2.AREA OF RECTANGLE
3.EXIT
->ENTER UR CHOICE::3
pict@nllab-18:~/23257$
*/

