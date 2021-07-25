#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = 1 << 18;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const int INF = 1e9;
const int SIGMA = 26;

struct minimizator {
	vector<int> a;

	minimizator() {}
	minimizator(int *a, int n) {
		for (int i = 0; i < n; i++) this->a.push_back(a[i]);
	}

	int getMin(int l, int r) {
		int res = INF;
		for (int i = l; i <= r; i++) res = min(res, a[i]);
		return res;
	}
};

int n;
string a[MAXN];
int lcp[MAXN];
minimizator mn;

int sz;
int nxt[MAXN][SIGMA];
vector<int> vct[MAXN];

void add(const string &s, int id) {
	int cur = 0;
	for (char c : s) {
		if (nxt[cur][c - 'a'] == 0) {
			nxt[cur][c - 'a'] = sz++;
		}
		cur = nxt[cur][c - 'a'];
		vct[cur].push_back(id);
	}
}

ll ans;

void dfs(int v, int h) {
	for (int i = 0; i < SIGMA; i++) if (nxt[v][i]) dfs(nxt[v][i], h + 1);
	vector<int> clcp;
	for (int i = 0; i < (int)vct[v].size() - 1; i++) {
		clcp.push_back(mn.getMin(vct[v][i], vct[v][i + 1] - 1));
	}

	clcp.push_back(-1);
	vector<pair<int, int> > st;
	st.push_back(make_pair(-2, -1));
	for (int i = 0; i < (int)clcp.size(); i++) {
		while (st.back().first >= clcp[i]) {
			int value = st.back().first;
			st.pop_back();
			int len = i - st.back().second;
			ans = max(ans, 1LL * value * len * h);
		}
		st.push_back(make_pair(clcp[i], i));
	}
}

int main() {
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);
	
	sz = 1;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);
	for (int i = 0; i + 1 < n; i++) {
		while (lcp[i] < min(a[i].length(), a[i + 1].length()) && a[i][lcp[i]] == a[i + 1][lcp[i]]) lcp[i]++;
	}
	mn = minimizator(lcp, n - 1);

	for (int i = 0; i < n; i++) {
        if (1LL * a[i].size() * a[i].size() > ans)
            ans = 1LL * a[i].size() * a[i].size();
		reverse(a[i].begin(), a[i].end());
		add(a[i], i);
	}

	dfs(0, 0);

	cout << ans << endl;

	return 0;
}
