#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#define pw(j) (1<<j)

using namespace std;

const int maxn = (1 << 22);

int n, a[maxn], d[maxn];

int main() {
	freopen("F.in", "r", stdin);
	freopen("F.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		scanf("%d", &a[i]);

	for (int i = 0; i < n; ++i) 
	for (int j = 0; j < n; ++j)
		if ((a[i] & a[j]) == 0) {
			d[i]++;
		}

	for (int i = 0; i < n; ++i)
		printf("%d ", d[i]);

	return 0;
}

