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

const int MAXN = (int)1e5 + 5;

int n, fl;
int L[MAXN], R[MAXN], ans[MAXN], s[MAXN], u[MAXN], p[MAXN];
VEC < VEC <int> > gr;
VEC <int> lv;
set <int> st;

queue <int> q;

int get_s(int v)
{
    if (p[v] == 0) return 0;
    return s[v] + get_s(p[v]);
}

void BFS()
{
    while(!q.empty())
    {
        int v = q.front();
        for (int i = 0; i < gr[v].SZ; ++i){
            int to = gr[v][i];
            if (!u[to]){
                u[to] = 1;
                p[to] = v;
                q.push(to);
            }
        }
        q.pop();
    }
}

void check()
{
    for (int i = 1; i <= n; ++i){
        q.push(i);
        u[i] = 1;
        BFS();
        fill(u, u+n+1, 0);
        for (int j = 0; j < lv.SZ; ++j){
            //cout << lv[j] << "\n";
            if (i == lv[j]) continue;
            int s = get_s(lv[j]);
            st.insert(s);
            if (st.SZ > 1) {fl = 1; break;}
        }
        fill(p, p+n+1, 0);
        if (!fl) ans[i] = 1;
        fl = 0;
        st.clear();
    }
}

void DFS(int v)
{
    //cout << "V = " << v << "\n";
    if (v == n+1){
        check();
        return;
    }
    for (int i = L[v]; i <= R[v]; ++i){
        s[v] = i;
        DFS(v+1);
    }
}

void in()
{
    ifstream cin("lamps.in");
    cin >> n;
    gr.resize(n+1);
    for (int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        gr[a].PB(b);
        gr[b].PB(a);
    }
    for (int i = 1; i <= n; ++i)
        cin >> L[i] >> R[i];
}

void solution()
{
    for (int i = 1; i <= n; ++i)
        if (gr[i].SZ == 1) lv.PB(i);
    /*for (int i = 0; i < lv.SZ; ++i)
        cout << lv[i] << "\n";
    cout << "\n";*/
    DFS(1);
}

void out()
{
    ofstream cout("lamps.out");
    for (int i = 1; i < n; ++i)
        cout << ans[i] << " ";
    cout << ans[n] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
