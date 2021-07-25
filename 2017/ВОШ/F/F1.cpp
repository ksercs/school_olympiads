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

const int MAXN = (int)2*1e4, MAXCH = (int)1e4, INF = int(2*1e9);;

int n, k, ans, sum;
VEC <int> v;

void in()
{
    ifstream cin("nearest.in");
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; ++i){
        cin >> v[i];
        v[i] = abs(v[i]);
    }
}

void solution()
{

}

void out()
{
    ofstream cout("nearest.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
