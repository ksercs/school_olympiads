#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>


using namespace std;

int n, m, ans, a, b;
int mass[200000+5];

void solution()
{
     ifstream cin ("swap.in");
     ofstream cout ("swap.out");
     cin >>n;
     cin >>m;
     
     for (int i=1; i<=2*n; i++)
     {
         mass[i]=i;
     }
          
     ans=n;
     
     for (int i=0; i<m; i++)
     {
        cin >>a >>b;
     if (a>n && b<=n) {swap(a,b);}  
        swap(mass[a], mass[b]);
     if (a<=n && b>n)
     {
        if (mass[b]<=n && mass[a]>n) {ans--;}
        if (mass[b]>n && mass[a]<=n) {ans++;}
     }
        cout <<ans <<"\n"; 
     }
}


int main()
{
    solution();
return 0;
}
