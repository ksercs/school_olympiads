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

const int MAXN = int(1e6) + 5;

int n, k, ans;
int u[MAXN];
VEC <int> cnk, num;

void DFS(int bits_cnt, int last, int cur)
{
    if (bits_cnt == k){
        cnk.push_back(cur);
        //cout << cur << "\n";
    }
    else
        for (int i = last + 1; i < 15 - k + bits_cnt; ++i)
            DFS(bits_cnt + 1, i, cur + (1 << i));
}

void in()
{
    //ifstream cin("input.txt");
    ios_base:: sync_with_stdio(false);
    cin >> n >> k;
    num.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> num[i];
}

void solution()
{
    DFS(0, -1, 0);
    /*for (int i = 0; i < cnk.SZ; ++i)
        cout << cnk[i] << " ";*/
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < cnk.SZ; ++j)
            ans += u[(cnk[j] ^ num[i])];
        ++u[num[i]];
    }
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
