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

LL n, k, ans;
VEC <LL> v;

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}

void solution()
{
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i){
        if (v[i] > 2*k){
            while (2*k < v[i]){
                k *= 2;
                ++ans;
            }
        }
        k = max(k, v[i]);
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
