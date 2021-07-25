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

const int maxn = (int)1e5 + 10;

int a[maxn];
int d[1 << 22];

int main() {
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
		d[a[i]]++;
	}

	for (int i = 0; i < 22; i++) 
		for (int mask = 0; mask < (1 << 22); mask++) {
			if ((mask & (1 << i)) == 0) {
				d[mask | (1 << i)] += d[mask];
			}
		}	

	for (int i = 0; i < n; i++) {
		printf("%d ",d[(1 << 22) - 1 - a[i]]);
	}

	return 0;
}
