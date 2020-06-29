#include<iostream>
using namespace std;

class tele
{
	int model_no;
	float size;
	int price;
public:
	void getdata();
	void display()
	{
		cout<<"\nTELEVISION SUCCESSFULLY PURCHASED\n";
	}	
};
void tele :: getdata()
{
	int count=0,a;
	cout<<"\nENTER THE MODEL NO.[RANGE(1-5)DIGITS]:-";
	cin>>model_no;
	cout<<"ENTER THE SIZE[RANGE(12 TO 70)]:-";
	cin>>size;
	cout<<"ENTER THE PRICE[RANGE(0-50000)]:-";
	cin>>price;
	a=model_no;
	do
	{
		a=a/10;
		count++;
	}while(a!=0);	
	try
	{
		if(count>5)
		{
			throw model_no;
		}
		else if(size < 12.00 || size > 70.00)
		{
			throw size;
		}
		else if(price<0 || price>50000)
		{
			throw 'd';
		}
		else
		{
			display();
			return;	
		}
	}
	catch(int)
	{
		cout<<"\nINCORRECT MODEL NO.";
		return;				
	}
	catch(float)
	{
		cout<<"\nINCORRECT SIZE";
		return;
	}
	catch(char)
	{
		cout<<"\nINCORRECT PRICE";
		return;
	}
	catch(...)
	{
		cout<<"\nUNIVERSAL EXCEPTION";
		return;
	}
}
int main()
{
	tele t;
	t.getdata();
	return 0;
}								
