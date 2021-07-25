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

LL n, M, cnt, k, ans=1;
VEC <LL> v, a;

void in()
{
    ifstream cin("input.txt");
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
}

void solution()
{
    sort(v.begin(), v.end());
    LL M = v[0];
    cnt = 1;
    while (v[cnt] == M)
        cnt++;
    //cout << cnt <<"\n";
    LL ch = 1;
    int s = cnt;
    for (int i = s; i < n; ++i){
        if (ch == k && cnt > 0) {a.PB(M); cnt--; ch = 1; i--; continue;}
        if (cnt == 0 && n-a.SZ >= k) ans = 0;
        ch++;
        a.PB(v[i]);
    }
    while(cnt != 0){
        a.PB(M);
        cnt--;
    }
}

void out()
{
    ofstream cout("output.txt");
    if (!ans) cout << "Impossible\n";
    else{
        for (int i = 0; i < n-1; ++i)
            cout << a[i] << " ";
        cout << a[n-1] << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
