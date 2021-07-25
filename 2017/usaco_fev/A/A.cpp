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

const int INF = (int)1e6;

int n, ans = INF;
VEC <>

void in()
{
    ifstream cin("mincross.in");
    cin >> n;
    for (int i = 0; i < n; ++i){
        char a;
        cin >> a;
        s1 += a;
    }
    for (int i = 0; i < n; ++i){
        char a;
        cin >> a;
        s2 += a;
    }
}

void solution()
{
    for (int i = 0; i < n; ++i){
        int res = 0;
        int ind = s1.find_first_of(s2[i]);
        string s3;
        if (ind-i >= 0) s3 = s1.substr(ind-i, n-ind+i) + s1.substr(0, ind-i);
        else            s3 = s1.substr(n+ind-i, i-ind) + s1.substr(0, n+ind-i);
        cout << ind << " " << s3 << " " << s2 << "\n";
        for (int i = 1'')
        ans = min(ans, res);
    }
}

void out()
{
    ofstream cout("mincross.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
