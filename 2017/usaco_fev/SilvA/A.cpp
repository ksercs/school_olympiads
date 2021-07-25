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

const int MAXN = 20000+5;

int c, n, ans;

VEC <int> cp;
VEC < PII > cow;
int u[MAXN];
VEC < pair <int,  PII > > v;

void in()
{
    ifstream cin("helpcross.in");
    cin >> c >> n;
    cp.resize(c);
    cow.resize(n);
    v.resize(n);
    for (int i = 0; i < c; ++i)
        cin >> cp[i];
    for (int i = 0; i < n; ++i){
        cin >> cow[i].FF >> cow[i].SS;
        v[i].FF = cow[i].SS + cow[i].FF;
        v[i].SS = cow[i];
    }
}

/*void solution()
{
    sort(cp.begin(), cp.end());
    sort(cow.begin(), cow.end());
    while (!cp.empty() && !cow.empty()){
        int t1 = cp[0];
        PII t2 = cow[0];
        while (t1 > t2.SS && !cow.empty()){
            cow.erase(cow.begin());
            t2 = cow[0];
        }
        if (cow.empty()) break;
        while (t1 < t2.FF && !cp.empty()){
            cp.erase(cp.begin());
            t1 = cp[0];
        }
        if (cp.empty()) break;
        ans++;
        cp.erase(cp.begin());
        cow.erase(cow.begin());
    }
}*/

void solution()
{
    sort(cp.begin(), cp.end());
    sort(v.begin(), v.end());
    for (int i = 0; i < c; ++i){
        for (int j = 0; j < n; ++j)
            if (cp[i] >= v[j].SS.FF && cp[i] <= v[j].SS.SS && !u[j]){
                u[j] = 1;
                ans++;
                break;
            }
    }
}

void out()
{
    ofstream cout("helpcross.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
