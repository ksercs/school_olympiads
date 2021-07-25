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

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = (int)1e5+15;

queue <int> q;

int n, ans=1000000, answer;
PII st, fn;
map <int, VEC <int > > gr1, gr2;
map <int, int> p, u;

void get_ans(int v)
{
    if (v == 0) return;
    cout << v << endl;
    answer++;
    get_ans(p[v]);
}

void BFS1()
{
    while (!q.empty())
    {
        int v = q.front();
        if (v == fn.FF || v == fn.SS) break;
        if (gr1[v].SZ > 0)
            for (int i = 0; i < gr1[v].SZ; i++)
            {
                int to = (gr1[v][i]);
                if (!u[to])
                {
                    u[to] = 1;
                    p[to] = v;
                    q.push(to);
                }
            }
        q.pop();
    }
}

void BFS2()
{
    while (!q.empty())
    {
        int v = q.front();
        if (v == fn.FF || v == fn.SS) break;
        if (gr2[v].SZ > 0)
            for (int i = 0; i < gr2[v].SZ; i++)
            {
                int to = (gr1[v][i]);
                if (!u[to])
                {
                    u[to] = 1;
                    p[to] = v;
                    q.push(to);
                }
            }
        q.pop();
    }
}

void in()
{
    ifstream cin("lasers.in");
    cin >> n >> st.FF >> st.SS >> fn.FF >> fn.SS;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        gr1[a].PB(b);
        gr2[b].PB(a);
    }
}

void solution()
{
    if (fn.FF == 0 || fn.SS == 0) return;
    q.push(0);
    u[0] = 1;
    BFS1();
    if (u[fn.FF]) {get_ans(fn.FF); answer--; ans = min(answer, ans);}
    if (u[fn.SS]) {answer = 0; get_ans(fn.SS); answer--; ans = min(answer, ans);}
    while (!q.empty())
        q.pop();
    p.clear();
    u.clear();
    u[0] = 1;
    q.push(0);
    BFS2();
    if (u[fn.FF]) {get_ans(fn.FF); answer--; ans = min(answer, ans);}
    if (u[fn.SS]) {answer = 0; get_ans(fn.SS); answer--; ans = min(answer, ans);}
}

void out()
{
    ofstream cout("lasers.out");
    if (ans == 1000000) cout << "-1\n";
    else                cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
