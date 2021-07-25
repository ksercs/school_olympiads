#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    freopen("luigi.in", "rt", stdin);
    freopen("luigi.out", "wt", stdout);
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int ans = b + d - (b + d) % k;
    //cerr << ans << endl;
    int x = a, y = ans - a;
    int dif = y - d;
    //cerr << y << ' ' << d << ' ' << dif;
    //cerr << endl << (diff < 0 && y < c) << ' ' <<  (x + dif > b) << endl;
    if ((dif < 0 && y < c) || x + dif > b)
        cout << -1 << endl;
    else 
        cout << x + max(dif, 0) << ' ' << y - max(dif, 0) << endl;
    return 0;
}