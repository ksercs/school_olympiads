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
#include <climits>
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

const int MAXN = (int)1e6 + 15;

int n;
map <int, VEC <int> > mp;
LL ans = LLONG_MIN, ansL, ansR, answer = LLONG_MIN, ind;
LL sum[MAXN];

void in()
{
    ifstream cin("input.txt");
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        sum[i] = sum[i-1]+a;
        mp[a].PB(i);
        if (a > answer){
            answer = a;
            ind = i;
        }
    }
}

void solution()
{
    for (auto item : mp){
        if (item.SS.SZ == 1)
            continue;
        LL s = 0, min_pos = -1;
        for (int i = 1; i < item.SS.SZ; ++i){
                s += sum[item.SS[i]]-sum[item.SS[i-1]-1] + (-sum[item.SS[i-1]]+sum[item.SS[i-1]-1])*(i != min_pos+1);
                //cout << s << "\n";
                if (s > ans) {
                    ans = s;
                    ansL = item.SS[min_pos+1];
                    ansR = item.SS[i];
                }

                if (s < 0) {
                    s = 0;
                    min_pos = i;
                }
        }
    }
    if (ans < answer){
        ans = answer;
        ansL = ind;
        ansR = ind;
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n" << ansL << " " << ansR << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
