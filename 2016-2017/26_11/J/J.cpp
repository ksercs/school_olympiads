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

const int MAXN = 100000 + 15;

int n, ind2, ind0, u2, ans, fl, L;
int dg[MAXN], gr[MAXN], u[MAXN];

void DFS(int v)
{
    if (L == 1 && v == 1) return;
    //cout << v << endl; system("PAUSE");
    int to = gr[v];
    if (!L && to == ind2)
    {
        if (u2 == 0) u2++;
        else if (u2 == 1) {L = 1; gr[v] = ind0; to = ind0; ans = v;}
        DFS(to);
    }
    else if (u[to] == 1) fl = 0;
         else   DFS(to);
}

void in()
{
    ifstream cin("rooms.in");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> gr[i];
        dg[gr[i]]++;
        if (dg[gr[i]] > 1) {fl ++; ind2 = gr[i];}
    }
}

void solution()
{
    if (fl == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dg[i] == 0) {ind0 = i; break;}
        }
        //cout << ind0 << " " << ind2 << endl;
        DFS(1);
    }
}

void out()
{
    ofstream cout("rooms.out");
    if (fl == 1) cout << ans << " " << ind0 << "\n";
    else    cout << "-1 -1\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
