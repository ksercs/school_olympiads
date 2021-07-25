#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("soldiers.in", "r", stdin);
    freopen("soldiers.out", "w", stdout);

    int n, m, k;
    string s;
    while (cin >> n >> m >> k >> s) {
        int cur = 0;
        int ans = 0;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'L') cur = (cur + 1) % 4;
            if (s[i] == 'R') cur = (cur + 3) % 4;
            if (s[i] == 'A') cur = (cur + 2) % 4;
            ans += cur % 2;
        }
        if (n == m || m == 0) ans = 0;
        cout << ans << endl;
    }

    return 0;
}