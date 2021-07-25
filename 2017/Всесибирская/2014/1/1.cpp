#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

int n, m, ans=1;

int gcd_R(int a, int b)
{
    return ( (a&&b) ? gcd_R(b, a%b) : (a|b)  );
}


void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
}

void solution()
{
    if (n == 1 || m == 1) ans = 1;
    else if (n == m) ans = n/2+1;
         else ans *= gcd_R(n,m);
    /*else ans = 2;
    if (n == m) ans = n/2+1;
    ans *= gcd_R(n,m);*/
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
