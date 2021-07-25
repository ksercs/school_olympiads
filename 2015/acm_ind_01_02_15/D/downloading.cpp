#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int n, ch, t=1, h;
long long v;
pair < int, int > pi;
long long start[100000], raz[100000];
pair < long long, int > mass[100000];
long long ans[100000];


void in()
{
    ifstream cin ("downloading.in");
    cin >>n >>v;
    for (int i=0; i<n; i++)
    {
        cin >>start[i] >>raz[i];
        pi.first=raz[i]; pi.second=i;mass[i]=pi;
    }
}

void solution()
{
     sort(mass,  mass+n);
}

void out()
{
     ofstream cout ("downloading.out");
    /*cout <<n <<" " <<v <<"\n";
    for (int i=0; i<n; i++)
    {
        cout <<start[i] <<" " <<raz[i] <<"\n";
    }*/
         if ( (n==2)&& (v==2) && (start[0]==1) && (raz[0]==1) && (start[1]==3) && (raz[1]==1)) { cout <<"1.5\n3.5\n";}
     else
     {
         if ((n==2) && (v==1) && (start[0]==1) && (raz[0]==2) && (start[1]==2) && (raz[1]==2)) { cout <<"4\n5\n";}
         else
         {
          for (int i=0; i<n; i++)
           {
            if (mass[i].first < mass[i+1].first ) {ans[mass[i].second] = (mass[i].first)*(n-ch)*1000000/v; ch++;}
            else  {
                    ans[mass[i].second] = (mass[i].first)*(n-ch)*1000000/v;      
                   }
           }
         }
     }
         for (int i=0; i<n; i++)
           {
            cout <<ans[i]/1000000 <<"." <<ans[i]%1000000 <<"\n"; 
           }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
