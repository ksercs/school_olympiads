#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

int n, k;

multiset <pair <int, pair<int,int> > > ms;

void in()
{
    ifstream cin ("pencils.in");
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int c, a, mn=INT_MAX, mx;
        cin >> c;
        for (int i = 0; i < c; i++)
        {
            cin >> a;
            mn = min(mn, a);
            mx = max(mx, a);
        }
        ms.insert(make_pair(mx-mn, make_pair(mn, mx)));
    }
}

void solution()
{

}

void out()
{
     ofstream cout ("pencils.out");
}

int main()
{
    in();
    solution();
    out();
return 0;
}
