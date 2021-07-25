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
#define edge pair < PII, PII >

using namespace std;

const int MAXN = 105;

int n, k, r;
LL ans;
int u[MAXN][MAXN];
int dx[] = {-1, 0, 1, 0},
    dy[] = { 0, 1, 0, -1};
set < edge > tabu;
set < PII > cow;
set < PII >:: iterator it;
VEC <int> comp;
queue < PII > q;

void in()
{
    ifstream cin("countcross.in");
    cin >> n >> k >> r;
    for (int i = 0; i <= n+1; ++i)
        for (int j = 0; j <= n+1; ++j)
             u[i][j] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            u[i][j] = 0;
    for (int i = 0; i < r; ++i){
        edge ed;
        cin >> ed.FF.FF >> ed.FF.SS >> ed.SS.FF >> ed.SS.SS;
        tabu.insert(ed);
        PII p = ed.SS;
        ed.SS = ed.FF;
        ed.FF = p;
        tabu.insert(ed);
    }
    for (int i = 0; i < k; ++i){
       int a, b;
       cin >> a >> b;
       cow.insert(MP(a,b));
    }
}

void BFS()
{
    int cnt = 0;
    while (!q.empty()){
        PII v = q.front();
        //cout << v.FF << " " << v.SS << "\n";
        if (cow.count(v)) cnt++;
        for (int i = 0; i < 4; ++i){
            int tox = v.FF + dx[i],
                toy = v.SS + dy[i];
            PII np = MP(tox, toy);
            if (!u[tox][toy] && !tabu.count(MP(v, np))){
                u[tox][toy] = 1;
                q.push(np);
            }
        }
        q.pop();
    }
    comp.PB(cnt);
}

void solution()
{
    if (cow.SZ == 0) return;
    for (it = cow.begin(); it != cow.end(); it++){
        PII v = (*it);
        int vx = v.FF, vy = v.SS;
        if (!u[vx][vy]){
            q.push(v);
            u[vx][vy] = 1;
            BFS();
        }
    }
    for (int i = 0; i < comp.SZ-1; ++i)
        for (int j = i+1; j < comp.SZ; ++j)
            ans += comp[i]*comp[j];
}

void out()
{
    ofstream cout("countcross.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
