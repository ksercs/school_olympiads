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

const int MAXN = (int)1e5+5, MAXNUM = (int)1e4+15;

int n, ans, ind, best, fst;
VEC <int> arr, last(MAXNUM, -1), p, dp, ou;

void in()
{
    ifstream cin("input.txt");
    ios_base:: sync_with_stdio(false);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
}

void solution()
{
    p.resize(n, -1);
    dp.resize(n, 1);
    for (int i = 0; i < n; ++i){
        best = -1;
        for (int j = 1; j*j <= arr[i]; j++){
            if (arr[i]%j == 0){
                if (last[j] > -1 && best < dp[last[j]]){
                    best = dp[last[j]];
                    ind = last[j];
                }
                if (last[arr[i]/j] > -1 && best < dp[last[arr[i]/j]]){
                    best = dp[last[arr[i]/j]];
                    ind = last[arr[i]/j];
                }
            }
        }
        if (best != -1){
            p[i] = ind;
            dp[i] = dp[ind]+1;
        }
        last[arr[i]] = i;
    }
    ind = 0;
    for (int i = 0; i < n; i++)
        if (dp[i] > ans){
            ans = dp[i];
            ind = i;
        }
    while (ind != -1){
        ou.PB(ind);
        ind = p[ind];
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
    for (int i = ou.SZ-1; i > 0; --i)
        cout << ou[i]+1 << " ";
    cout << ou[0]+1 << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
