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

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

int n, q;

VEC <int> num, ans;

void in()
{
    ifstream cin("haybales.in");
    cin >> n  >> q;
    num.resize(n);
    ans.resize(q);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num.begin(), num.end());
    for (int i = 0; i < q; i++)
    {
        int a, b, c = 0;
        cin >> a >> b;
        int st, fn;
        st = lower_bound(num.begin(), num.end(), a) - num.begin();
        fn = lower_bound(num.begin(), num.end(), b) - num.begin();
        if (binary_search(num.begin(), num.end(), b)) c++;
        ans[i] = fn-st+c;
    }
}

void out()
{
    ofstream cout("haybales.out");
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
