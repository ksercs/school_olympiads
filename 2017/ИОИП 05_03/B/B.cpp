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

const int MAXN = (int)1e5+5;

struct vertex
{
    int L;
    int R;
    int val;
};

LL ans;
int n, q, lv, ch;
vertex tr[(1<<22)];
multiset <int> cnt, num;

void count_leav()
{
    lv = 1;
    while (lv < n)
        lv *= 2;
}

void iniz()
{
    for (int i = 2*lv-1; i >= lv; --i){
        tr[i].L = i-lv+1;
        tr[i].R = i-lv+1;
    }
    for (int i = lv-1; i >= 1; --i){
        tr[i].L = tr[i*2].L;
        tr[i].R = tr[i*2+1].R;
    }
}

void upd(int v, int L, int R)
{
    if (L != tr[v].L || R != tr[v].R){
        int M = tr[v*2].R;
        if (R <= M) upd(v*2, L, R);
        else
            if (L > M) upd(v*2+1, L, R);
            else{
                upd(v*2, L, M);
                upd(v*2+1, M+1, R);
            }
    }
    else
        tr[v].val++;
}

void DFS(int v)
{
    if (v > lv-1+n) return;
    ch += tr[v].val;
    if (tr[v].L == tr[v].R)
        cnt.insert(ch);
    else{
        DFS(v*2);
        DFS(v*2+1);
    }
    ch -= tr[v].val;
}

void in()
{
    ifstream cin("loganqueries.in");
    cin >> n >> q;
    count_leav();
    iniz();
    for (int i = 1; i <= n; ++i){
        int a;
        cin >> a;
        num.insert(a);
    }
    for (int i = 0; i < q; ++i){
        int L, R;
        cin >> L >> R;
        upd(1, L, R);
    }
    /*for (int i = 2*lv-1; i >= 1; --i)
        cout << tr[i].L << " " << tr[i].R << "\n";*/
}

void solution()
{
    /*for (int i = 2*lv-1; i >= 1; --i)
        cout << tr[i].val << "\n";*/
    DFS(1);
    multiset <int>:: iterator it, c;
    c = num.begin();
    for (it = cnt.begin(); it != cnt.end(); it++){
        ans += 1LL*(*it)*(*c);
        c++;
        //cout << (*it) << " ";
    }
}

void out()
{
    ofstream cout("loganqueries.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
