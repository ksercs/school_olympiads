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

const int maxn = 2005;

int c[maxn][maxn],f[maxn][maxn];
int ptr[maxn],lvl[maxn];
int A[maxn],B[maxn];
int S,T;

bool bfs() {
	memset(lvl,-1,sizeof(lvl));
	lvl[S] = 0;
	queue<int> q;
	q.push(S);
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for (int i = 0; i <= T; i++) if (c[v][i] > f[v][i] && lvl[i] == -1) {
			lvl[i] = lvl[v] + 1;
			q.push(i);
		}
	}
	return lvl[T] != -1;
}

bool dfs(int v) {
	if (v == T) return true;
	for (int &i = ptr[v]; i <= T; i++) if (c[v][i] > f[v][i] && lvl[i] == lvl[v] + 1) {
		if (dfs(i)) {
			f[v][i]++;
			f[i][v]--;
			return true;
		}
	}
	return false;
}

int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);

	int n,m,k; cin >> n >> m >> k;

	S = m + k + 2 * n;
	T = m + k + 2 * n + 1;

	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		c[S][i] = x;
	}

	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		c[m + i][T] = x;
	}

	for (int i = 0; i < n; i++) {
		c[m + k + 2 * i][m + k + 2 * i + 1] = 1;
		int cc; cin >> cc;
		for (int j = 0; j < cc; j++) {
			int x; scanf("%d",&x);
			c[x - 1][m + k + 2 * i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		int cc; cin >> cc;
		for (int j = 0; j < cc; j++) {
			int x; scanf("%d",&x);
			c[m + k + 2 * i + 1][m + x - 1] = 1;
		}
	}

	int res = 0;

	while(bfs()) {
		memset(ptr,0,sizeof(ptr));
		while(dfs(S)) {
			res++;
		}
	}

	cout << res << endl;

	return 0;
}
