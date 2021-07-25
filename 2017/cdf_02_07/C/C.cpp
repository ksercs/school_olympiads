#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <climits>
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

int n, x, ans = INT_MAX, fl;

VEC < pair < PII, PII > > v;
map <int, VEC < pair <PII,int> > > mp;

bool check (PII a, PII b)
{
    if (a.SS < b.FF || b.SS < a.FF) return true;
    else                            return false;
}

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> x;
    v.resize(n);
    for (int i = 0; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = MP(MP(b-a+1, c),MP(a,b));
        mp[b-a+1].PB(MP(MP(a,b), c));
    }
}

void solution()
{
    sort(v.begin(), v.end());
    for (int ind = 0; ind < n; ++ind){
        if (!mp[x-v[ind].FF.FF].empty()){
            int ch = INT_MAX;
            for (int i = 0; i < mp[x-v[ind].FF.FF].SZ; ++i){
                if (check(v[ind].SS, mp[x-v[ind].FF.FF][i].FF)){
                    fl = 1;
                    ch = v[ind].FF.SS + mp[x-v[ind].FF.FF][i].SS;
                    if (ch < ans) ans = ch;
                }
            }
        }
    }
}

void out()
{
   // ofstream cout("output.txt");
    if (!fl) cout << "-1\n";
    else cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
