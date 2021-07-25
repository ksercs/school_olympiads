#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
char s[N];
int main() {
    freopen("soldiers.in", "r", stdin);
    freopen("soldiers.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    if (m == 0 || m == n)
        return cout << 0, 0;
    scanf("%s", s);
    int dir1 = 0, dir2 = 0, ans = 0;
    for (int i = 0; i < k; ++i) {
        if (s[i] == 'L') {
            dir1 = (dir1 + 1) % 4;
            dir2 = (dir2 + 3) % 4;
        } else if (s[i] == 'R') {
            dir1 = (dir1 + 3) % 4;
            dir2 = (dir2 + 1) % 4;
        } else {
            dir1 = (dir1 + 2) % 4;
            dir2 = (dir2 + 2) % 4;
        }
        ans += dir1 != dir2;
    }
    cout << ans;
    return 0;
}
