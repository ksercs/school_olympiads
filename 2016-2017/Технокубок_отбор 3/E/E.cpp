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

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = (int)1e6+50;

int n, k;
int a[MAXN];
LL ans, L, R = (LL)1e13, M;

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void solution()
{
    while (R-L > 1){
        //cout << L << " " << R << "\n";
        M = L + (R-L)/2;
        LL cnt = 0;
        for (int i = 1; i <= n; i++) cnt += a[i]/M;
        if (cnt >= k) L = M;
        else          R = M;
    }
    if (R == 0) ans = -1;
    else
    {
        LL cnt = 0;
        for (int i = 1; i <= n; i++) cnt += a[i]/R;
        if (cnt >= k) ans = R;
        else          ans = L;
    }
    if (ans == 0) ans = -1;
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
