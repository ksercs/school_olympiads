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

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>

using namespace std;

const int MAXN = 1000 + 15;

int n, m, ans;
int mass[MAXN][MAXN];

VEC <int> L(MAXN,-1), R(MAXN,-1), U(MAXN,-1), D(MAXN,-1);

void in()
{
    //ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mass[i][j];
            if (mass[i][j]) {
                if (L[i] == -1) L[i] = j;
                R[i] = j;
                if (U[j] == -1) U[j] = i;
                D[j] = i;
            }
        }
    }
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!mass[i][j])
            {
                if (L[i] != -1 && L[i] < j) ans++;
                if (R[i] > j) ans++;
                if (U[j] != -1 && U[j] < i) ans++;
                if (D[j] > i) ans++;
            }
        }
    }
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
