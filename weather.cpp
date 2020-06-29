#include<iostream>
using namespace std;
class weather{	
	public:
	int day,highTemp,lowTemp,amtRain,amtSnow;
	weather(){
		day=99;
		highTemp=999;
		lowTemp=-999;
		amtRain=0;
		amtSnow=0;
	}
};	
int main(){
	int sumHT=0,sumLT=0,sumR=0,sumS=0;
	float avgHT=0,avgLT=0,avgR=0,avgS=0;
	int i,n=0,choice;
	weather w[30];
	do{
		cout<<"\n\n1.Display"<<"\n\n2.Update"<<"\n\n3.Average"<<"\n\n4.Exit";
		cout<<"\n\n\nEnter Choice";
		cin>>choice;
		switch(choice){
			case 1:
			cout<<"Sr.No.	Day	High Temp	Low Temp	Amt Rain	Amt Snow";
			for(i=0;i<30;i++)
			cout<<"\n"<<i+1<<"\t"<<w[i].day<<"\t"<<w[i].highTemp<<"\t\t"<<w[i].lowTemp<<"\t\t"<<w[i].amtRain<<"\t\t"<<w[i].amtSnow;
			break;
			case 2:
			n++;
			cout<<"Enter day";
			cin>>i;
			i--;
			w[i].day=i+1;
			cout<<"Enter High Temp (-30 to 70)";
			cin>>w[i].highTemp;
			sumHT=sumHT+w[i].highTemp;
			cout<<"Enter low Temp (-30 to 70)";
			cin>>w[i].lowTemp;
			sumLT=sumLT+w[i].lowTemp;
			cout<<"Enter Rainfall";
			cin>>w[i].amtRain;
			sumR=sumR+w[i].amtRain;
			cout<<"Enter Snowfall";
			cin>>w[i].amtSnow;
			sumS=sumS+w[i].amtSnow;
			avgHT=sumHT/n;
			avgLT=sumLT/n;
			avgR=sumR/n;
			avgS=sumS/n;
			break;
			case 3:
			cout<<"\nAverage High Temperature : "<<avgHT;
			cout<<"\nAverage Low Temperature : "<<avgLT;
			cout<<"\nAverage Rainfall : "<<avgR;
			cout<<"\nAverage Snow : "<<avgS;
			break;
			case 4:
			break;
		}
	}while(choice!=4);
	return 0;
}
