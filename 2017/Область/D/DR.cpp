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
#define PIL pair <int,LL>
#define LL long long

using namespace std;

const int MAXN = (int)1e5+5, MOD = (int)1e9+7;

int n;
LL ans = 1, max_v;
set <LL> v;
set <LL>:: iterator it, it1;
map <LL, LL> mp, answer;

PIL get_ans(LL ver)
{
    max_v = max(max_v, ver);
    if (!mp[ver]) return MP(1,0);
    PIL pL = get_ans(2*ver);
    PIL pR = get_ans(2*ver+1);
    if (pL.FF && pR.FF && pL.SS == pR.SS) {
        answer[ver] = ((1+(LL)pow(2, mp[ver]+1)-2)%MOD+((LL)pow(2, pL.SS+1)-2)%MOD)%MOD;
        ans = max(ans, answer[ver]);
        return MP(1, answer[ver]);
    }
    return MP(0, 0);
}

bool check(LL v1, LL v2)
{
    if (v1 > (LL)1e10) return true;
    if (v1 == v2) return false;
    LL p1 = v1*2;
    LL p2 = v1*2+1;
    check(p1,v2);
    check(p2,v2);
}

void in()
{
    ifstream cin("D.in");
    cin >> n;
    for (int i = 0; i < n; ++i){
        LL a;
        cin >> a;
        if (!mp[a]) v.insert(a);
        mp[a]++;
    }
}

void solution()
{
    for (it = v.begin(); it != --v.end(); it++)
        for (it1 = ++it; it1 != v.end(); it1++){
            int fl = check( (*it), (*it1) );
            if (!fl) mp[(*it1)] += mp[(*it)];
        }
    for (it = v.begin(); it != v.end(); it++){
        LL V = (*it);
        //if (!answer[V]) {
            max_v = 0;
            PIL p = get_ans(V);
            if (p.FF && v.lower_bound(max_v)==v.end()) ans = max(p.SS, ans);
       // }
    }
    for (it = v.begin(); it != v.end(); it++)
        cout << answer[(*it)] << "\n";
}

void out()
{
    ofstream cout("D.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
