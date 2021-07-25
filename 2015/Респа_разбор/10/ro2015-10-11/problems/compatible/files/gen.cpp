#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>

using namespace std;

int n;
const int maxn = (4e6);
int p = (int)(1e4);

int main() {
	srand(time(NULL));
//	freopen("compatible.in", "w", stdout);
	n = p;

	printf("%d\n", n);
	for (int i = 0; i < n; i++)
		printf("%d ", rand() % maxn + 1);

	return 0;
}
