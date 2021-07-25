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

int n, ans;
VEC <int> v;

void in()
{
    ifstream cin("stones.in");
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}

void solution()
{
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i){
        int cur = v[i],
            last = v[i]+n-1;
        int ind2;
        ind2 = upper_bound(v.begin(), v.end(), last) - v.begin() - 1;
        ans = max(ans, (ind2-i));
    }
    ans = n-ans-1;
}

void out()
{
    ofstream cout("stones.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
