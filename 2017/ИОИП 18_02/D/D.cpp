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

const int MAXN = int(5*1e4)+5;

int n, ans, sz, len;
VEC <VEC <int> > gr;
char col[MAXN];
int u[MAXN];
VEC <int> way;
string sq, s;

set < PII > st;

void check()
{
    /*for (int i = 0; i < sz; ++i){
        //cout << way[i] << " ";
        sq += col[way[i]];
    }*/
    //cout << "\n";
    //cout << sq << "\n\n";
    int res = sz;
    for (int i = 0; i < sz-1; ++i)
        for (int j = 2; j <= min(sz-i, res+1); ++ j){
            string s1 = sq.substr(i,j);
            //cout << s1 << "\n";
            string s2 = s1;
            reverse(s1.begin(), s1.end());
            if (s1 == s2) {
                res = min(res, j-1);
                break;
            }
        }
    ans = max(ans, res);
    sq.clear();
    //cout << "\n";
}

void get_M(int ind)
{
    if (ind == len){
        for (int i = 0; i < len; ++i)
            if (s[i] == '1') sq += col[way[i]];
        sz = sq.SZ;
        if (sq.SZ > 1) check();
        return;
    }
    s[ind] = '0';
    get_M(ind+1);
    s[ind] = '1';
    get_M(ind+1);
}

void get_ans()
{
    len = way.SZ;
    s.clear();
    for (int i = 0; i < len; ++i)
        s += '0';
    get_M(0);
}

void DFS (int v)
{
    u[v] = 1;
    way.PB(v);
    /*for (int i = 0; i < way.SZ; ++i)
        cout << way[i] << " ";
    cout << "\n";*/
    if (gr[v].SZ == 1 && gr[v][0] == way[way.SZ-2] && !(st.count(MP(way[0],v))) ){ st.insert(MP(way[0],v)); st.insert(MP(v,way[0])); get_ans();}
    for (int i = 0; i < gr[v].SZ; ++i){
        int to = gr[v][i];
        if (!u[to]){
            u[to] = 1;
            DFS(to);
            u[to] = 0;
        }
    }
    u[v] = 0;
    way.erase(--way.end());
}

void in()
{
    ifstream cin("canderlabrum.in");
    ios_base:: sync_with_stdio(false);
    cin >> n;
    gr.resize(n+1);
    for (int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        gr[a].PB(b);
        gr[b].PB(a);
    }
    string str;
    cin >> str;
    for (int i = 0; i < n; ++i)
        col[i+1] = str[i];
}

void solution()
{
    for (int i = 1; i <= n; ++i)
        if (gr[i].SZ == 1) DFS(i);
}

void out()
{
    ofstream cout("canderlabrum.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
