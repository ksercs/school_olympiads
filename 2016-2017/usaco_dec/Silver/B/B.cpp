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
#define PSS pair <string,string>
#define LL long long

using namespace std;

int n, ans;

VEC < PSS > v;
multiset < PSS > ms;

void in()
{
    ifstream cin("citystate.in");
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        s1.erase(2,s1.SZ-2);
        v[i] = MP(s1,s2);
        ms.insert(v[i]);
    }
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        PSS p = v[i];
        swap(v[i].FF, v[i].SS);
        int ch = 0;
        while (ms.count(v[i]))
        {
            if (v[i].FF != v[i].SS) ans ++;
            ch ++;
            ms.erase(ms.find(v[i]));
        }
        while (ch > 0)
        {
            ch--;
            ms.insert(v[i]);
        }
    }
    ans /= 2;
}

void out()
{
    ofstream cout("citystate.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
