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

const int MAXN = 100+5;

int n, m, fl = 1, k;
char M[MAXN][MAXN];
VEC <int> ans;

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> M[i][j];
    cin >> k;
    for (int t = 1; t <= k; t++){
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++){
                char s;
                cin >> s;
                if (s == '*' && M[i][j] == '.' || s == '.' && M[i][j] == '*') fl = 0;
            }
        ans.PB(fl);
        fl = 1;
    }
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 0; i < ans.SZ; i++)
        (ans[i] == 1) ? cout << "YES\n" : cout << "NO\n";
}

int main()
{
    in();
    out();
    return 0;
}
