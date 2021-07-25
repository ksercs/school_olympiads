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

const int MAXN = (int)2*1e5+15;

int n, x, m, cnt, del;
VEC <int> q, ans, dp;

void in()
{
    ifstream cin("longqueue.in");
    cin >> n >> x;
    q.resize(n);
    dp.resize(n);
    cin >> q[0];
    for (int i = 1; i < n; ++i){
        cin >> q[i];
        dp[i] = dp[i-1] + (q[i-1]>=x);
    }
    cin >> m;
    for (int i = 0; i < m; ++i){
        int t, ch;
        cin >> t;
        if (t != 2) cin >> ch;
        switch(t){
            case 1:{
                //cout << "1: " << ch << "\n";
                q.PB(ch);
                int sz = q.SZ-1;
                dp.PB(dp[sz-1] + (q[sz-1]>=x));
                break;
            }
            case 2:{
                if (q[del] >= x) cnt++;
                //q.erase(q.begin());
                //dp.erase(dp.begin());
                del++;
                break;
            }
            case 3:{
                //cout <<"3: " << ch << " " << dp[ch] << "\n";
                ans.PB(dp[ch+del]-cnt);
                break;
            }
        }
    }
}

void out()
{
    ofstream cout("longqueue.out");
    for (int i = 0; i < ans.SZ; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
