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

int n;
LL t, s, ans;

void in()
{
    ifstream cin("beasts.in");
    cin >> t >> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        LL L, R, Lcnt, Rcnt;
        cin >> L >> R;
        //if (R < L) swap(L, R);
        if (R < t) continue;
        /*L = max(L, t);
        //L = max(1LL*0, L-t);
        //R -= t;
        Lcnt = L/s;
        Rcnt = R/s;
        ans += Rcnt-Lcnt+((L%s==0)&&L!=0 || L == t);
        //ans++;*/
        if (t < L && (L-t)%s !=0)  L = ((L-t)/s+1)*s+t;
        else
        if (t > L)  L = t;
        if (L <= R)
        {
            ans += (R-L)/s;
            ans++;
        }
    }
}

void out()
{
    ofstream cout("beasts.out");
    cout << ans << endl;
}

int main()
{
    in();
    out();
    return 0;
}
