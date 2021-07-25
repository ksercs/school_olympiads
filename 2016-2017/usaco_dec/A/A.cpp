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

const LL INF = (LL)1e18;

LL n, ans;
VEC < PII > p;
map < PII, PII > u;
map < PII, int > u1;
set < pair < PII, PII > > st;
int cnt;

void in()
{
    ifstream cin("moocast.in");
    cin >> n;
    p.RSZ(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (u1[MP(a,b)] == 0) {p[cnt] = MP(a, b);u1[p[cnt]]=1; u[p[cnt]]=MP(-1,-1); cnt++;}
    }
}

void solution()
{
    //cout << cnt << "\n";
    u1.clear();
    for (int i = 0; i < cnt; i++){
        if (u1[p[i]]==1) continue;
        LL mini = INF;
        int ch = -1;
        for (int j = 0; j < cnt; j++)
        {
            if (i == j /*|| u[p[j]]==p[i] || u[p[i]]==p[j]*/ || st.count(MP(p[i], p[j]))/* || u1[p[j]]==1*/ ) continue;
            PII v = MP((p[j].FF-p[i].FF), (p[j].SS-p[i].SS));
            LL s = (LL)(1LL*(v.FF)*(v.FF) + 1LL*(v.SS)*(v.SS));
            cout << i << " " << j << ": " << s << endl;
            if (s < mini) {mini = s; ch = j;}
        }
        if (ch == -1) mini=0;
        u1[p[ch]]=1;
        u1[p[i]]=1;
        st.insert(MP(p[ch],p[i]));
        cout << "MINI = " << mini << " " << ch << "\n\n";
        ans = max(mini, ans);
    }
    if (cnt == 1) ans = 0;
}

void out()
{
    ofstream cout("moocast.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
