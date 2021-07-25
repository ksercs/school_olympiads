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

LL a, b, ans;

LL fac (LL ch)
{
    LL res = 1;
    for (int i = 2; i <= ch; ++i)
        res *= i;
    return res;
}

void in()
{
    //ifstream cin("input.txt");
    cin >> a >> b;
}

void solution()
{
    ans = fac(min(a,b));
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
