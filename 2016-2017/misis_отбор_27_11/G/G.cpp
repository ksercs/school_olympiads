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
#define LL long long

using namespace std;

const int MAXN = 500000+15;

int n, m, st, fn, FL, ans, fl = 1;

VEC < pair < PII, int> > E;
VEC <VEC < int > > gr;
VEC <int> w;

int u[MAXN];

void DFS(int v)
{
    //w.PB(v);
    //cout << " --- ";
    /*for (int i = 0; i < w.SZ; i++)
    {
        cout << w[i] << " ";
    }*/
    //cout << endl;
    u[v] = 1;
    if (v == fn) {FL = 1; return;}
    for (int i = 0; i < gr[v].SZ; i++)
    {
        int to = gr[v][i];
        if (!u[to])
        {
            DFS(to);
        }
    }
   // w.pop_back();
}

bool check(int S)
{
    //w.clear();
    //gr.clear();
    fill(u, u+n+1, 0);
   // gr.resize(n+1);
   for (int i = 1; i <= n; i++)
   {
       gr[i].clear();
   }
    FL = 0;
    for (int i = 0; i < E.SZ; i++)
    {
        if (E[i].SS >= S){
            int a = E[i].FF.FF, b = E[i].FF.SS;
            gr[a].PB(b);
            gr[b].PB(a);
        }
    }
    DFS(st);
    if (u[fn]) FL = 1;
    if (FL) { ans = max(ans, S); return true;}
    else return false;
}

void BS(int L, int R)
{
    //cout << L << " " << R << endl;
    if (L > R) return;
    int M = L + (R-L)/2;
    bool rez = check(M);
    //system("PAUSE");
    if (rez) BS(M+1, R);
    else     BS(L, M-1);
}

void in()
{
    ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    gr.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        E.PB(MP(MP(a,b),c));
        gr[a].PB(b);
        gr[b].PB(a);
    }
    cin >> st >> fn;
}

void solution()
{
    DFS(st);
    if (u[fn]) FL = 1;
    if (FL){
    BS(1, 1000000000);}
    else fl = 0;
}

void out()
{
    ofstream cout("output.txt");
   if (fl) cout << ans << endl;
   else    cout << "-1\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
