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

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

LL n, ans;

void in()
{
    ifstream cin("suitcase.in");
    cin >> n;
}

void solution()
{
    ans = n*(n+1)/2;
   // if ( n > 8) ans--;
   n -= 6;
   if (n%4 == 0 || n%4 == 3) ans--;
   n+=6;
}

void out()
{
    ofstream cout("suitcase.out");
    if (n < 7)  cout << "0\n";
    else        cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
