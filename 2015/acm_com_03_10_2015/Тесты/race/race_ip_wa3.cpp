#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int LEN = 2e5 + 10;
char ss[LEN];

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", ss);
        mx = max(mx, (int)strlen(ss));
    }
    cout << 1LL * mx * mx;
    return 0;
}
