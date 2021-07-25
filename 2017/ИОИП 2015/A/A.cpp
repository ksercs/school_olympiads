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

const int MAXN = 1000 + 5;

int n, s, ans;
int c[MAXN];

void in()
{
    ifstream cin("cubes.in");
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> c[i];
        s += c[i];
    }
}

void solution()
{
    int dop = (s%n >= 1.0*n/2);
    int m = s/n + dop;
    int need;
    sort(c+1, c+n+1);
    dop ? need = n-s%n : need = s%n;
    int nw = need;
    if (dop)
        for (int i = 1; i <= n; ++i){
            int a = m-c[i];
            if (a < nw){
                c[i] = m;
                nw -= a;
            }
            else{
                c[i] += nw;
                nw = 0;
                break;
            }
        }
    else{
        for (int i = n; i >= 0; --i){
            int a = c[i]-m;
            if (a < nw){
                c[i] = m;
                nw -= a;
            }
            else{
                c[i] -= nw;
                nw = 0;
                break;
            }
        }
    }
    /*for (int i = 1; i <= n; ++i)
        cout << c[i] << " ";*/
    for (int i = 1; i <= n; ++i)
        ans += abs(c[i]-m);
    ans /= 2;
    ans += need;
}

void out()
{
    ofstream cout("cubes.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
