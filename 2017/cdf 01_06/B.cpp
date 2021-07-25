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
#define PII pair <int,int>
#define LL long long

using namespace std;

int n, m, ans, last, pl;
int gr[115][2], h[115];

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> m;
    for (int i = n; i >= 1; --i){
        for (int j = 0; j <= m+1; ++j){
            char b;
            cin >> b;
            int a = int(b-'0');
            if (a) last = j;
            if (!gr[i][0] && a) gr[i][0] = j;
            gr[i][1] = last;
        }
        last = 0;
        if (gr[i][0]) h[i] = 1;
    }
}

void solution()
{
    for (int i = 1; i <= n; ++i){
        h[i] += h[i-1];
        //cout << h[i] << "\n";
    }
    if (!h[n]) return;
    for (int i = 1; i <= n; ++i){
        if (gr[i][0] == 0)  {++ans; continue;}
        int need = 0;
        if (pl){
             ans += m+1-gr[i][0];
             //cout << "K " << m+1-gr[i][0] << "\n";
             if (!(h[n]-h[i])) break;
             for (int j = i+1; j <= n; ++j)
                if (gr[j][0]) {need = j; break;}
             if (m+1-gr[i][0] + m+1-gr[need][0] <= gr[i][0]+gr[need][1]) {ans += m+1-gr[i][0]; pl = 1;}
             else   {ans += gr[i][0]; pl = 0;}
        }
        else    {
            ans += gr[i][1];
            if (!(h[n]-h[i])) break;
            for (int j = i+1; j <= n; ++j)
                if (gr[j][0]) {need = j; break;}
            if (m+1-gr[i][1]+ m+1-gr[need][0] <= gr[i][1]+gr[need][1]) {ans += m+1-gr[i][1]; pl = 1;}
            else   {ans += gr[i][1]; pl = 0;}
        }
        ++ans;
        //cout << ans << "\n";
    }
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
