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

const int MAXN = int(1e5)+5;

int n, m, q, L, R, c, fl=1;
map < PII, int> col;
VEC <VEC <int> > ans;
VEC <int> way;
int u[MAXN];

void DFS(int v)
{
    u[v] = 1;
    way.PB(v);
    if (way.SZ > 100){
        fl = 0;
        return;
    }
    for (int i = L; i <= R; ++i){
        if (v == way[0]) c = -1;
        if (i == v || (c != -1 && col[MP(v,i)] != c)) continue;
        //cout << v << " " << i << " " << c << "\n"; //system("PAUSE");
        if (u[i]){
            if (i != way[way.SZ-2] && i == way[0]){
                //cout << "END!\n";
                fl = 2;
                return;
            }
        }
        else{
            //cout << "new\n";
            u[i] = 1;
            c = col[MP(v,i)];
            u[i] = 1;
            DFS(i);
            u[i] = 0;
            if (!fl || fl == 2) return;
        }
    }
    u[v] = 0;
    way.erase(--way.end());
}

void in()
{
    ifstream cin("loopquery.in");
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        col[MP(a,b)] = 1;
        col[MP(b,a)] = 1;
    }
    cin >> q;
    ans.resize(q);
    for (int i = 0; i < q; ++i){
        cin >> L >> R;
        for (int j = L; j <= R; ++j){
            //u[j] = 1;
            c = -1;
           // cout << "\nHEY!\n";
            DFS(j);
            if (fl == 2){
                ans[i] = way;
                fill(u, u+n+1, 0);
                way.clear();
                fl = 1;
                break;
            }
            fill(u, u+n+1, 0);
            way.clear();
            fl = 1;

        }
    }
}

void out()
{
    ofstream cout("loopquery.out");
    for (int i = 0; i < q; ++i){
        if (ans[i].SZ == 0) cout << "-1\n";
        else{
            cout << ans[i].SZ << " ";
            for (int j = 0; j < ans[i].SZ-1; ++j)
                cout << ans[i][j] << " ";
            cout << ans[i][ans[i].SZ-1] << "\n";
        }
    }
}

int main()
{
    in();
    out();
    return 0;
}
