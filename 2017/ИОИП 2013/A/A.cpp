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

const int MAXN = 1005;

int n, m, ans;
int gr[MAXN][MAXN];

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            char c;
            cin >> c;
            if (c == '.')  gr[i][j] = 1;
        }
}

void solution()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < m; ++j)
            if (gr[i][j] == gr[i][j+1] && gr[i][j] == 1) ans++;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j <= m; ++j)
            if (gr[i][j] == gr[i+1][j] && gr[i][j] == 1) ans++;
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
