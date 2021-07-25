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

LL n, k, ans;

void in()
{
    ifstream cin("pairs.in");
    cin >> n >> k;
}

void solution()
{
    if (n == 1 || k <= 2) return;
    if (n >= k) {ans = k/2 - (k%2==0); return;}
    if (n > k/2) {ans = n-k/2; return;}
}

void out()
{
    ofstream cout("pairs.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
