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

int n, ans, st, h;

VEC < PII > v;

void in()
{
    ifstream cin("deepcycle.in");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.PB(MP(a, i));
    }
}

void solution()
{
    sort(v.begin(), v.end());
    st = v[0].SS;
    h = v[0].FF;
    for (int i = st+1; i < v.SZ; i++)
    {
        if (v[i].FF > h) {h = v[i].FF; ans++;}
    }
    for (int i = 0; i < st; i++)
    {
        if (v[i].FF > h) {h = v[i].FF; ans++;}
    }
    ans++;
}

void out()
{
    ofstream cout("deepcycle.out");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
