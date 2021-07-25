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

const int MAXN = 200000+15, INF = (int)(2e9);;

int n, ans1, ans2, MIN = 1000000012, MAX, M, ind, ans;
int mass[MAXN];

void in()
{
    ifstream cin("deepcycle.in");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mass[i];
        if (mass[i] > M) {M = mass[i]; ind = i;}
    }
    for (int i = n; i <= ind; i++)
    {
        mass[i] = mass[i-n];
    }

}

void solution()
{
    /*ind = n-1;
    for (int i = n-1; i >= 0; i--)
    {
        M = max(M, mass[i]);
        if (mass[i] < MIN) {ans2++; MIN = mass[i]; MAX = M;ind = i;}
    }
    //cout << MIN << " " << MAX << endl;
    for (int i = 0; i < ind; i++)
    {
        if (mass[i] > MAX) ans1++;
    }
    ans = ans1+ans2;
    MIN = 1000000012; MAX=0; ind = 0;
    M =1000000012; ans1 = 0; ans2 = 0;
    for (int i = 0; i < n; i ++)
    {
        M = min(M, mass[i]);
        if (mass[i] > MAX) {ans1++; MAX = mass[i]; MIN = M;ind = i;}
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (mass[i] > MIN) break;
        if (mass[i] < MIN) ans2++;
    }
    ans = max(ans, ans1+ans2);*/
    vector <int> dp(n+1, INF);
    dp[0] = -1;
    for (int i = 0; i < n; i++)
    {
		dp[lower_bound(dp.begin(), dp.end(), mass[i]) - dp.begin()] = mass[i];
	}
    for (int i = n; i >= 0; i--)
        if (dp[i] != INF) {
            ans = i;
           // cout << i <<  " " << dp[i] << endl;
            break;
        }
        //ans--;
}

void out()
{
    ofstream cout("deepcycle.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
