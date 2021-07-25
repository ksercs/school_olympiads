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
#define LL long long
#define PII pair <int,int>
#define PA pair <LL, pair <PII, PII> >
#define RSZ resize

using namespace std;

const LL INF = (LL)1e18;

int n, cnt;
LL ans;

VEC < PA > e;
VEC < PII > p;
map < PII, int> c;
map < PII, int>:: iterator it;
set < PII > st;

LL Len(PII p1, PII p2)
{
    PII v = MP(p2.FF-p1.FF, p2.SS-p1.SS);
    LL s = (LL)(1LL*v.FF*v.FF + 1LL*v.SS*v.SS);
    return s;
}

void in()
{
    ifstream cin("moocast.in");
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (c[MP(a,b)] == 0) {p[cnt] = MP(a, b); c[p[cnt]]=cnt; cnt++;}
    }
}

void solution()
{
   for (int i = 0; i < cnt-1; i++)
        for (int j = i+1; j < cnt; j++)
        {
            e.PB(MP(Len(p[i],p[j]), MP(p[i], p[j])));
        }
    sort(e.begin(), e.end());
   /* for (int i = 0; i < e.SZ; i++)
    {
        cout << e[i].FF << " <" << e[i].SS.FF.FF << "," <<e[i].SS.FF.SS << ">  " << " <" << e[i].SS.SS.FF << "," <<e[i].SS.SS.SS << ">\n";
    }
    cout << endl << endl;*/
    for (int i = 0; i < e.SZ; i++)
    {
        pair <PII, PII> pa = e[i].SS;
        if (c[pa.FF] != c[pa.SS]){
            int old = c[pa.SS], need = c[pa.FF];
            for (it = c.begin(); it != c.end(); it++)
                if (it->SS == old) {/*cout << it->SS << " ";*/ it->SS = need; /*cout << it->SS << "\n";*/}
            ans = e[i].FF;
        }
    }
}

void out()
{
    ofstream cout("moocast.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
