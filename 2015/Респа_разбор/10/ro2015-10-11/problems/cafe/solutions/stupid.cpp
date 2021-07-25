/*
    Author: Adilet Zhaxybay
    Date: 09.03.15
    Description: Slow solution (2^r * r * log(r)) --- where r is number of relations 
*/               


#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 505;

int n, m, k;
int a[MAXN], b[MAXN];
int curA[MAXN], curB[MAXN];
int c[MAXN], p[MAXN];
vector < pair < int, pair <int, int> > > v;
int sz;
int ans;

int main() {
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= k; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        for (int j = 1; j <= num; j++) {
            int x;
            scanf("%d", &x);    
            v.push_back(make_pair(i, make_pair(1, x)));
        }
    }

    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);
        for (int j = 1; j <= num; j++) {
            int x;
            scanf("%d", &x);    
            v.push_back(make_pair(i, make_pair(2, x)));
        }
    }

    sz = (int) v.size();
    for (int mask = 0; mask < (1 << sz); mask++) {
        map <int, int> mpa, mpb;
        set <int> sta, stb;

        for (int i = 0; i < (int) sz; i++) {
            if ((mask & (1 << i)) == 0)
                continue;
            int p = v[i].first, t = v[i].second.first, x = v[i].second.second;
            if (t == 1) {
                mpa[x]++;
                sta.insert(p);
            }
            else {          
                mpb[x]++;
                stb.insert(p);
            }
        }

        bool ok = true;

        for (map <int, int> :: iterator it = mpa.begin(); it != mpa.end(); it++) {
            int x = it->first, num = it->second;
            if (a[x] < num) {
                ok = false;
                break;
            }
        }

        for (map <int, int> :: iterator it = mpb.begin(); it != mpb.end(); it++) {
            int x = it->first, num = it->second;
            if (b[x] < num) {
                ok = false;
                break;
            }
        }

        if (!ok)
            continue;

        int curAns = 0;
        for (set <int> :: iterator it = sta.begin(); it != sta.end(); it++) {
            int p = *(it);
            if (stb.count(p))
                curAns++;
        }
        
        if (curAns > ans)
            ans = curAns;
    }

    cout << ans << endl;

    return 0;
}