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

const int MAXN = (int)1e5+15;

int n;
LL k, s;
double ans;
LL mass[MAXN];

void in()
{
    ifstream cin("tallbarn.in");
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> mass[i];
        s += mass[i];
    }
}

void solution()
{
    k -= n;
    for (int i = 1; i <= n; i++){
        LL cnt = 1 + (LL)round(1.0*mass[i]/s*k) ;
        ans += 1.0*mass[i]/cnt;
        //cout << mass[i] << " " << cnt << "\n";
    }
    ans = round(ans);
}

void out()
{
    ofstream cout("tallbarn.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
