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

const int MAXN = 150000+15;

int n, m, fl, ch = 1, st, tmp = MAXN;

VEC <VEC <int> > gr;
VEC < PII > v;
map < PII, VEC<int> > mp;
map < PII, int > cnt;
int u[MAXN];
queue <int> q;

void DFS(int v)
{
    //cout << v << "\n";
    u[v] = 1;
    for (int i = 0; i < gr[v].SZ; ++i){
        int to = gr[v][i];
        //cout << " ?  FROM " << v << " to " << to << "\n";
        if (/*!u[to] &&*/  mp[MP(v,to)].SZ < cnt[MP(v,to)]){
            u[to] = 1;
            mp[MP(v,to)].PB(ch);
            mp[MP(to,v)].PB(ch);
            //cout << "  TO = " << to << " " << ch << "\n";
            ch++;
            DFS(to);
            u[to] = 0;
        }
    }
    u[v] = 0;
}

void BFS()
{
    while (!q.empty())
    {
        int ver = q.front();
        q.pop();
        //cout << ver << "\n";
        for (int i = 0; i < gr[ver].SZ; ++i){
            int to = gr[ver][i];
            if (!u[to] || mp[MP(ver,to)].SZ < cnt[MP(ver,to)]){
                u[to] = 1;
                q.push(to);
                mp[MP(ver,to)].PB(ch);
                mp[MP(to,ver)].PB(ch);
                ch++;
            }
        }
    }
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
    v.resize(m);
    gr.resize(n+1);
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        v[i] = MP(a, b);
        gr[a].PB(b);
        gr[b].PB(a);
        cnt[MP(a,b)]++;
        cnt[MP(b,a)]++;
    }
}

void solution()
{
    for (int i = 1; i <= n; ++i){
        if (gr[i].SZ == 1)
            fl++;
        if (gr[i].SZ < tmp){
            tmp = gr[i].SZ;
            st = i;
        }
    }
    if (fl > 1 && n != 2){
        fl = 0;
        return;
    }
    fl = 1;
    //u[st] = 1;
    //q.push(st);
    //BFS();
    DFS(st);
}

void out()
{
    ofstream cout("output.txt");
    if (fl) for (int i = 0; i < m; ++i){
        cout << mp[v[i]][0] << "\n";
        mp[v[i]].erase(mp[v[i]].begin());
        mp[MP(v[i].SS, v[i].FF)].erase(mp[MP(v[i].SS, v[i].FF)].begin());
    }
    else    cout << "IMPOSSIBLE\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
