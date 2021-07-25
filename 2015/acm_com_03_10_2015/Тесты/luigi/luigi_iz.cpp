#include <cstdio>
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    freopen("luigi.in", "r", stdin);
    freopen("luigi.out", "w", stdout);

    int a, b, c, d, k;
    while (cin >> a >> b >> c >> d >> k) {
        int mn = a + c;
        int mx = b + d;
        if (mn / k == mx / k && mn % k != 0) {
            cout << -1 << endl;
            continue;
        }
        int o = min(mx % k, b - a);
        b -= o;
        mx -= o;
        o = min(mx % k, d - c);
        d -= o;
        mx -= o;
        assert(mx % k == 0);
        cout << b << " " << d << endl;
    }
    return 0;
}