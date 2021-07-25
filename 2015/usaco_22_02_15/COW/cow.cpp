#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>


using namespace std;

char str[100000];
int n, sl;
long long ans;

set < int > Cs;
set < int > Os;
set < int > Ws;
set < int >:: iterator it1;
set < int >:: iterator it2;
set < int >:: iterator it3;

void in()
{
    ifstream cin ("cow.in");
    cin >>n;
    cin >>str;
}

void solution()
{
     sl=strlen(str);
   /* for (int i=0; i<sl; i++)
     {
         if (str[i]=='C') {
                          for (int g=i+1; g<sl; g++)
                           {
                                   if (str[g]=='O') {
                                                    for (int f=g+1; f<sl; f++)
                                                     {
                                                             if (str[f]=='W') {ans++;}
                                                     }
                                                    }
                           }
                          }
     }*/
     for (int i=0; i<sl; i++)
     {
         if (str[i]=='C') {Cs.insert(i);}
         if (str[i]=='O') {Os.insert(i);}
         if (str[i]=='W') {Ws.insert(i);}
     }
     for (it1=Cs.begin(); it1!=Cs.end(); it1++)
     {
       for (it2=Os.begin(); it2!=Os.end(); it2++)
       {
         if ( (*it2) > (*it1) ) 
         {
           for (it3=Ws.begin(); it3!=Ws.end(); it3++)
           {
            if ( (*it3) > (*it2) )  {ans++;}
            //else {Ws.erase(*it3);}
           }
         }
         //else {Os.erase(*it2);}
       }   
     }
}

void out()
{
     ofstream cout ("cow.out");
     cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
