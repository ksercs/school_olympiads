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

const int MAXN = 150000 + 15;

int n, m, ans = 1, w;
int u[MAXN], p[MAXN];
VEC <set <int> > gr;

void DFS(int v)
{
    u[v] = 1;
    w++;
    if (w > 2){
        if (!gr[v].count(p[p[v]])) {ans = 0; return;}
    }
    for (set <int>:: iterator it = gr[v].begin(); it != gr[v].end(); it++){
        int to = (*it);
        if (!u[to]) {
            p[to] = v;
            DFS(to);
        }
        else{
            if (u[to] == 2){
            if (w > 1)
                if (!gr[to].count(p[v])) {ans = 0; return;}
            }
        }
        if (!ans) return;
    }
    u[v] = 2;
    w--;
}

void in()
{
    //ifstream cin("input.txt");
    ios_base:: sync_with_stdio(false);
    cin >> n >> m;
    gr.resize(n+1);
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        gr[a].insert(b);
        gr[b].insert(a);
    }
}

void solution()
{
    for (int i = 1; i <= n; ++i)
        if (gr[i].SZ > 0 && !u[i]) {DFS(i); w = 0;/* way.clear();*/}
}

void out()
{
    //ofstream cout("output.txt");
    if (ans) cout << "YES\n";
    else     cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
