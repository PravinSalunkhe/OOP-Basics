#include<iostream>
#include<iomanip>
using namespace std;
class weather_report
{

float htemp,ltemp,amtrain,amtsnow;
static int count;
public:
    weather_report();
    void display(void);
    void input(void);
    void average(weather_report w[31]);
};
int weather_report::count;

weather_report::weather_report()
{
ltemp=-999;
htemp=999;
amtrain=0;
amtsnow=0;
}

void weather_report::input(void)
{
  count++;  
  cout<<"\n enter the high temp";
  cin>> htemp ;
  cout<<"\n enter the low temp";
  cin>> ltemp ;
  cout<<"\n enter the amt of rain";
  cin>> amtrain ;
  cout<<"\n enter the amt of snow";
  cin>> amtsnow ;
 }
void weather_report::display(void)
{
 cout<<"|"<<setw(9)<<htemp;
 cout<<"|"<<setw(9)<<ltemp;
 cout<<"|"<<setw(9)<<amtrain;
 cout<<"|"<<setw(9)<<amtsnow;
}
void weather_report::average(weather_report w[31])
{
float train,tsnow,tltemp,thtemp;
float avghtemp,avgltemp,avgrain,avgsnow;
thtemp=0,tltemp=0,tsnow=0,train=0;
int i;
for(i=0;i<31;i++)
{
if(w[i].htemp!=999)
{
thtemp+=w[i].htemp;
}
if(w[i].ltemp!= -999)
{
tltemp+=w[i].ltemp;
}
if(w[i].amtrain!=0)
{
train+=w[i].amtrain;
}
if(w[i].amtsnow!=0)
{
tsnow+=w[i].amtsnow;     
}
}
avghtemp=thtemp/count;
avgltemp=tltemp/count;
avgrain=train/count;
avgsnow=tsnow/count;
cout<<"\nAverage High Temp:"<<avghtemp;
cout<<"\nAverage Low Temp:"<<avgltemp;
cout<<"\nAverage Amount of Rain:"<<avgrain;
cout<<"\nAverage Amount of Snow:"<<avgsnow;
}
  

const int size=31;  
int main()
{
weather_report wt[size],obj;
int ch,i,day;
cout<<"\n WEATHER REPORT\n";
do
{
 cout<<"\n MAIN MENU";
 cout<<"\n 1.ENTER THE DATA";
 cout<<"\n 2.DISPLAY REPORT";
 cout<<"\n 3.EXIT";
 cout<<"\n   ENTER YOUR CHOICE";
 cin>>ch ;
 switch (ch)
 {
  case 1:cout<<"enter the date to be updated:";
         cin>>day;
         wt[day].input();
         break;
  case 2:
         cout<<setw(15)<<setiosflags(ios::left)<<"\n|DAY OF MONTH"<<setw(10)<<"|HIGHTEMP"<<setw(10)<<"|LOWTEMP"<<setw(10)<<"|AMTRAIN"<<setw(10)<<"|AMTSNOW";
         cout<<"\n";
         for(i=0;i<size;i++)
                {
                 cout<<"\n"<<setw(14)<<i+1;
                 wt[i].display();
                }
         obj.average(wt);
         break; 
 default: printf("\nENTER A VALID CHOICE\n");             
 } 
}while(ch!=3);  
return (0);
}
                        
                   
        
