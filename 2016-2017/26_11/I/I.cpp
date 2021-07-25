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
int mass[MAXN][MAXN], Left[MAXN][MAXN], Left[MAXN][MAXN];

VEC < PII > one;

void get_ans( PII koor )
{
    int M = 100000, sz = 0, ch = 0, c = 0, r = 0;
    int x = koor.FF, y = koor.SS;
   // cout <<"X,Y: " << x << " " << y << endl;
    sz = 1; ch = 0;
    c = y; r = x-1;
    //if (x == 4 && y == 4) cout <<"MASS = " << mass[r][c] << endl;
    if (dp[c][r] != 0) ch = dp[c][r];
    else{
    while (ch <= M && r > 0 && mass[r][c])
    {
        ch++;
        r--;
    }}
    //cout << ch << " ";
    //if (x == 4 && y == 4) cout << ch << endl;
    M = min(M,ch); ch = 0;
    c = y; r = x+1;
        if (dp[c][r] != 0) ch = dp[c][r];
    else{
    while (ch <= M && r <= n && mass[r][c])
    {
        ch ++;
        r++;
    }}
    //cout << ch << " ";
   // if (x == 4 && y == 4) cout << ch << endl;
    M = min(M,ch); ch = 0;
    c = y-1; r = x;
        if (dp[c][r] != 0) ch = dp[c][r];
    else{
    while (ch <= M && c > 0 && mass[r][c])
    {
        ch ++;
        c--;
    }}
   // cout << ch << " ";
    //if (x == 4 && y == 4) cout << ch << endl;
    M = min(M,ch); ch = 0;
    c = y+1; r = x;
        if (dp[c][r] != 0) ch = dp[c][r];
    else{
    while (ch <= M && c <= m && mass[r][c])
    {
        ch ++;
        c++;
    }}
    //cout << ch << "\n";
    //if (x == 4 && y == 4) cout << ch << endl;
    M = min(M,ch);
    sz += 4*M;
    //cout << x << " " << y << " " << sz << endl;
    if (sz > ans) {ans = sz; X = x; Y = y;}
}

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
  if (one.SZ != 0) fl = 1;
  if (fl)
  {
      for (int i = 0; i < one.SZ; i++)
      {
          //cout <<"-----" << one[i].FF << " " << one[i].SS << endl;
          get_ans(one[i]);
      }
  }
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
