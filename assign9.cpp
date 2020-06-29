/*
SE-10
G-10
23257
PROBLEM STATEMENT:-Write a C++ program that creates an output file, writes information to it,
closes the file and open it again as an input file and read the information from
the file
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{
	string str;
	ofstream fout;
	fout.open("abc.txt",ios::app);
	cout<<"ENTER THE DATA TO BE ENTERED IN FILE:-";
	getline(cin,str);
	fout<<str;
	fout<<endl;;
	fout.close();




	
	ifstream fin;
	fin.open("abc.txt",ios::in);
	cout<<"THE FILE CONTAINS:-\n";
	while(fin>>str)
	{
		cout<<" "<<str;
		
	}
	cout<<endl;
	fin.close();
}
		
/*OUTPUT:-

admin1@pravin-27:~/se10/oopl$ g++ assign9.cpp
admin1@pravin-27:~/se10/oopl$ ./a.out
ENTER THE DATA TO BE ENTERED IN FILE:-I STUDY IN ALPHONSA HIGH SCHOOL 
ISTUDYINALPHONSAHIGHSCHOOL
admin1@pravin-27:~/se10/oopl$ g++ assign9.cpp
admin1@pravin-27:~/se10/oopl$ ./a.out
ENTER THE DATA TO BE ENTERED IN FILE:-my name is pravin
THE FILE CONTAINS:-
 I STUDY IN ALPHONSA HIGH SCHOOLmy name is pravin
admin1@pravin-27:~/se10/oopl$ 
*/
	
	
