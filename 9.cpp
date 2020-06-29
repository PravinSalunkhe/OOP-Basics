/*
SE-10
G-10
23257
PROBLEM STATEMENT:-
Write a C++ program that creates an output file, writes information to it,
closes the file and open it again as an input file and read the information from
the file.
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
string str;

ofstream F;//for writing in the file

F.open("1.txt",ios::app);//opening in append mode

cout<<"WRITE SOMETHING\n";
getline(cin,str);

F<<str;//input for file

F.close();

  ifstream f;//cannot declare same object F because it already is oject of ofstream
  f.open("1.txt",ios::in);//for reading from file
  cout << "\nTHE FILE CONTAINS \n" ; 
     while(f>>str)//will exit if file ends
            {
           cout<<" "<<str;
            }
            
     cout<<endl;
     f.close();

}

/*OUTPUT:-
admin1@pravin-27:~/se10/oopl$ ./a.out
WRITE SOMETHING
MY NAME IS PRAVIN.MY COLLEGE NAME IS PICT.

THE FILE CONTAINS 
 MY NAME IS PRAVIN.MY COLLEGE NAME IS PICT.
admin1@pravin-27:~/se10/oopl$ 
*/


