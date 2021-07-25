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
#define LD long double

using namespace std;

int n, q;
VEC < PII > m;
VEC <int> s;
VEC < PII > p;
PII T;

LD ans;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    p.resize(n+1);
    s.resize(n+1);
    m.resize(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> m[i].FF >> m[i].SS >> s[i];
    cin >> q;
    p.resize(q+1);
    for (int i = 1; i <= q; ++i)
        cin >> p[i].FF >> p[i].SS;
    cin >> T.FF >> T.SS;
}

void solution()
{
    for (int i = 1; i <= q; ++i){
        LD ch = 1e18;
        for (int j = 1; j <= n; ++j){
            LD v = sqrt(1LL*(p[i].FF-m[j].FF)*(p[i].FF-m[j].FF) + 1LL*(p[i].SS-m[j].SS)*(p[i].SS-m[j].SS))/s[j];
            ch = min(ch, v);
        }
        LD S = sqrt(1LL*(p[i].FF-T.FF)*(p[i].FF-T.FF) + 1LL*(p[i].SS-T.SS)*(p[i].SS-T.SS));
        ans = max(ans, S/ch);
    }
}

void out()
{
    ofstream cout("output.txt");
    cout.precision(12);
    cout << fixed << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
