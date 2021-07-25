#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <utility>

#define mp make_pair
#define ss second
#define ff first
#define pii pair <int, int>
#define pb push_back
#define SZ size()
#define vec vector
#define sp " "

using namespace std;

const int MAXN = (int)2*1e5+5;

int n, m, st, fn, ch=-1, tinp, toutp, tinv, toutv;

int used[MAXN], p[MAXN], tin[MAXN], tout[MAXN];

vec <vec <int> > gr;
vec <int> ans, vect;

pii BS_R(int L, int R, int vi, int vo)
{
    //cout << L << sp << R << endl;
    if (L > R)  return mp(L, 0);
    int mid = L+(R-L)/2;
    int M = vect[mid];
    if (tin[M] <= vi && tout[M] >= vo)   return mp(mid,1);
    if (tin[M] <= vi)    return BS_R(mid+1, R, vi, vo);
    if (tout[M] >= vo)   return BS_R(L, mid-1, vi, vo);
}

bool pred(int pr, int ver)
{
    if (tin[pr] <= tin[ver] && tout[ver] <= tout[pr]) return true;
    return false;
}

int get_ans(int s, int f)
{
    if ( !(pred(s,f)) ) return p[s];
    vect = gr[s];
    pii pa = BS_R(0,vect.SZ-1, tin[f], tout[f]);
    return vect[pa.ff];
}

void DFS(int v)
{
    ch++;
    tin[v] = ch;
    for (int i = 0; i < gr[v].SZ; i++)
    {
        int to = gr[v][i];
        if (!used[to])
        {
            used[to] = 1;
            p[to] = v;
            DFS(to);
            used[to] = 0;
        }
    }
    ch++;
    tout[v] = ch;
}

void in()
{
    ifstream cin ("treefirstedge.in");
    cin >> n;
    gr.resize(n+1);
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    used[1] = 1;
    DFS(1);
    /*for (int i = 1; i <= n; i++)
    {
        cout << p[i] << sp << tin[i] << sp << tout[i] << endl;
    }*/
    cin >> m;
    ans.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> st >> fn;
        ans[i] = get_ans(st, fn);
    }
}

void out()
{
     ofstream cout ("treefirstedge.out");
     for (int i = 0; i < m; i++)
     {
         cout << ans[i] << endl;
     }
}

int main()
{
    in();
    out();
return 0;
}
