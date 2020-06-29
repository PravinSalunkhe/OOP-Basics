/*
SE-10
G-10
PRAVIN SALUNKHE
Write a program in C++ using function/class template to read two matrices of
different data types such as integers and floating point values and perform simple
arithmetic operations on these matrices separately and display it.
*/
#include<iostream>
using namespace std;
template<typename T>//prototype declaration for using templates
void getmatrix(T mat[10][10],int row,int col);
template<typename T>//prototype declaration for using templates
void display(T mat[10][10],int row,int col);
template<typename T>//prototype declaration for using templates
void add(T matx[10][10],T maty[10][10],T matz[10][10],int row,int col);
template<typename T>//prototype declaration for using templates	
void sub(T matx[10][10],T maty[10][10],T matz[10][10],int row,int col);
template<typename T>//prototype declaration for using templates	
void mul(T matx[10][10],T maty[10][10],T matz[10][10],int r1,int r2,int c1,int c2);
int main()
{
	int row1,col1,row2,col2,ch,ch1;
	cout<<"USE OF TEMPLATES\nMATRIX OPERATIONS USING 2 MATRICES\n";
	cout<<"Enter the 1st matrix\n";
	cout<<"\nEnter the no. of rows:";
	cin>>row1;
	cout<<"Enter the no. of columns:";
	cin>>col1;	
	
	cout<<"Enter the 2nd matrix\n";
	cout<<"\nEnter the no. of rows:";
	cin>>row2;
	cout<<"Enter the no. of columns:";
	cin>>col2;
c:	cout<<"\nTYPE OF MATRICES::\n1.INTEGER\n2.FLOAT\n3.EXIT\nENTER UR CHOICE:-";
	cin>>ch;
	switch(ch)
	{
		case 1:
			int mat1[10][10],mat2[10][10],mat5[10][10];
			cout<<"ENTER MATRIX 1:-";
			getmatrix <int> (mat1,row1,col1);//getting integer version of matrix
			cout<<"MATRIX 1\n";
			display(mat1,row1,col1);
			cout<<"ENTER MATRIX 2:-";
			getmatrix <int> (mat2,row2,col2);//getting integer version of matrix
			cout<<"MATRIX 2\n";
			display(mat2,row2,col2);
			do
			{
				cout<<"MENU\n1.ADDITION\n2.SUBTRACTION\n3.MULTIPLICATION\n4.EXIT THE MENU\n5.EXIT THE PROGRAM\nENTER YOUR CHOICE:-";
				cin>>ch1;
				switch(ch1)
				{
					case 1:
						if(row1==col1 && col1==col2)
						{
						cout<<"ADDITION IS:-\n";
						add <int> (mat1,mat2,mat5,row1,col1);//addition
						display<int> (mat5,row1,col1);
						}
						else
						cout<<"ADDITION NOT POSSIBLE\n";
						break;
					case 2: 
						if(row1==col1 && col1==col2)
						{
						cout<<"SUBTRACTION IS:-\n";
						sub <int> (mat1,mat2,mat5,row2,col2);//subtraction
						display <int> (mat5,row1,col1);
						}
						else
						cout<<"SUBTRACTION NOT POSSIBLE\n";
						break;
					case 3:
						if(col1==row2)
						{
						cout<<"MULTIPLICATION IS:-\n"; 
						mul <int> (mat1,mat2,mat5,row1,row1,col1,col2);//multiplication
						display <int> (mat5,row1,col2);
						}
						else
						cout<<"MULTIPLICATION NOT POSSIBLE\n";
						break;
					case 4:
						goto c;
					case 5:
						break;	
				}
			}while(ch1!=5);		
			break;
		case 2:
			float mat3[10][10],mat4[10][10],mat6[10][10];
			cout<<"\nENTER MATRIX 1:-";
			getmatrix <float> (mat3,row1,col1);//getting float version of matrix
			cout<<"MATRIX 1\n";
			display(mat3,row1,col1);
			cout<<"\nENTER MATRIX 2:-";
			getmatrix <float> (mat4,row2,col2);//getting float version of matrix
			cout<<"MATRIX 2\n";
			display(mat4,row2,col2);
			do
			{
				cout<<"MENU\n1.ADDITION\n2.SUBTRACTION\n3.MULTIPLICATION\n4.EXIT THE MENU\n5.EXIT THE PROGRAM\nENTER YOUR CHOICE:-";
				cin>>ch1;
				switch(ch1)
				{
					case 1:
						if(row1==col1 && col1==col2)
						{
						cout<<"ADDITION IS:-\n";
						add <float> (mat3,mat4,mat6,row1,col1);//addition
						display <float> (mat6,row1,col1);
						}
						else
						cout<<"ADDITION NOT POSSIBLE\n";
						break;
					case 2: 
						if(row1==col1 && col1==col2)
						{
						cout<<"SUBTRACTION IS:-\n";
						sub <float> (mat3,mat4,mat6,row1,col1);//subtraction
						display <float> (mat6,row1,col1);
						}
						else
						cout<<"SUBTRACTION NOT POSSIBLE\n";
						break;
					case 3:
						if(col1==row2)
						{
						cout<<"MULTIPLICATION IS:-\n"; 
						mul <float> (mat3,mat4,mat6,row1,row2,col1,col2);//multiplication
						display <float> (mat6,row1,col2);
						}
						else
						cout<<"MULTIPLICATION NOT POSSIBLE\n";
						break;
					case 4:
						goto c;
					case 5:	
						break;	
				}
			}while(ch1!=5);		
			break;
		case 3:
			break;	
	}				
}
template<typename T>
void getmatrix(T mat[10][10],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<"ELEMENT NO ["<< i<<"]["<< j <<"]:-";
			cin>>mat[i][j];
		}
	}
}
template<typename T>
void display(T mat[10][10],int row,int col)
{
	int i,j;
	cout<<"[\n";
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\t\t]\n";
}
template<typename T>	
void add(T matx[10][10],T maty[10][10],T matz[10][10],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			matz[i][j]=matx[i][j]+maty[i][j];
		}	
	}
}
template<typename T>	
void sub(T matx[10][10],T maty[10][10],T matz[10][10],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			matz[i][j]=matx[i][j]-maty[i][j];
		}	
	}
}	
template<typename T>	
void mul(T matx[10][10],T maty[10][10],T matz[10][10],int r1,int r2,int c1,int c2)
{		
	int i,j,k;
	T sum;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			sum=0;
			for(k=0;k<c1;k++)
			{
				sum=sum+matx[i][k]*maty[k][j];
			}
			matz[i][j]=sum;
		}
	}
}	
/*OUTPUT:-

a3-402-18@a340218-OptiPlex-3010:~/23257$ ./a.out
USE OF TEMPLATES
MATRIX OPERATION USING 2 MATRICES
Enter the 1st matrix

Enter the no. of rows:2
Enter the no. of columns:2
Enter the 2nd matrix

Enter the no. of rows:2
Enter the no. of columns:2

TYPE OF MATRIX::
1.INTEGER
2.FLOAT
3.EXIT
ENTER UR CHOICE:-1
ENTER MATRIX 1:-ELEMENT NO [0][0]:-2
ELEMENT NO [0][1]:-3
ELEMENT NO [1][0]:-4
ELEMENT NO [1][1]:-5
MATRIX 1
[
2	3	
4	5	
		]
ENTER MATRIX 2:-ELEMENT NO [0][0]:-1
ELEMENT NO [0][1]:-2
ELEMENT NO [1][0]:-6
ELEMENT NO [1][1]:-7
MATRIX 2
[
1	2	
6	7	
		]
MENU
1.ADDITION
2.SUBTRACTION
3.MULTIPLICATION
4.EXIT THE MENU
5.EXIT THE PROGRAM
ENTER YOUR CHOICE:-2
SUBTRACTION IS:-
[
1	1	
-2	-2	
		]
MENU
1.ADDITION
2.SUBTRACTION
3.MULTIPLICATION
4.EXIT THE MENU
5.EXIT THE PROGRAM
ENTER YOUR CHOICE:-3
MULTIPLICATION IS:-
[
20	25	
34	43	
		]
MENU
1.ADDITION
2.SUBTRACTION
3.MULTIPLICATION
4.EXIT THE MENU
5.EXIT THE PROGRAM
ENTER YOUR CHOICE:-1
ADDITION IS:-
[
3	5	
10	12	
		]
MENU
1.ADDITION
2.SUBTRACTION
3.MULTIPLICATION
4.EXIT THE MENU
5.EXIT THE PROGRAM
ENTER YOUR CHOICE:-4

TYPE OF MATRIX::
1.INTEGER
2.FLOAT
3.EXIT
ENTER UR CHOICE:-2

ENTER MATRIX 1:-ELEMENT NO [0][0]:-4.
ELEMENT NO [0][1]:-5.5
ELEMENT NO [1][0]:-2.0
ELEMENT NO [1][1]:-3.5
MATRIX 1
[
4	5.5	
2	3.5	
		]

ENTER MATRIX 2:-ELEMENT NO [0][0]:-1.5
ELEMENT NO [0][1]:-2.5
ELEMENT NO [1][0]:-2.0
ELEMENT NO [1][1]:-3.5
MATRIX 2
[
1.5	2.5	
2	3.5	
		]
MENU
1.ADDITION
2.SUBTRACTION
3.MULTIPLICATION
4.EXIT THE MENU
5.EXIT THE PROGRAM
ENTER YOUR CHOICE:-1
ADDITION IS:-
[
5.5	8	
4	7	
		]
MENU
1.ADDITION
2.SUBTRACTION
3.MULTIPLICATION
4.EXIT THE MENU
5.EXIT THE PROGRAM
ENTER YOUR CHOICE:-2
SUBTRACTION IS:-
[
2.5	3	
0	0	
		]
MENU
1.ADDITION
2.SUBTRACTION
3.MULTIPLICATION
4.EXIT THE MENU
5.EXIT THE PROGRAM
ENTER YOUR CHOICE:-3
MULTIPLICATION IS:-
[
17	29.25	
10	17.25	
		]
MENU
1.ADDITION
2.SUBTRACTION
3.MULTIPLICATION
4.EXIT THE MENU
5.EXIT THE PROGRAM
ENTER YOUR CHOICE:-5
a3-402-18@a340218-OptiPlex-3010:~/23257$ 
*/										
