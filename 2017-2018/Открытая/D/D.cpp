#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <climits>
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

const int MAXN = (int)1e5 +15;

LL n, H, T, mini = LLONG_MAX;
LL h[MAXN], v[MAXN];

bool check (LL x)
{
    LL num = x, tim = 0;
    //cout << "ST :" << x  << "\n";
    while (1){
        ++tim;
        //cout <<num << " " << tim << "\n";
        for (int i = n; i >= 1; --i){
            if (num >= h[i]) num = max(num-v[i], h[i]-1);
            /*for (int j = 0; j < v[i]; ++j){
                if (num >= h[i])
                    num--;
            }*/
        }
        if (num >= H)
            return true;
        if (tim == T)
            return false;
        num += x;
    }
    return true;
}

int bin()
{
    LL L = 0, R = 1000000000000000;
    while (R-L > 1){
        LL M = (L+R)/2;
        if (check(M))
            R = M;
        else
            L = M;
    }
    return R;
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> H >> T;
    for (int i = 1; i <= n; ++i){
        cin >> h[i] >> v[i];
        mini = min(mini, h[i]);
    }
        //cout << n << " " << H << " " << T << "\n";
}

void out()
{
    ofstream cout("output.txt");
    cout << bin() << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
