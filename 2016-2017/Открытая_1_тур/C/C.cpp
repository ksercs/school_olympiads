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
#include <stdio.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

FILE* file;

const int MAXN = (int)1e6+15;

int n, m, ans = MAXN, ch;
int u[MAXN], C[MAXN];
map <int, VEC <int> > c;
map <int, VEC <int> >:: iterator it;
VEC <VEC <int> > gr;
queue < PII > q;

void BFS()
{
    int s = 0;
    while(!q.empty()){
        PII p = q.front();
        int v = p.FF;
        //cout << "--" << v << "\n";
        if (C[v] != 0 && C[v] != ch) {ans = min(ans, p.SS); break;}
        for (int i = 0; i < gr[v].SZ; i++){
            int to = gr[v][i];
            if (!u[to]){
                q.push(MP(to,p.SS+1));
                u[to] = 1;
            }
        }
        q.pop();
    }
}

void in()
{
    //ifstream cin("input.txt");
    ios_base:: sync_with_stdio(false);
    file = fopen("input.txt", "r");
    //cin >> n >> m;
    fscanf(file, "%d %d", &n, &m);
    gr.resize(n+1);
    for (int i = 1; i <= n; i++){
        int w;
        fscanf(file, "%d", &w);
        //cin >> w;
        c[w].PB(i);
        C[i] = w;
    }
    for (int i = 0; i < m; i++){
        int a, b;
        //cin >> a >> b;
        fscanf(file, "%d %d", &a, &b);
        gr[a].PB(b);
        gr[b].PB(a);
    }
}

void solution()
{
    it = c.begin();
    if (it -> FF == 0) it++;
    for (; it != c.end(); it++){
        int w = it -> FF;
        //if (w == 0) continue;
        ch = w;
        //cout << w << ": \n";
        VEC <int> ver = (it -> SS);
        for (int j = 0; j < ver.SZ; j++){
            int v = ver[j];
            q.push(MP(v,0));
            u[v] = 1;
        }
        BFS();
        memset(u, 0, sizeof(u));
        while (!q.empty()) q.pop();
    }
}

void out()
{
    //ofstream cout("output.txt");
    file = fopen("output.txt", "w");
    //cout << ans << "\n";
    fprintf(file, "%d\n", ans);
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
