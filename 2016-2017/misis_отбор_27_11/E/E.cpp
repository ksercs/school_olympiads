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

const int MAXN = 200000+15;

int n, m, bal, fl1, fl2;
int ans[MAXN];

VEC < PII > one, nol;

bool comp(PII a, PII b)
{
    if (a.FF != b.FF) return a.FF < b.FF;
    else              return a.SS > b.SS;
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int L, R, T;
        cin >> L >> R >> T;
        if (T == 0) {nol.PB(MP(L, 1)); nol.PB(MP(R+1, -1));}
        if (T == 1) {one.PB(MP(L, 1)); one.PB(MP(R+1, -1));}
    }
}

void solution()
{
    if (nol.SZ == 0) fl1= 1;
    if (one.SZ == 0) fl2 = 1;
    if (!fl1)sort(nol.begin(), nol.end(), comp);
    if (!fl2)sort(one.begin(), one.end(), comp);
    //cout << nol.SZ << endl;
    if (!fl1)for (int i = 0; i < nol.SZ-1; i++)
    {
        bal += nol[i].SS;
        if (bal%2)
        {
            //cout << i << " " <<i+1 << endl;
           // cout << nol[i].FF << " " << nol[i+1].FF << endl;
            int L = nol[i].FF, R = nol[i+1].FF-1;
            if ((nol[i].FF)%2) L++;
            if (!((nol[i+1].FF)%2)) R--;
            for (int j = L; j <= R; j+=2)
            {
                ans[j] = 1;
            }
        }
    }
    bal=0;
    if (!fl2)for (int i = 0; i < one.SZ-1; i++)
    {
        bal += one[i].SS;
        if (bal%2)
        {
            int L = one[i].FF, R = one[i+1].FF-1;
            if (!((one[i].FF)%2)) L++;
            if ((one[i+1].FF)%2) R--;
            for (int j = L; j <= R; j+=2)
            {
                ans[j] = 1;
            }
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[n] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
