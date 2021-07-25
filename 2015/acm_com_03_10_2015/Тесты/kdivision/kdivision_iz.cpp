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

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

string getMinShift(string s) {
	int n = s.length();
	s += s;
	int i = 0;
	int last = -1;
	while (i < n) {
		last = i;
		int j = i + 1, k = i;
		while (j < 2 * n && s[j] >= s[k]) {
			if (s[j] == s[k]) k++;
			else k = i;
			j++;
		}
		while (i <= k) i += j - k;
	}
	return s.substr(last, n);
}

int main() {
	freopen("kdivision.in", "r", stdin);
	freopen("kdivision.out", "w", stdout);
	
	string s;
	cin >> s;
	int n = s.length();
	vector<int> ans;
	for (int k = 1; k <= n; k++) {
		if (n % k) continue;
		string mn, mx;
		mn += (char)('z' + 1);
		mx += (char)('a' - 1);
		for (int i = 0; i < n; i += n / k) {
			string ss = getMinShift(s.substr(i, n / k));
			mn = min(mn, ss);
			mx = max(mx, ss);
		}
		if (mn == mx) {
			ans.push_back(k);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << " \n"[i + 1 == (int)ans.size()];
	}

	return 0;
}