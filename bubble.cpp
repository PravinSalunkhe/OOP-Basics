#include<iostream>
using namespace std;

template<typename T>
void bubble_sort(T array[20],int n);
template<typename T>
void display(T array[20],int n);
int main()
{
	int ch,n,i;
	cout<<"\nSORTING-APPLICATIOON OF TEMPLATES";
do
{

	cout<<"\n1.INTEGER SORTING\n2.FLOAT SORTING\n3.EXIT\nenter ur choice:-";
	cin>>ch;
	switch(ch)
	{
		case 1:
			 int array[20];
			 cout<<"\nENTER THE NO OF ELEMENTS:-";
			 cin>>n;
			 for(i=0;i<n;i++)
			 {
			 	cin>>array[i];
			 }
			 cout<<"\nSORTING.....";
			 bubble_sort <int> (array,n);
			// display<int>(array,n);	
			 break;
		case 2:
			float array1[20];
			cout<<"\nENTER THE NO OF ELEMENTS:-";
			cin>>n;
			 for(i=0;i<n;i++)
			 {
			 	cin>>array1[i];
			 }
			 cout<<"\nSORTING.....";
			 bubble_sort <float> (array1,n);
			 //display<float>(array1,n);	
			 break;
		case 3:
			break;
	}
}while(ch!=3);
return 0;
}

template<typename T>
void bubble_sort(T array[20],int n)
{
T t;	
int last,j,i,swap=0,tswap=0,comparison=0;
  	last=n;
  	
 	for(i=0;i<n;i++)
 	{
 		swap=0;
 		for(j=0;j<last-1;j++)
 		{
 			if(array[j]>array[j+1])
 			{
 				t=array[j];
 				array[j]=array[j+1];
 				array[j+1]=t;
 				swap=swap+1;
 			}
 		}
 		comparison=comparison+(last-1);
 		tswap=tswap+swap;
 		if(swap==0)
 		{	display<T>(array,n);
 			printf("\nNo of swaps are::%d",tswap);
 			printf("\nNo  of passes are::%d",i+1);
 			printf("\nNo of comparisons are::%d",comparison);
 			return;
 		}  
 		else{ last=last-1;}
 	}
}		
template<typename T>
void display(T array[20],int n)
{
	int i;
	cout<<"\n";
	for(i=0;i<n;i++)
	 {
	 	cout<<array[i]<<"\t";
	 }
} 
