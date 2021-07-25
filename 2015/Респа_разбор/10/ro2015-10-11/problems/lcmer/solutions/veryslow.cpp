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

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

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

int dp[111][1 << 9][1111];
int is[1111];

int main() {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);


	int n,L,R,A; cin >> n >> L >> R >> A;
	
	if (R > 1000) {
		cout << "TL!";
		return 0;
	}

	vector<int> v;

	get(A,v);

	int m = sz(v);

	for (int i = L; i <= R; i++) {
		for (int j = 0; j < m; j++) if (i % v[j] == 0) {
			is[i] |= 1 << j;	
		}
	}

	dp[0][0][L] = 1;
	
	for (int i = 0; i < n; i++) {
		for (int mask = 0; mask < (1 << m); mask++) {
			for (int j = L; j <= R; j++) {
				for (int k = j; k <= R; k++) {
					add(dp[i + 1][mask | is[k]][k],dp[i][mask][j]);
				}
			}
		}
	}

	int res = 0;

	for (int i = L; i <= R; i++) {
		add(res,dp[n][(1 << m) - 1][i]);
	}

	cout << res << endl;


	return 0;
}
