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

const int MAXN = 405;

int n, mp, pr, v1, v2, ch;
VEC < set <int> > gr;//, obgr;
set <int>:: iterator it;

int p[MAXN], u[MAXN];

void DFS(int v)
{
    //cout << " V = " << v << " :\n";
    u[v] = 1;
    for(set <int>:: iterator it1 = gr[v].begin(); it1 != gr[v].end(); it1++){
        int to = (*it1);
       // cout << " -- " << to << "\n"; system("PAUSE");
        if (!u[to]) {
            ch++;
            u[to] = 1;
            if (gr[to].SZ > 0) DFS(to);
        }
    }
}

void get_ans(int r1, int r2)
{
    int V;
    for (int i = 1; i <= n; i++){
        if (gr[i].SZ == 0) continue;
        //cout << i << " : \n";
        DFS(i);
        //cout << "\n";
        memset(u, 0, sizeof(u));
        if (ch > mp){
            mp = ch;
            pr = i;
            v1 = r1;
            v2 = r2;
        }
        ch = 0;
    }
}


void in()
{
    ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin >> n;
    gr.resize(n+1);
    //obgr.resize(n+1);
    for (int i = 1; i <= n; ++i){
        int k;
        cin >> k;
        for (int j = 0; j < k; j++){
            int a;
            cin >> a;
            //cout << a << "\n";
            gr[i].insert(a);
            //obgr[gr[i][j]].PB(i);
        }
    }
}

void solution()
{
    get_ans(1,2);
    for (int i = 1; i <= n; ++i){
        //cout << gr[i].SZ << "\n";
        if (gr[i].SZ > 0){
            int k = gr[i].SZ;
            int fl = 0;
            it = gr[i].begin();
            while (1){
                if (fl == k) break;
                int a = (*it);
                //cout << " -- " << a << "\n";
                if (gr[a].SZ > 0) if (gr[a].count(i)) {fl++; it++; continue;}
                gr[i].erase(a);
                gr[a].insert(i);
                //cout << " - START - : " << i << " " << a << "\n";
                get_ans(i, a);
                //cout << "\n";
                gr[a].erase(i);
                gr[i].insert(a);
                fl++;
                it++;
            }
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << mp << " " << v1 << " " << v2 << " " << pr << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
