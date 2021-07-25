#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

ll highest(ll x) {
    ll res = 1;
    while (x) {
        x /= 2;
        res <<= 1;
    }
    return res >> 1;
}

int cnt(ll x) {
    int res = 0;
    while (x) {
        res += x % 2;
        x /= 2;
    }
    return res;
}

int main() {
    freopen("parts.in", "r", stdin);
    freopen("parts.out", "w", stdout);
             
    int n;
    cin >> n;
    ll l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int ll, rr;
        cin >> ll >> rr;
        l += ll;
        r += rr;
    }

    cout << cnt(l | max(0LL, highest(l ^ r) - 1) | r) << endl;

    return 0;
}