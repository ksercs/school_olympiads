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
#define LL long long
#define PII pair <LL,int>

using namespace std;

int n, p;

VEC < PII > v;
PII ans;

bool better(PII p1, PII p2, int zn)
{
    //cout << p1.SS << " " << p2.SS << ": " << abs((long double)p1.FF/p2.FF-zn) << endl;
    //cout << ans.FF << " " << ans.SS << ": " << abs((long double)v[ans.FF].FF/v[ans.SS].FF-zn) << endl;
    return abs((long double)p1.FF/p2.FF-zn) < abs((long double)v[ans.FF].FF/v[ans.SS].FF-zn);
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> p;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        LL a;
        cin >> a;
        v[i] = MP(a, i);
    }
}

void solution()
{
    sort(v.begin(), v.end());
    ans = MP(0,1);
    for (int i = 0; i < n; i++)
    {
        int pos = lower_bound(v.begin(), v.end(), MP(v[i].FF*p,-1))-v.begin();
        for (int j = max(0,pos-2); j < min(n, pos+3); j++)
        {
            if (i != j && better(v[j], v[i], p)) ans = MP(v[j].SS, v[i].SS);
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans.FF+1 << " " <<ans.SS+1 << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
