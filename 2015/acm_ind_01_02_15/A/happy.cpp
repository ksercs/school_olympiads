#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int n, ch, nch;
int a[1000+5];

void in()
{
    ifstream cin ("happy.in");
    cin >>n;
    for (int i=0; i<n; i++)
    {
        cin >>a[i];
        if (a[i]%2==0) {ch++;}
        else  {nch++;}
    }
}

void solution()
{
}

void out()
{
     ofstream cout ("happy.out");
        if (ch>nch) {cout <<"Happy\n";}
        else  {cout <<"Sad\n";}
}

int main()
{
    in();
    solution();
    out();
return 0;
}
