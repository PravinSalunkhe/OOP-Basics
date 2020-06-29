#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class student{
     private:
          char name[10];
          int roll_no;
          
     public:
          student()
              {
                strcpy(name,"\0");
                roll_no = 0;
              }
           void create();
           void display();
           void search(int );
           void add();
           void del();
           void modify(int );
};
 
void student :: create(){
    char c;
    fstream file;
    file.open("1.dat",ios :: app | ios :: binary | ios :: out);
    while(c!='y')
      {
        cout<<"ENTER NAME : ";
        cin>>name;
        cout<<"ENTER ROLL NO. : ";
        cin>>roll_no;
        file.write((char *)this,sizeof(student)); 
        cout<<"IF YOU WANT TO EXIT PRESS y ELSE PRESS n \n";
        cin>>c;
      }
    cout<<"DATA SUCCESSFULLY ADDED TO FILE\n";
    file.close();
}

void student :: display(){

    ifstream f;
    f.open("1.dat",ios :: in | ios :: binary);

    while(f.read((char *)this,sizeof(student)))
      {
         cout<<"ROLL NO. : "<<roll_no;
         cout<<"\tNAME : "<<name;
         cout<<"\n";
      }

    f.close();
}

void student :: search(int x)
{
   ifstream f;
    f.open("1.dat",ios :: in | ios :: binary);

    while(f.read((char *)this,sizeof(student)))
      {
         if(this->roll_no == x)
           {
             cout<<"DATA OF GIVEN ROLL NUMBER IS \n";
             cout<<this->name<<endl;
           }
      }

    f.close();
}

void student :: modify(int x)
{
fstream f;
    f.open("1.dat",ios :: in | ios :: binary | ios :: out);

    while(f.read((char *)this,sizeof(student)))
      {
         if(this->roll_no == x)
           {
             f.seekg(f.tellg() - sizeof(student));
             cout<<"ENTER NEW NAME\n";
             cin>>this->name;
             f.write((char *)this,sizeof(student));
           }
      }

    f.close();
}

void student :: del()
{
   int r;
   student a;
   cout<<"ENTER ROLL NUMBER WHOSE DATA IS TO BE ERASED FROM FILE\n";
   cin>>r;
   fstream f1;
   fstream temp;
   f1.open("1.dat",ios :: in | ios :: binary | ios :: out);
   temp.open("2.dat",ios :: in | ios :: binary | ios :: out);
   while(f1.read((char *)this,sizeof(student)))
    {
      if(this -> roll_no != r)
        {
           a.roll_no = this ->roll_no;
           strcpy(a.name,this->name);
           temp.write((char *)&a,sizeof(student));  
        }
    }
   f1.close();
   temp.seekp(ios :: beg);
   ofstream f2;
   f2.open("1.dat",ios :: binary | ios :: out | ios :: trunc);
   while(temp.read((char *)&a , sizeof(student)))
   {
     this ->roll_no = a.roll_no;
     strcpy(this->name,a.name);
     f2.write((char *)this , sizeof(student));
   }
   cout << "THE GIVEN RECORD IS DELETED";
   f2.close();
   temp.close();
}

int main()
{
   student s;
   int ch,r;
   s.create();
   do{
      cout<<"ENTER THE CHOICE \n1.DISPLAY\n2.ADD A RECORD\n3.DELETE A RECORD\n4.MODIFY A RECORD\n5.SEARCH A RECORD\n6.EXIT\n";
      cin>>ch;
      switch(ch)
         {
           case 1:
               s.display();
               break;

           case 2:
               s.create();
               break;

           case 3:
               s.del();
               break;

           case 4:
               cout<<"ENTER THE ROLL NO. WHOSE DATA IS TO BE MODIFIED"<<endl;
               cin>>r;
               s.modify(r);
               break;

           case 5:
               cout<<"ENTER THE ROLL NO. TO BE SEARCHED"<<endl;
               cin>>r;
               s.search(r);
               break;

           case 6:
               break;

           default:
              cout<<"PLEASE ENTER VALID CHOICE\n";
         }
   }
   while(ch!=6);
 return 0;
}

