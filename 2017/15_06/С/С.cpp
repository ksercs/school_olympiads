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

LL n, s, ans;

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> s;
}

LL sum (LL c)
{
    LL res = 0;
    while (c > 0){
        res += c%10;
        c /= 10;
    }
    return res;
}

void solution()
{
    if (s > n) return;
    LL ch = s;
    while (ch - sum(ch) < s) ++ch;
    ans = max(0*1LL, n-ch+1);
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
