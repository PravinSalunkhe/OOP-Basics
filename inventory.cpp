/*
NAME:: Pravin Salunkhe
ROLL NO. 23257
CLASS - SE10
PROBLEM STATEMENT::A Book shop maintains the inventory of books that are being sold at the shop.
The list includes details such as title, author, publisher, price and available
stock.
Write a program in C++ which will have a class called books with suitable
member functions for
i.
Add
ii.
Update
iii.
Search a book
iv.
Purchase a book (update the stock and display the total cost)
v.
Record number of successful/unsuccessful transactions
(use static data members to keep count of transactions)
Use new operator in constructors to allocate memory space required.*/


#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class books  //class creation
{
	char *title;
	char *author;
	char *publisher;
	int price;
	int stock;
	static int success;
	static int fail; 
public:
	books()
	{
		author=new char[30];
		title=new char[30];
		publisher=new char[30];
	}
	~books()
	{
		delete []author;
		delete []title;
		delete []publisher;
	}
	void add(int i);
	int purchase(char a[30],int n);
	int search(char b[30],int n);
	void trans();
	void update();
	void display();
};
int books::success;
int books::fail;
int main()
{
 	static int m;
	int n=0,ch,i,flag=0,p;
	char a[30];
	char z[30];
	books b[50],c;
	cout<<"BOOK INVENTORY\n";
	
	do
	{
		cout<<"\nMENU\n 1.ADD BOOKS\n 2.DISPLAY INVENTORY\n 3.SEARCH A BOOK\n 4.PURCHASE A BOOK\n 5.UPDATE INVENTORY\n 6.SUCCESSFUL/UNSUCCESSFUL TRANSACTIONS\n 7.EXIT\nenter ur choice:-";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter the no of books to add-->\n";
				cin>>n;
				if(m==0)
				{	
					for(i=0;i<n;i++)
					{
						b[i].add(i);
					}
					m=m+n;
				}
				else
				{
					for(i=m;i<m+n;i++)
					{
						b[i].add(i);
					}
					m=m+n;
				}		
				break;
			case 2:	
				cout<<"\n"<<setw(10)<<setiosflags(ios::left)<<"|Sr no."<<setw(15)<<"|TITLE"<<setw(15)<<"|AUTHOR"<<setw(15)<<"|PUBLISHER"<<setw(7)<<"|PRICE"<<setw(7)<<"|STOCK\n";
				
				for(i=0;i<m;i++)
				{
					cout<<"|"<<setw(9)<<setiosflags(ios::left)<<i+1;
					b[i].display();
				}
				break;
			case 3:	cout<<"Enter the title of the book to be searched\n";
				cin.ignore();
				cin.getline(a,50);
				for(i=0;i<m;i++)
				{
			
					flag=b[i].search(a,n);
					if(flag==1)
					break;
					
				}
				if(flag==0)
					{
					cout<<"Sorry,book not found\n";
					}
				break;
			case 4: cout<<"Enter the title of the book to be purchased\n";
				cin.ignore();				
				cin.getline(z,50);
				for(i=0;i<m;i++)
				{
					flag=b[i].purchase(z,n);
					if(flag==1)
					break;

				}
					if(flag==0)
					{
					cout<<"Sorry,book not found\n";
					}				
				break;
			case 5:	cout<<"Enter the sr no. of the book whose stock is to be updated";
				cin>>p;
				b[p-1].update();
				break;
			case 6:
				c.trans();
				break;
			case 7: break;	
		}
	}while(ch!=7);
return 0;
}
void books:: add(int i)
{
	cin.ignore();
	cout<<"enter the title of the book "<<i+1<<"::";
	cin.getline(title,50);
	cout<<"enter the author of the book "<<i+1<<"::";
	cin.getline(author,50);
	cout<<"enter the publisher of the book "<<i+1<<"::";
	cin.getline(publisher,50);
	cout<<"enter the price of the book "<<i+1<<"::";
	cin>>price;
	cout<<"enter the stock of the book "<<i+1<<"::";
	cin>>stock;
}

void books::display()
{	cout<<"|"<<setw(14)<<setiosflags(ios::left)<<title<<"|"<<setw(14)<<author<<"|"<<setw(14)<<publisher<<"|"<<setw(6)<<price<<"|"<<setw(6)<<stock<<"\n";	
}
	
int books::purchase(char b[30],int n)
{
	int m,f1=0;
		if(strcmp(b,title)==0)
		{
			cout<<"Book found\n";
			f1=1;
			cout<<"enter the no of books\n";
			cin>>m;
			while(m<0)
			{
				cout<<"Please enter a valid no of books\n";
				cin>>m;	
			}
			if(m<=stock && m>0)
			{
				cout<<"\nTotal Cost of books is::"<<m*price<<"\n";
				success++;
				stock-=m;
			}
			else
			{
				cout<<"Sorry,we are out of stock";
				fail++;
			}
		}
	return f1;					
}
int books::search(char a[30],int n)
{
	int m,f1=0;
		if(strcmp(a,title)==0)
		{
			cout<<"Book found\n";
			f1=1;			
		}
	return f1;
		
}
void books::trans()
{
	cout<<"NO OF SUCCESSFUL TRANSACTIONS ARE "<<success<<"\n"<<endl;
	cout<<"NO OF UNSUCCESSFUL TRANSACTIONS ARE "<<fail<<"\n"<<endl;
}
void books::update()
{
	int ch;
	cout<<"what do u want to update\n1.TITLE\n2.AUTHOR\n3.PUBLISHER\n4.PRICE\n5.STOCK\n";
	cin>>ch;
	switch(ch)
	{
	case 1: cout<<"Enter the new title of the book";
		cin.getline(title,50);
		break;
	case 2:	cout<<"Enter the new author of the book";
		cin.getline(author,50);
		break;
	case 3:	cout<<"Enter the new publisher of the book";
		cin.getline(publisher,50);
		break;
	case 4:	cout<<"Enter the updated price of the book";
		cin>>price;
		break;
	case 5:	cout<<"Enter the updated stock of the book";
		cin>>stock;
		break;
	}
}
/*OUTPUT :-


BOOK INVENTORY

MENU
 1.ADD BOOKS
 2.DISPLAY INVENTORY
 3.SEARCH A BOOK
 4.PURCHASE A BOOK
 5.UPDATE INVENTORY
 6.SUCCESSFUL/UNSUUCCESSFUL TRANSACTIONS
 7.EXIT
enter ur choice1
Enter the no of books
3
enter the title of the book1::Harry Potter
enter the author of the book1::J K Rowling
enter the publisher of the book1::Royal publications                
enter the price of the book1::400
enter the stock of the book1::43
enter the title of the book2::Oliver Twist
enter the author of the book2::Ollie Pope
enter the publisher of the book2::London publications
enter the price of the book2::500
enter the stock of the book2::23
enter the title of the book3::Wings Of Fire
enter the author of the book3::DR.Apj Kalam
enter the publisher of the book3::Delhi publications
enter the price of the book3::335
enter the stock of the book3::12

MENU
 1.ADD BOOKS
 2.DISPLAY INVENTORY
 3.SEARCH A BOOK
 4.PURCHASE A BOOK
 5.UPDATE INVENTORY
 6.SUCCESSFUL/UNSUUCCESSFUL TRANSACTIONS
 7.EXIT
enter ur choice2

Sr no.	TITLE		AUTHOR		PUBLISHER		PRICE		STOCK
1	Harry Potter		J K Rowling		Royal publications	400		43
2	Oliver Twist		Ollie Pope		London publications	500		23
3	Wings Of Fire		DR.Apj Kalam		Delhi publications	335		12

MENU
 1.ADD BOOKS
 2.DISPLAY INVENTORY
 3.SEARCH A BOOK
 4.PURCHASE A BOOK
 5.UPDATE INVENTORY
 6.SUCCESSFUL/UNSUUCCESSFUL TRANSACTIONS
 7.EXIT
enter ur choice3
Enter the title of the book to be searched
Techmax
Sorry,book not found

MENU
 1.ADD BOOKS
 2.DISPLAY INVENTORY
 3.SEARCH A BOOK
 4.PURCHASE A BOOK
 5.UPDATE INVENTORY
 6.SUCCESSFUL/UNSUUCCESSFUL TRANSACTIONS
 7.EXIT
enter ur choice3
Enter the title of the book to be searched
Wings Of Fire
Book found

MENU
 1.ADD BOOKS
 2.DISPLAY INVENTORY
 3.SEARCH A BOOK
 4.PURCHASE A BOOK
 5.UPDATE INVENTORY
 6.SUCCESSFUL/UNSUUCCESSFUL TRANSACTIONS
 7.EXIT
enter ur choice4
Enter the title of the book to be purchased
Oliver Twist 
Book found
enter the no of books
20

Price of books is::10000

MENU
 1.ADD BOOKS
 2.DISPLAY INVENTORY
 3.SEARCH A BOOK
 4.PURCHASE A BOOK
 5.UPDATE INVENTORY
 6.SUCCESSFUL/UNSUUCCESSFUL TRANSACTIONS
 7.EXIT
enter ur choice5
Enter the sr no. of the book whose stock is to be updated2
what do u want to update
1.TITLE
2.AUTHOR
3.PUBLISHER
4.PRICE
5.STOCK
5
Enter the updated stock of the book40

MENU
 1.ADD BOOKS
 2.DISPLAY INVENTORY
 3.SEARCH A BOOK
 4.PURCHASE A BOOK
 5.UPDATE INVENTORY
 6.SUCCESSFUL/UNSUUCCESSFUL TRANSACTIONS
 7.EXIT
enter ur choice2

Sr no.	TITLE		AUTHOR		PUBLISHER		PRICE		STOCK
1	Harry Potter		J K Rowling		Royal publications		400		43
2	Oliver Twist		Ollie Pope		London publications		500		40
3	Wings Of Fire		DR.Apj Kalam		Delhi publications		335		12

MENU
 1.ADD BOOKS
 2.DISPLAY INVENTORY
 3.SEARCH A BOOK
 4.PURCHASE A BOOK
 5.UPDATE INVENTORY
 6.SUCCESSFUL/UNSUUCCESSFUL TRANSACTIONS
 7.EXIT
enter ur choice6
NO OF SUCCESSFUL TRANSACTIONS ARE 1

NO OF UNSUCCESSFUL TRANSACTIONS ARE 0


MENU
 1.ADD BOOKS
 2.DISPLAY INVENTORY
 3.SEARCH A BOOK
 4.PURCHASE A BOOK
 5.UPDATE INVENTORY
 6.SUCCESSFUL/UNSUUCCESSFUL TRANSACTIONS
 7.EXIT
enter ur choice4
Enter the title of the book to be purchased
Harry Potter
Book found
enter the no of books
44
Sorry,we are out of stock
MENU
 1.ADD BOOKS
 2.DISPLAY INVENTORY
 3.SEARCH A BOOK
 4.PURCHASE A BOOK
 5.UPDATE INVENTORY
 6.SUCCESSFUL/UNSUUCCESSFUL TRANSACTIONS
 7.EXIT
enter ur choice6
NO OF SUCCESSFUL TRANSACTIONS ARE 1

NO OF UNSUCCESSFUL TRANSACTIONS ARE 1


MENU
 1.ADD BOOKS
 2.DISPLAY INVENTORY
 3.SEARCH A BOOK
 4.PURCHASE A BOOK
 5.UPDATE INVENTORY
 6.SUCCESSFUL/UNSUUCCESSFUL TRANSACTIONS
 7.EXIT
enter ur choice7
*/



