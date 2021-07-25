#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int ans, n, m, p, P;

void in()
{
    ifstream cin ("rectangle.in");
    cin >> n >> m >> p;
}

void solution()
{
    P = 2*(n+m);
    if (n > 2)
    {
        if (p==P+4*m) {ans=1;}
    }
    if (m > 2)
    {
         if (p==P+4*n) {ans=1;}
    }
    for (int i = 1; i < n; i++)
    {
       if (p == P+2*(m+n-i)) {ans = 1;}
    }
    for (int i = 1; i < m; i++)
    {
        if (p == P+2*(n+m-i)) {ans = 1;}
    }
}

void out()
{
     ofstream cout ("rectangle.out");
     if (ans == 1) {cout <<"YES\n";}
     else          {cout <<"NO\n";}
}

int main()
{
    in();
    solution();
    out();
return 0;
}
