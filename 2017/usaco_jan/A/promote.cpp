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

FILE* file;

const int MAXN = (int)1e5+15;

int n, ind;
int p[MAXN], tr[MAXN], ans[MAXN];

void get_ans(int v)
{
    int pr = p[v];
    if (!pr) return;
    if (tr[pr] < tr[ind]) ans[pr]++;
    get_ans(pr);
}

void in()
{
    //ifstream cin("promote.in");
    file = fopen("promote.in", "r");
    //cin >> n;
    fscanf(file, "%d", &n);
    for (int i = 1; i <= n; ++i)
        fscanf(file, "%d", &tr[i]);
        //cin >> tr[i];
    for (int i = 2; i <= n; ++i)
        fscanf(file, "%d", &p[i]);
        //cin >> p[i];
}

void solution()
{
    for (int i = 2; i <= n; ++i){
        ind = i;
        get_ans(i);
    }
}

void out()
{
    //ofstream cout("promote.out");
    file = fopen("promote.out", "w");
    for (int i = 1; i <= n; ++i)
        fprintf(file, "%d\n", ans[i]);
        //cout << ans[i] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
