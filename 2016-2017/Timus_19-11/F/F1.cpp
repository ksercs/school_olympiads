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

const int MAXT = (int)1e6+15;

int L, T, A, B, n, ans;
LL stop[3][MAXT];
pair <LL, LL> dp[3][MAXT];
VEC < pair <LL, LL> > AL;
VEC < pair <LL, LL> > BOB;

bool intersection(pair <LL, LL> pi1, pair <LL, LL> pi2)
{
    if (pi1.first > pi1.second) {swap(pi1.first, pi1.second);}
    if (pi2.first > pi2.second) {swap(pi2.first, pi2.second);}
    if (pi1.first > pi2.first)  {swap(pi1.first, pi2.first); swap(pi1.second, pi2.second);}
    if (pi1.second < pi2.first) {return false;}
    else                        {return true;}
}


void in()
{
    ifstream cin("input.txt");
    cin >> L >> T >> A >> B;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        LL a, b, c;
        cin >> a >> b >> c;
        stop[a][b] = max(c, stop[a][b]);
    }
}

void solution()
{
    dp[1][0] = MP(1,1);
    dp[2][0] = MP(1,1);
    A %= L;
    B %= L;
    for (int i = 1; i <= T; i++)
    {
        if (dp[1][i].FF ==0) {dp[1][i] = MP((dp[1][i-1].FF+dp[1][i-1].SS),A);
        if (dp[1][i].FF+dp[1][i].SS <= L) dp[1][i].FF += L;
        if (dp[1][i].FF > 2*L) dp[1][i].FF -= L;
        }
        //else{//dp[1][i] = dp[1][i-1];
        for (int j = i+1; j <= i+stop[1][i]; j++)
        {
                dp[1][j] = dp[1][i];
        }//}
        //cout << "stop[i] = " << stop[1][i] << endl;
        //cout << i << " ";
        int fl = 0;
        if (stop[1][i] > 0) fl = -1;
        i = i+stop[1][i] + fl;
        //cout << i << endl;
    }
    for (int i = 1; i <= T; i++)
    {
        if (dp[2][i].FF ==0){dp[2][i] = MP((dp[2][i-1].FF-dp[2][i-1].SS),B);
        if (dp[2][i].FF <= 0) dp[2][i].FF += L;}
        //else{//dp[2][i] = dp[2][i-1];
        for (int j = i+1; j <= i+stop[2][i]; j++)
        {
                dp[2][j] = dp[2][i];
        }//}
        int fl = 0;
        if (stop[2][i] > 0) fl = -1;
        i = i+stop[2][i] + fl;
    }
    /*for (int i = 1; i <= T; i++)
    {
        cout << dp[1][i].FF << " " << dp[1][i].SS << " " << dp[2][i].FF << " " <<dp[2][i].SS << endl;
    }*/
    /*for (int i = 1; i <= T; i++)
    {
        if (dp[1][i].FF+dp[1][i].SS == dp[2][i].FF+dp[2][i].SS) ans++;
    }*/
    for (int i = 1; i <= T; i++)
    {
        LL x1, x2, y1, y2;
        x1 = dp[1][i].FF;
        y1 = dp[2][i].FF;
        x2 = dp[1][i].FF + dp[1][i].SS;
        y2 = dp[2][i].FF + dp[2][i].SS;
        //if (x1 != y1 && x2 != y2)
        {
           // if (x2 < x1) x2 += L;
           // if (y1 < y2) y1 += L;
            if (x2 == y1) ans--;
            if (intersection(MP(x1,x2), MP(y1,y2))) ans++;
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
