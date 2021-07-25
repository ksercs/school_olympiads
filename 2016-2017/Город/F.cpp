#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

#define VEC vector
#define SZ size()
#define PB push_back

using namespace std;


const int INF = 2*(int)1e9, MAXN = (int)1e6+15;

int n, ans;
//int p[MAXN];

VEC <int> v, d;

void in()
{
   ifstream cin("F.in");
   cin >> n;
   v.resize(n);
   for (int i = 0; i < n; i++)
   {
       cin >> v[i];
   }
}

void solution()
{
   // sort(v.begin(), v.end());
   //ans.resize(n);
   //ans[0] = v[0];
   /*ans.PB(v[0]);
    for (int i = 1; i < n; i++)
    {
        int ind = lower_bound(ans.begin(), ans.end(), v[i])-ans.begin();
        //cout << ind << endl;
        if (ind >= ans.SZ) ans.PB(v[i]);
        else /*if (ind == ans.SZ-1)              ans[ind] = v[i];
    */
    d.resize(n+1);
    /*ans[0] = (-1)*INF;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = INF;
    }
    for (int i = 0; i < n; i++)
    {
        int ind = upper_bound(ans.begin(), ans.end(), v[i])-ans.begin();
        cout << ind << endl;
        if (ans[ind-1] < v[i] && v[i] < ans[ind])  {ans[ind] = v[i]; }
    }
    for (int i = 0; i < ans.SZ; i++)
    {
        cout << ans[i] << " ";
    }*/
    for (int i = 0; i < n; i++)
    {
        d[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (v[j] < v[i]) d[i] = max(d[i], d[j]+1);
        }
    }
    ans = d[0];
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, d[i]);
    }
}

void out()
{
    ofstream cout("F.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
