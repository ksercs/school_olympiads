#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int n, m, k;
long long ch;
int mass[20000][20000];
int x[100000], y[100000];

void in()
{
    ifstream cin ("adding.in");
   cin >>n >>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {   
            cin >>mass[i][j];
        }
    }
    cin >>k;
    for (int i=0; i<k; i++)
    {
        cin >>x[i] >>y[i];
        for (int g=0; g<m; g++)
        {   
            ch=(mass[x[i]-1][g]+mass[y[i]-1][g])%1000000007;
            //cout <<ch <<"\n"; system("pause");
            mass[x[i]-1][g]=ch;
            ch=0;
        }
    }
}   

void solution()
{
}

void out()
{
     ofstream cout ("adding.out");
    /* cout <<n <<" " <<m <<"\n";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {   
            cout <<mass[i][j] <<" ";
        }
        cout <<"\n";
    }
    cout <<k <<"\n";;
    for (int i=0; i<k; i++)
    {
        cout <<x[i] <<" " <<y[i] <<"\n";
    }*/
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {   
            cout <<mass[i][j] <<" ";
        }
        cout <<"\n";
    }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
