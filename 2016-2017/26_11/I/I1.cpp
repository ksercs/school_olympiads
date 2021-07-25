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
#define LL long long

using namespace std;

const int MAXN = 5000+15;

int n, m, X, Y, fl, ans;
int mass[MAXN][MAXN];

void in()
{
    ifstream cin("pluses.in");
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '1') {one.PB(MP(i,j+1));mass[i][j+1]=1;}
        }
    }
}

void solution()
{

}

void out()
{
    ofstream cout("pluses.out");
    if (!fl) cout << "-1\n";
    else cout << ans << "\n" << X << " " << Y << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
