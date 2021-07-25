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

const int MAXN = (int)60005;
const double EPS = 1e-6;

int n;
double ans;
int koor[MAXN], v[MAXN];

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> koor[i];
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}

void solution()
{
    double L = 0.0, R = 1e9, M;
    for (int i = 0; i < 50; ++i){
        //cout << L << " " << R << "\n";
        M = L + (R-L)/2.0;
        double  Lx = koor[0] - M*v[0],
                Rx = koor[0] + M*v[0];
        for (int j = 1; j < n; ++j){
            Lx = max(Lx, koor[j]-M*v[j]);
            Rx = min(Rx, koor[j]+M*v[j]);
        }
        if (Lx <= Rx+EPS) R = M;
        else              L = M;
    }
    ans = L;
}

void out()
{
    //ofstream cout("output.txt");
    cout.precision(12);
    cout << fixed << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
