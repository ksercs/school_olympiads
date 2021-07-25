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

const int MAXN = int(1e5+15);

int n, k, r, ans = MAXN;
VEC <int> v;
int dp[MAXN];

void in()
{
    ifstream cin("maxcross.in");
    cin >> n >> k >> r;
    v.resize(r);
    for (int i = 0; i < r; ++i)
        cin >> v[i];
}

void solution()
{
    sort(v.begin(), v.end());
    for (int i = 1; i < v.SZ; ++i)
        for (int j = v[i-1]; j < v[i]; ++j)
            dp[j] = dp[v[i-1]-1] + 1;
    for (int i = v[v.SZ-1]; i <= n; ++i)
        dp[i] = dp[v[v.SZ-1]-1]+1;
    //for (int i = 1; i <= n; ++i)
    //    cout << dp[i] << " ";
    //cout << "\n";
    for (int i = 1; i <= n-k+1; ++i)
        ans = min(ans, dp[i+k-1]-dp[i-1]);
        //cout << i-1 << " " << i+k-1 << " "  << dp[i+k+1]-dp[i-1] << "\n";
}

void out()
{
    ofstream cout("maxcross.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
