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
#define PA pair <pair <int,int>, int>
#define LL long long

using namespace std;

int n, ans, ch;
VEC < PA > ed;
map < PII, VEC<PII> > gr;
map <PII, int> u;

void DFS(PII v)
{
    //cout << v.FF << " " << v.SS << " " << ch  << endl;
    u[v] = 1;
    ch ++;
    for (int i = 0; i < gr[v].SZ; i++)
    {
        PII to = gr[v][i];
        if (!u[to]) {
            u[to]=1;
            DFS(to);
           // u[to]=0;
        }
    }
    //u[v]=0;
}

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
    ed.resize(n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ed[i]=(MP(MP(a,b), c));
    }
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            //if (i == j) continue;
            LL s = Len(ed[i].FF, ed[j].FF);
            if ( s <= 1LL*ed[i].SS*ed[i].SS){
                gr[ed[i].FF].PB(ed[j].FF);
                //gr[ed[j].FF].PB(ed[i].FF);
            }
            if (s <= 1LL*ed[j].SS*ed[j].SS) gr[ed[j].FF].PB(ed[i].FF);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!u[ed[i].FF]) DFS(ed[i].FF);
        ans = max(ans, ch);
        ch = 0;
        u.clear();
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
