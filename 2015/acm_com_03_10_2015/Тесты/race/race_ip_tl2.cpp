#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 300;

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> a(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, (int)a[i].size());
    }
    int ans = 0;
    for (int i = 1; i <= mx; ++i)
        for (int j = 1; j <= mx; ++j) {
            vector<pair<string, string> > pairs;
            for (int p = 0; p < a.size(); ++p)
                if (i <= a[p].size() && j <= a[p].size())
                    pairs.push_back(make_pair(a[p].substr(0, i), a[p].substr(a[p].size() - j, j)));
            sort(pairs.begin(), pairs.end());
            for (int p = 0; p < pairs.size();) {
                int e = p;
                while (p < pairs.size() && pairs[e] == pairs[p]) ++p;
                ans = max(ans, i * j * (p - e));
            }
        }
    printf("%d\n", ans);
    return 0;
}
