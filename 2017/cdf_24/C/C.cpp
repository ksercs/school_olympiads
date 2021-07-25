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

int n, m, q;
VEC <int> ans, sum;
VEC <VEC <int> > mass, dp;

void in()
{
    //ifstream cin("input.txt");
    ios_base:: sync_with_stdio(false);
    cin >> n >> m;
    dp.resize(n+1);
    mass.resize(n+1);
    sum.resize(n+1);
    mass[0].resize(m+1);
    dp[0].resize(m+1);
    for (int i = 1; i <= n; ++i){
        mass[i].resize(m+1);
        dp[i].resize(m+1);
        for (int j = 1; j <= m; ++j){
            if (i == 1) dp[i][j] = 1;
            cin >> mass[i][j];
            if (mass[i][j] >= mass[i-1][j]) dp[i][j] =  dp[i-1][j]+1;
            else                            dp[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            sum[i] = max(sum[i], dp[i][j]);
    cin >> q;
    ans.resize(q);
    for (int i = 0; i < q; ++i){
        int L, R;
        cin >> L >> R;
        if (R - sum[R] + 1 <= L) ans[i] = 1;
    }
}

void out()
{
    //ofstream cout("output.txt");
    for (int i = 0; i < q; ++i)
        if (ans[i]) cout << "Yes\n";
        else        cout << "No\n";
}

int main()
{
    in();
    out();
    return 0;
}
