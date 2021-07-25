#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int LEN = 2e5 + 10;
char ss[LEN];
const int K = 26;

struct Trie {
    struct Node {
        int t[K];
        int cntEnds;
    };

    vector<Node> a;
    Trie() {
        a.push_back(Node());
    }

    void insert(const string& s) {
        int v = 0;
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            if (a[v].t[c] == 0) {
                a.push_back(Node());
                a[v].t[c] = a.size() - 1;
            }
            v = a[v].t[c];
            a[v].cntEnds++;
        }
    }
};

long long dfs(const Trie& trie, int v, int lev) {
    long long mx = 1LL * lev * trie.a[v].cntEnds;
    for (int i = 0; i < K; ++i)
        if (trie.a[v].t[i] != 0)
            mx = max(mx, dfs(trie, trie.a[v].t[i], lev + 1));
    return mx;
}

long long f(int sufLen, const vector<string>& a) {
    vector<pair<int, int> > b;
    for (int i = 0; i < a.size();) {
        if (a[i].size() < sufLen) {
            ++i;
            continue;
        }
        string suff = a[i].substr(0, sufLen);
        int j = i;
        while (i < a.size() && sufLen <= a[i].size() && a[i].substr(0, sufLen) == suff)
            ++i;
        b.push_back(make_pair(j, i));
    }
    long long mx = 0;
    for (int i = 0; i < b.size(); ++i) {
        Trie trie;
        for (int j = b[i].first; j < b[i].second; ++j) {
            string b = a[j];
            reverse(b.begin(), b.end());
            trie.insert(b);
        }
        mx = max(mx, dfs(trie, 0, 0));
    }
    return sufLen * mx;
}

int main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> a(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", ss);
        a.push_back(string(ss));
        mx = max(mx, (int)a.back().size());
    }
    sort(a.begin(), a.end());

    int l = 1, r = mx, m1, m2;
    while (r - l >= 3) {
        m1 = (2 * l + r) / 3;
        m2 = (l + 2 * r) / 3;
        if (f(m1, a) > f(m2, a)) r = m2;
        else l = m1;
    }
    long long ans = 1LL * mx * mx;
    for (; l <= r; ++l) ans = max(ans, f(l, a));
    cout << ans;
    return 0;
}
