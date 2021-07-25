#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int MAX = 200005;
const long long INF = 1000000007;

long long n, m, k, x, s, time, minn;

int a[MAX], b[MAX], c[MAX], d, ost;

set < pair <int, int> > ss;
set < pair <int, int> >:: iterator it, itt;

void in()
{
    cin >> n >> m >> k >> x >> s;
    minn = n * x;
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> c[i];
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> d;
        ss.insert(make_pair(d, c[i]));
    }
}

void solution()
{
    for (int i = 0; i < m; ++i)
    {
        ost = s - b[i];
        if (ost < 0) continue;
        it = ss.upper_bound(make_pair(ost, INF));
        if (it != ss.begin())
        {
            it--;
            time = (n - it->second) * (a[i]);
        }
        else time = (a[i]) * n;
        minn = min(minn, time);
    }
    for (itt = ss.begin(); itt != ss.end(); ++itt)
    {
        if (itt->first <= s)
        {
            minn = min(minn, (n - itt->second) * x);
        }
    }
}

void out()
{
    cout << minn << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
