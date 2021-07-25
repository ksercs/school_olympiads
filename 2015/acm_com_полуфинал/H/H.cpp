#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int a[100+5][100+5], n, a1, d, k;

void in()
{
    ifstream cin ("fever.in");
    cin >> n >> a1 >> d >> k;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }
}

void solution()
{
    int lt=0, sh=0;;
    while (lt<k)
    {
        lt++;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if ((j==0) && (i==0)) {sh = sh + a[i+1][j] + a[i][j+1];}
                if ((j==0) && (i!=n-1) && (i!=0)) {sh = sh + a[i+1][j] + a[i-1][j] + a[i][j+1];}
                if ((j!=n-1) && (j!=0) && (i==0)) {sh = sh + a[i+1][j] +a[i][j+1] + a[i][j-1];}
                if ((j==n-1) && (i==n-1)) {sh = sh + a[i-1][j] + a[i][j-1];}
                if ((j!=n-1) && (i==n-1) && (j!=0)) {sh = sh + a[i-1][j] + a[i][j+1] + a[i][j-1];}
                if ((j==n-1) && (i!=n-1) && (i!=0)) {sh = sh + a[i][j-1] + a[i+1][j] + a[i-1][j];}
                if ((j!=0) && (i!=0) && (j!=n-1) &&( i!=n-1)) {sh = sh + a[i+1][j] + a[i-1][j] + a[i][j+1] + a[i][j-1];}
                if ((j==0) && (i==n-1)) {sh = sh + a[i-1][j] + a[i][j+1];}
                if ((j==n-1) && (i==0)) {sh = sh + a[i][j-1] + a[i+1][j];}

                if ((sh>=a1) && (sh<d)) {a[i][j]=1;}
                if ((sh>=a1) && (sh<=d)) {a[i][j]=1;}
                if ((sh<a1) && (sh>d)) {a[i][j]=0;}
            }
        }
    }
}

void out()
{
     ofstream cout ("fever.out");
     for (int i=0; i<n; i++)
     {
         for (int j=0; j<n; j++)
         {
             cout << a[i][j];
         }
         cout << "\n";
     }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
