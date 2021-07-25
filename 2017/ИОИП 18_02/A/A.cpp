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

LL n, ans, L = 1, R;

void BS()
{
    LL zn;
    while (R-L > 1){
        LL M = (L + (R-L)/2);
        if (!(M%2)) zn = (1+M)*(M/2);
        else      zn = ((1+M)/2)*M;
        cout << M << " " << zn << "\n";
        if (zn == n){
            ans = M; return;
        }
        if (zn > n) R = M-1;
        if (zn < n) L = M;
    }
    if (!(R%2)) zn = (1+R)*(R/2);
    else        zn = ((1+R)/2)*R;
    if (zn <= n) ans = R;
    else         ans = L;
}

void in()
{
    ifstream cin("castle.in");
    cin >> n;
}

void solution()
{
    R = n;
    BS();
}

void out()
{
    ofstream cout("castle.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
