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

int n, m, ans = MAXN;
int C[MAXN], u[MAXN];
set <int> c;
set <int>:: iterator it;
VEC <VEC <int> > gr;
queue < int > q;

void BFS()
{
    while(!q.empty()){
        int v = q.front();
        int cost = C[v];
        int d = u[v];
        for (int i = 0; i < gr[v].SZ; i++){
            int to = gr[v][i];
            if (u[to] == -1){
                q.push(to);
                u[to] = d+1;
                C[to] = C[v];
            }
            else if (C[v] != C[to] && C[to] != 0) {ans = u[v]+u[to]+1; return;}
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
        if (w != 0) c.insert(i);
        C[i] = w;
    }
    for (int i = 0; i < m; i++){
        int a, b;
        //cin >> a >> b;
        fscanf(file, "%d %d", &a, &b);
        gr[a].PB(b);
        gr[b].PB(a);
        if (C[a] && C[b] && C[a] ^ C[b])
        {
            ans = 1;
            return;
        }
    }
}

void solution()
{
    memset(u, -1, sizeof(u));
    for (it = c.begin(); it != c.end(); it++){
        int v = (*it);
        q.push(v);
        u[v] = 0;
    }
    BFS();
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
    if (ans != 1) solution();
    out();
    return 0;
}
