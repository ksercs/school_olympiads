#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
//#include <conio.h>

using namespace std;

const int MAX_mass_size=1000;
int n, k, ch, f, ans=1;
int a[MAX_mass_size+2], k_mass[MAX_mass_size+2][MAX_mass_size+2];

void in()
{
    ifstream cin ("chess.in");
    cin >>n;
    for (int i=1; i<=n; i++)
    {
        cin >>a[i];
    }
}

void solution()
{
     for (int i=1; i<=n; i++)
     {
         for (int j=a[1]-a[i]+1; j<=a[1]; j++)
         {
            // cout <<a[i] <<" " <<a[1]-a[ch]+1 <<"\n"; getch();
             k_mass[j][i]=1;
         }
     }
     for (int i=1; i<=n; i++)
     {
         for (int j=1; j<=a[1]; j++)
         {
             if (k_mass[a[1]-f][i]!=1) {ch=i-1;}
             f++;
         }
     }
     
}

void out()
{
     ofstream cout ("chess.out");
    /*cout <<n <<"\n";
    for (int i=1; i<n; i++)
    {
        cout <<a[i] <<" ";
    }
    cout <<a[n] <<"\n";*/
    /*for (int i=1; i<=n; i++)
     {
         for (int j=a[1]-a[i]+1; j<=a[1]; j++)
         {
            cout << k_mass[j][i] <<"\n"; //getch();
         }
         cout <<" "; //getch();
     }*/
     f=0;
     cout <<ch <<"\n";
     for (int i=1; i<=n; i++)
     {
             if (k_mass[a[1]-f][i]!=1) {ch=i-1;}
             else                      {cout <<ans <<" " <<i <<"\n"; ans++;}
             f++;
     }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
