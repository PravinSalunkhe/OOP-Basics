#include<iostream>
#include<string.h>
using namespace std;

template<class T>
class matrix
{
		T mat[10][10];
		int row;
		int col;
		
	public:	
		void insert();
		void display();
		void add(matrix <T> & a,matrix <T> & b,matrix <T> & c);
		void sub(matrix <T> & a,matrix <T> & b,matrix <T> & c);	
};
template<class T>
void matrix <T> :: insert()
{
	int i,j;
	cout<<"\nENTER THE NO OF ROWS:-";
	cin>>row;
	cout<<"\nENTER THE NO OF COLUMNS:-";
	cin>>col;
	cout<<"\nENTER THE MATRIX ELEMENTS:-";
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<"ELEMENT["<<i<<"]["<<j<<"]:-";
			cin>>mat[i][j];
		}
	}
}
template<class T>
void matrix <T> :: display()
{
	int i,j;
	cout<<"[";
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\t\t]";
}
template<class T>
void matrix <T> :: add(matrix <T> & a,matrix <T> & b,matrix <T> & c)
{
	int i,j;
	if(a.row==b.row && a.col==b.col)
	{
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				c.mat[i][j]=a.mat[i][j]+b.mat[i][j];
			}
		}
	c.row=a.row;
	c.col=a.col;
	}
	else
	{
	cout<<"\nADDITION NOT POSSIBLE";
	}
}
template<class T>
void matrix <T> :: sub(matrix <T> & a,matrix <T> & b,matrix <T> & c)
{
	int i,j;
	if(a.row==b.row && a.col==b.col)
	{
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				c.mat[i][j]=a.mat[i][j]-b.mat[i][j];
			}
		}
	c.row=a.row;
	c.col=a.col;
	}
	else
	{
	cout<<"\nSUBTRACTION NOT POSSIBLE";
	}
}	
	
int main()
{
	int ch,ch1;
	cout<<"\nUSE OF TEMPLATES\n";
	do
	{
		cout<<"\nMENU\n1.INTEGER MATRICES\n2.FLOAT MATRICES\n3.EXIT\nENTER UR CHOICE:-";
		cin>>ch;
		switch(ch)
		{
			case 1:
				matrix <int> m1;
				matrix <int> m2;
				m1.insert();
				m1.display();
				m2.insert();
				m2.display();
				do
				{
					cout<<"\nSELECT OPERATION\n1.ADD\n2.SUBTRACT\n3.EXIT\nENTER UR CHOICE:-";
					cin>>ch1;
					switch(ch1)
					{
						case 1:
							matrix <int> m5;
							m5.add(m1,m2,m5);
							m5.display();
							break;
						case 2:
							matrix <int> m6;
							m6.sub(m1,m2,m6);
							m6.display();
							break;
						case 3:
							exit(1);
					}
				}while(ch1!=3);		
				break;
			case 2:
				matrix <float> m3;
				matrix <float> m4;
				m3.insert();
				m3.display();
				m4.insert();
				m4.display();
				do
				{
					cout<<"\nSELECT OPERATION\n1.ADD\n2.SUBTRACT\n3.EXIT\nENTER UR CHOICE:-";
					cin>>ch1;
					switch(ch1)
					{
						case 1:
							matrix <float> m7;
							m7.add(m3,m4,m7);
							m7.display();
							break;
						case 2:
							matrix <float> m8;
							m8.sub(m3,m4,m8);
							m8.display();
							break;
						case 3:
							exit(1);
					}
				}while(ch1!=3);		
				break;
			case 3:
				exit(0);
		}
	}while(ch!=3);
return 0;
}	
						
				
						
