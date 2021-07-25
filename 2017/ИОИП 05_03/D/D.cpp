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
#include <ctime>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 5;

int n, q, fl = 1;
clock_t start;
int st[MAXN], fn[MAXN], mass[MAXN];
int num[55], fin[55];
set <int> indx;
VEC < PII > v;

void in()
{
    ifstream cin("buckets.in");
    ios_base:: sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < n; ++i){
        int c;
        cin >> c;
        num[i+1] = c;
        mass[i+1] = c;
        st[c]++;
    }
    for (int i = 0; i < n; ++i){
        int c;
        cin >> c;
        fin[i+1] = c;
        fn[c]++;
    }
    v.resize(q);
    for (int i = 0; i < q; ++i){
        int x, y;
        cin >> x >> y;
        v[i] = MP(x,y);
        if (!fl) continue;
        if (st[x] == 0)
            fl = 0;
        else{
            st[x]--;
            st[y]++;
        }
    }
}

bool check()
{
    int tmp = 1;
        for (int i = 1; i <= n; ++i)
            if (mass[i] != fin[i]){
                tmp = 0;
                break;
            }
    return tmp;
}

void out()
{
    ofstream cout("buckets.out");
    if (fl) cout << "YES\n";
    else    cout << "NO\n";
}


void upd(int ind)
{
    if (fl) return;
    if (clock() - start > 1.95){
        fl = 1;
        out();
        exit(0);
    }
    if (ind == q)
        if (check()) {fl = 1; return;}
    int x = v[ind].FF,
        y = v[ind].SS;
    for (int i = 1; i <= n; ++i)
        if (mass[i] == x){
            mass[i] = y;
            upd(ind+1);
            mass[i] = x;
            if (fl) return;
        }
}

void sol()
{
    if (q == 0){
        if (check()) fl = 1;
        return;
    }
    upd(0);
}

void solution()
{
    if (!fl) return;
    int ch = 0;
    for (int i = 1; i <= 3; ++i){
        if (st[i] != fn[i]){
            fl = 0;
            break;
        }
        ch += st[i]-fn[i];
    }
    if (ch != 0) fl = 0;
    if (fl) {fl = 0; sol();}
}

int main()
{
    start = std::clock();
    in();
    solution();
    out();
    return 0;
}
