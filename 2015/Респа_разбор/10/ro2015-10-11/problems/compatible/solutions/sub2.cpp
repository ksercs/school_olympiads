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

int n, a[maxn], bn[111], b[111][111], d[maxn];
int mx;

int main() {
	freopen("F.in", "r", stdin);
	freopen("F.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		mx = max(mx, a[i]);
	}

	if (mx <= 100) {
   		for (int i = 0; i < n; ++i)
			d[a[i]]++;

	    for (int i = 1; i <= 100; ++i)
	    for (int j = 1; j <= 100; ++j)
    		if ((i & j) == 0) {
    			b[i][bn[i]++] = j;
	      	}
		
		for (int i = 0; i < n; ++i) {
			int res = 0;
			for (int j = 0; j < bn[a[i]]; ++j) {
				int y = b[a[i]][j];
				res += d[y];
			}
			printf("%d ", res);
		}	
	} else {
		for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j)
			if ((a[i] & a[j]) == 0) {
				d[i]++;
			}

		for (int i = 0; i < n; ++i)
			printf("%d ", d[i]);
	}

	return 0;
}
