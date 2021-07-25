#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>


using namespace std;

long long f, r, ans;

void in()
{
    ifstream cin ("game.in");
    cin >>f >>r;
}

void solution()
{
     if (r%2!=0 && f%2!=0)     {ans=(r-f)/2;}
     else      {ans=(r-f)/2+1;}
}

void out()
{
     ofstream cout ("game.out");
     cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
