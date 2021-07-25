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
#define PII pair <LL,LL>
#define LL long long

using namespace std;

const int MAXN = (int)1e5+5;

int n, m, fl = 1;
LL nod[MAXN], num_day[MAXN];
VEC < PII > day[MAXN];
map <int, int> mp;

LL gcd_R (LL a, LL b)
{
    return (a && b) ? gcd_R(b, a%b) : (a|b);
}

void in()
{
    ifstream cin("accounts.in");
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j){
            LL num;
            LL cnt;
            cin >> num >> cnt;
            mp[num]|++;
            day[i].PB(MP(cnt, num));
            if (nod[num] == 0) nod[num] = cnt;
            else               nod[num] = gcd_R(nod[num], cnt);
        }
    }
}

void solution()
{
    //for (int i = 1; i <= n; ++i)
    //    cout << nod[i] << " ";
    int tmp = 0;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < day[i].SZ; ++j){
            LL num = day[i][j].SS;
            LL cnt = day[i][j].FF;
            if (nod[num] != cnt)
                if (num_day[i] == 0) {
                    if (cnt%nod[num] == 0){ num_day[i] = cnt/nod[num]; tmp = 1; }//j = -1; }//solution(); return;}
                    else {fl = 0; return;}
                }
                else{
                    if (cnt%nod[num] != 0) /*{fl = 0; return;} */ continue;
                    LL n_day = cnt/nod[num];
                    if (n_day != num_day[i]){
                         fl = 0;
                         return;
                    }
                }
            else if (num_day[i] != 0){
                    if (cnt%num_day[i] != 0) {fl = 0; return;}
                    nod[num] = cnt/num_day[i];
                }
        }
        if (tmp) i = -1;
        tmp = 0;
    }
}

void out()
{
    ofstream cout("accounts.out");
    if (!fl) cout << "NO\n";
    else{
        cout << "YES\n";
        for (int i = 1; i < n; ++i)
            if (!nod[i]) cout << "1 ";
            else         cout << nod[i] << " ";
        if (!nod[n]) cout << "1\n";
        else         cout << nod[n] << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
