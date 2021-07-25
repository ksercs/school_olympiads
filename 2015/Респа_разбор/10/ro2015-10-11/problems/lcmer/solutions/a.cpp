#pragma comment(linker, "/STACK:640000000")
#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<algorithm>

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)

using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);

const int mod = (int)1e9 + 7;

void get(int n, vector<int> &v) {
	int x = 2;
	while(x * x <= n) {
		if (n % x == 0) {
			int p = 1;
			while(n % x == 0) {
				 n /= x;
				 p *= x;
			}
			v.pb(p);
		}
		x++;
	}
	if (n > 1) v.pb(n);
}

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int cnt[1 << 9];
int dp[111][1 << 9];
int DP[111],dd[111][111];
int f[111],o[111];
int c[111][111];

int binpow(int a, int b) {
	int res = 1;
	while(b) {
		if (b & 1) res = res * 1LL * a % mod;
		a = a * 1LL * a % mod;
		b >>= 1;
	}
	return res;
}

int main() {
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);

	for (int i = 0; i < 111; i++) {
		c[i][0] = 1;
	}
	for (int i = 1; i < 111; i++) {
		for (int j = 1; j <= i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= mod) c[i][j] -= mod;
		}
	}

	f[0] = 1;

	for (int i = 1; i < 111; i++) {
		f[i] = f[i - 1] * 1LL * i % mod;
	}
	for (int i = 0; i < 111; i++) {
		o[i] = binpow(f[i],mod - 2);
	}

	int L,R,A,n; cin >> n >> L >> R >> A;

	vector<int> v;	

	get(A,v);

	int m = sz(v);

	for (int mask = (1 << m) - 1; mask >= 0; mask--) {
		int l = 1;
		for (int i = 0; i < m; i++) if (mask & (1 << i)) {
			l = l / __gcd(l,v[i]) * v[i];
		}
		int val = R / l - (L - 1) / l;
		for (int sub = mask;; sub = (sub - 1) & mask) {
			if (bit(mask ^ sub) % 2 == 0) {
				cnt[sub] += val;
			} else {
				cnt[sub] -= val;
			}
			if (sub == 0) break;
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int mask = 0; mask < (1 << m); mask++) {
			for (int sub = 0; sub < (1 << m); sub++) {
				add(dp[i + 1][mask | sub],dp[i][mask] * 1LL * cnt[sub] % mod);
			}
		}
	}

	dd[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= j; k++) {
				add(dd[i][j],dd[i - 1][j - k] * 1LL * o[k + 1] % mod);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		DP[i] = dp[i][(1 << m) - 1];
		for (int j = i - 1; j >= 1; j--) {
			DP[i] -= DP[j] * 1LL * dd[j][i - j] % mod * 1LL * f[i] % mod;
			if (DP[i] < 0) DP[i] += mod;
		}
		DP[i] = DP[i] * 1LL * o[i] % mod;
	}

	int res = 0;

	for (int i = 1; i <= n; i++) {
		add(res,DP[i] * 1LL * c[n - 1][i - 1] % mod);
	}

	cout << res << endl;

	return 0;
}
