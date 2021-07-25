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
#include <stack>

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

int n, k, fl = 1;
VEC <int> need, ans;
VEC <VEC <int> > gr;
int u[MAXN];
stack <int> way;

void DFS()
{
    /*cout << v << "\n";
    u[v] = 1;
    for (int i = 0; i < gr[v].SZ; ++i){
        if (!fl) return;
        int to = gr[v][i];
        if (!u[to]){
            u[to] = 1;
            DFS(to);
        }
        else if (!ver.count(to)){
            fl = 0;
            return;
        }
    }
    ans.PB(v);
    ver.insert(v);*/
    while (!way.empty() && fl){
        int tmp = 0;
        int v = way.top();
        //cout << v << "\n";
        if (u[v] == 2) {way.pop(); continue;}
        u[v] = 1;
        for (int i = 0; i < gr[v].SZ; ++i){
            if (!fl) return;
            int to = gr[v][i];
            if (!u[to]){
                //u[to] = 1;
                tmp = 1;
                way.push(to);
            }
            else if (u[to] == 1){
                fl = 0;
                return;
            }
        }
        if (!tmp){
            ans.PB(v);
            u[v] = 2;
            way.pop();
        }
    }
}

void in()
{
    //ifstream cin("input.txt");
    ios_base:: sync_with_stdio(false);
    cin >> n >> k;
    need.resize(k);
    gr.resize(n+1);
    for (int i = 0; i < k; ++i)
        cin >> need[i];
    for (int i = 1; i <= n; ++i){
        int t;
        cin >> t;
        gr[i].resize(t);
        for (int j = 0; j < t; ++j){
            int to;
            cin >> gr[i][j];
        }
    }
}

void solution()
{
    for (int i = 0; i < k; ++i){
        way.push(need[i]);
        if (!u[need[i]]) DFS();
        if (!fl) break;
    }
}

void out()
{
    //ofstream cout("output.txt");
    if (!fl) cout << "-1\n";
    else{
        //reverse(ans.begin(), ans.end());
        cout << ans.SZ << "\n";
        for (int i = 0; i < ans.SZ-1; ++i)
            cout << ans[i] << " ";
        cout << ans[ans.SZ-1] << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
