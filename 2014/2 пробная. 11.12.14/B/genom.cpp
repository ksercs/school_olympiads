#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

long long x, y, z, ans;
long long k;

void in()
{
    ifstream cin ("genom.in");
    cin >>x >>y >>z >>k;
}

void solution()
{
     if(k%2==0) {ans=x-y;}
     else       {ans=y-x;}
}

void out()
{
     ofstream cout ("genom.out");
     cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
