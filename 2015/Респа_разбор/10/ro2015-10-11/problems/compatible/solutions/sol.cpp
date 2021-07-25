#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>
#include <ctime>
#define pw(j) (1<<j)

using namespace std;

const int maxn = (1 << 22);

int n, a[maxn], d[maxn];

int main() {
	freopen("F.in", "r", stdin);
	freopen("F.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		d[a[i]]++;
	}                       

	for (int i = 0; i < 22; ++i)
	for (int mask = 1; mask < (1 << 22); ++mask)
		if (!(mask & (1 << i)))
			d[mask + (1 <<i)] += d[mask];

	for (int i = 0; i < n; ++i)
		printf("%d ", d[(1 << 22) - a[i] - 1]);

	return 0;
}
