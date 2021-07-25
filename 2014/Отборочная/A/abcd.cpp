#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <conio.h>

using namespace std;

int i, t, num[10000+1], sh1, sh2, sh3, sh4, sh5, sh6, j;
int otvet[10000+1];
char ans[2][4]={"NO","YES"};

void in()
{
    ifstream cin ("abcd.in");
    cin >> t;
    for (i=0; i<t; i++)
    {
        cin >> num[i];
    }
}

void solution()
{
     for (i=0; i<t; i++)
     {
         sh1=num[i]%100;
         sh2=num[i]/100;
         if ((sh1*sh1+sh2*sh2)%7==1) {otvet[i]=1;}
         else {otvet[i]=0;}
     }
}

void out()
{
     ofstream cout ("abcd.out");
     for (i=0; i<t; i++)
     {
         cout << ans[otvet[i]] <<"\n";
     }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
