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

const int MAXN = (int)1e5+5;

int n, fl=1, s1, s2, z1, z2;
multiset < int > ms;
int ans[MAXN], cnt[MAXN];
map <int, VEC <int> > mp;


void in()
{
    ifstream cin("parties.in");
    cin >> n;
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        ms.insert(a);
        mp[a].PB(i);
    }
}

void solution()
{
    get_ans();
    if (s1 != z2 || z1 != s2) fl = 0;
}

void out()
{
    ofstream cout("parties.out");
    if (fl){
        cout << "YES\n";
        for (int i = 0; i < n-1; ++i)
            cout << ans[i] << " ";
        cout << ans[n-1] << "\n";
    }
    else cout << "NO\n";

}

int main()
{
    in();
    solution();
    out();
    return 0;
}
