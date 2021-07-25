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

const int MAXN = (int)2*1e5+15;

int n, ans;
VEC <VEC <int> > gr;
int c[MAXN];

void DFS(int v, int p)
{
    int tmp = 1;
    for (int i = 0; i < gr[v].SZ; ++i){
        int to = gr[v][i];
        if (p == to) continue;
        while (tmp == c[v] || tmp == c[p]) ++tmp;
        c[to] = tmp++;
        DFS(to, v);
    }
}

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    gr.resize(n+1);
    for (int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        gr[a].PB(b);
        gr[b].PB(a);
    }
}

void solution()
{
    c[1] = 1;
    DFS(1, 0);
    for (int i = 1; i <= n; ++i)
        ans = max(ans, c[i]);
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans << "\n";
    for (int i = 1; i < n; ++i)
        cout << c[i] << " ";
    cout << c[n] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
