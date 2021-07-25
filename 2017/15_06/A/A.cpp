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

int a, b, c, d, x, y, t1, t2, fl = 1;

void in()
{
    ifstream cin("input.txt");
    cin >> a >> b >> c >> d >> x >> y;
}

void solution()
{
    t1 = abs(c-a);
    t2 = abs(d-b);
    if (t1 % x != 0 || t2 % y != 0) fl = 0;
    t1 /= x;
    t2 /= y;
}

void out()
{
    ofstream cout("output.txt");
    if (t1%2 == t2%2 && fl) cout << "YES\n";
    else              cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
