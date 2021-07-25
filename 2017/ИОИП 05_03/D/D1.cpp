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

const int MAXN = 55;

int n, q, fl;
int st[MAXN], fn[MAXN];
VEC < PII > v;

void in()
{
    ifstream cin("buckets.in");
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> st[i];
    for (int i = 1; i <= n; ++i)
        cin >> fn[i];
    v.resize(q);
    for (int i = 0; i < q; ++i)
        cin >> v[i].FF >> v[i].SS;
}

bool check()
{
    int tmp = 1;
        for (int i = 1; i <= n; ++i)
            if (st[i] != fn[i]){
                tmp = 0;
                break;
            }
    return tmp;
}

void upd(int ind)
{
    if (fl) return;
    if (ind == q)
        if (check()) {fl = 1; return;}
    int x = v[ind].FF,
        y = v[ind].SS;
    for (int i = 1; i <= n; ++i)
        if (st[i] == x){
            st[i] = y;
            upd(ind+1);
            st[i] = x;
            if (fl) return;
        }
}

void solution()
{
    if (q == 0){
        if (check()) fl = 1;
        return;
    }
    upd(0);
}

void out()
{
    ofstream cout("buckets.out");
    if (fl) cout << "YES\n";
    else    cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
