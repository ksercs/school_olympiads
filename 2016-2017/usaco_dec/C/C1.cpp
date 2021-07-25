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

queue < PII > q;

int n, ans, ans1=1000000, ans2=1000000, fl, FL;
PII st, fn;
map <int, VEC <int > > grx, gry;
map <int, int> u, p;
map < PII, int > u1;

void get_ans1(int v)
{
    if (v == st.SS ||v == st.FF) return ;
    ans++;
    //cout << v << "\n";
    get_ans1(p[v]);
}

void get_ans2(int v)
{
    if (v == st.SS || v == st.FF) return ;
    ans++;
    //cout << v << "\n";
    get_ans2(p[v]);
}

void BFS()
{
    while (!q.empty())
    {
        int v = q.front().FF, c = q.front().SS;
        if (v == fn.FF && c ==0 || v == fn.SS && c == 1)  break;
        if (c == 0){
            for (int i = 0; i < grx[v].SZ; i++)
            {
                int to = (grx[v][i]);
                if (!u[to])
                {
                    u[to] = 1;
                    p[to] = v;
                    q.push(MP(to,1));
                }
            }
        }
        else{
            for (int i = 0; i < gry[v].SZ; i++)
            {
                int to = (gry[v][i]);
                if (!u[to])
                {
                    u[to] = 1;
                    p[to] = v;
                    q.push(MP(to,0));
                }
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
        if (u1[MP(a, b)] == 0){
        grx[a].PB(b);
        gry[b].PB(a);
        u1[MP(a,b)] = 1;
        }
    }
}

void solution()
{
    q.push(MP(st.FF,0));
    u[st.FF] = 1;
   // q.push(st.SS);
   // u[st.SS] = 1;
    BFS();
    int a = 0;
    if (u[fn.FF]) {FL = 1; get_ans1(fn.FF); ans1 = ans; ans = 0; fl = 1;}
    if (u[fn.SS]) {FL = 1; a = ans1; get_ans1(fn.SS);  ans1 = min(a, ans);}
    u.clear();
    p.clear();
    while (!q.empty()) q.pop();
    q.push(MP(st.SS,1));
    u[st.SS] = 1;
   // q.push(st.FF);
    //u[st.SS] = 1;
    BFS();
    a = 0;
    fl = 0;
    if (u[fn.FF]) {FL = 1; ans = 0; get_ans2(fn.FF); ans2 = ans; fl = 1;}
    if (u[fn.SS]) {FL = 1; a = ans2; ans = 0; get_ans2(fn.SS);  ans2 = min(a, ans);}

}

void out()
{
    ofstream cout("lasers.out");
    if (!FL)     cout << "-1\n";
    else        cout << min(ans1, ans2) << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
