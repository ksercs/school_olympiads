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

int n, m, ans = -1, L = 105, R, D, U = 105, cnt, len;

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            char a;
            cin >> a;
            if (a == 'B'){
                ++cnt;
                if (L > j) L = j;
                if (R < j) R = j;
                if (U > i) U = i;
                if (D < i) D = i;
            }
        }
    //cout << L << " " << R << " " << D << " " << U << "\n";
    if (!cnt){
        ans = 1;
        return;
    }
    len = max(R-L+1, D-U+1);
    if (n < len || m < len) return;
    ans = len*len - cnt;
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
