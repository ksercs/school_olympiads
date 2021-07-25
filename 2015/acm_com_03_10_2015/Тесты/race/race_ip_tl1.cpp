#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 22;
int getLCP(const vector<string>& b) {
    int l = 0;
    bool all = true;
    while (all) {
        all = true;
        for (int i = 0; i < b.size(); ++i)
            all &= l < b[i].size() && b[i][l] == b[0][l];
        ++l;
    }
    --l;
    return l;
}

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    int tot = 1<<n;
    int ans = 0;
    for (int ms = 1; ms < tot; ++ms) {
        vector<string> b;
        for (int i = 0; i < n; ++i)
            if ((ms>>i)&1)
                b.push_back(a[i]);
        int lc = getLCP(b);
        for (int i = 0; i < b.size(); ++i)
            reverse(b[i].begin(), b[i].end());
        int sc = getLCP(b);
        ans = max(ans, (int)(lc * sc * b.size()));
    }
    printf("%d\n", ans);
    return 0;
}
