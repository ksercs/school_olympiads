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
#define LB lower_bound

using namespace std;

const int MAXN = (int)1e5+2;

FILE* file;

int n, q;
PII  v[MAXN];
int ans[MAXN], rez[MAXN];

void in()
{
    //ifstream cin("input.txt");
    file = fopen("input.txt", "r");
    ios_base:: sync_with_stdio(false);
    fscanf(file, "%d", &n);
    //cin >> n;
    for (int i = 1; i <= n; ++i){
        fscanf(file, "%d%d", &v[i].FF, &v[i].SS);
        //cin >> v[i].FF >> v[i].SS;
    }
    //cin >> q;
    fscanf(file, "%d", &q);
    for (int i = 0; i < q; ++i){
        int ch;
        fscanf(file, "%d", &ch);
        for (int j = 1; j <= n; ++j){
            int zn = v[j].SS-v[j].FF+1;
            if (v[j].FF <= ch && v[j].SS >= ch && (zn > rez[i])) {
                ans[i] = j; rez[i] = zn;
            }
        }
    }
        //cin >> p[i];
}

void out()
{
    //ofstream cout("output.txt");
    file = fopen("output.txt", "w");
    for (int i = 0; i < q; ++i)
        (!ans[i])? fprintf(file, "-1\n") : fprintf(file, "%d\n", ans[i]);
        //cout << ans[i] << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
