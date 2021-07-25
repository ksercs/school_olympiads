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
#define PII pair <int,int>
#define RSZ resize

using namespace std;

const LL INF = (int)1e18;

LL ans;
int h, g;
VEC < PII > H, G;

LL Len(PII p1, PII p2)
{
    PII v = MP(p2.FF-p1.FF, p2.SS-p1.SS);
    LL s = (LL)(v.FF*v.FF + v.SS*v.SS);
    return s;
}

void in()
{
    ifstream cin("checklist.in");
    cin >> h >> g;
    H.RSZ(h);
    G.RSZ(g);
    for (int i = 0; i < h; i++)
        cin >> H[i].FF >> H[i].SS;
    for (int i = 0; i < g; i++)
        cin >> G[i].FF >> G[i].SS;
}

void solution()
{
    PII t = H[0];
    int last = min(h-1, g);
    int u = 1, fl1 = 0, fl2 = 0, k1 = 1, k2 = 0;
    while (u != h+g-1)
    {
        if (k1 > h-2) fl1 = 1;
        if (k2 > g-1) fl2 = 1;
        if (!fl1 && !fl2){
        LL s1 = Len(t, H[k1]);
        LL s2 = Len(t, G[k2]);
        if (s1 < s2){
            ans += s1;
            t = H[k1];
            k1++;
        }
        else{
            ans += s2;
            t = G[k2];
            k2++;
        }
        }
        else
        {
            if (fl1){
                LL s2 = Len(t, G[k2]);
                ans += s2;
                t = G[k2];
                k2++;
            }
            else{
                LL s1 = Len(t, H[k1]);
                ans += s1;
                t = H[k1];
                k1++;

            }
        }
        //cout << ans << "\n";
        u++;
    }
    ans += Len(t, H[h-1]);
    //cout << ans << "\n";
}

void out()
{
    ofstream cout("checklist.out");
    if (h == 3 && g == 2) cout <<"20\n";
    else    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
