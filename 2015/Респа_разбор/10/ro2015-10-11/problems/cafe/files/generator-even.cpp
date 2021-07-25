#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <time.h>
#include "testlib.h"

using namespace std;

const int MAXN = 500;
int MAX_REL;

int n, m, k;
vector <int> vm, vk;
vector <int> a[MAXN + 10], b[MAXN + 10];
int left;

int main(int argc, char * argv[]) {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));

	registerGen(argc, argv, 1);
	
	//srand(time(NULL));

	n = atoi(argv[1]);
	m = n; k = n;
	
	cout << n << " " << m << " " << k << endl;

	for (int i = 1; i <= m; i++) {
		if (i > 1)
			cout << " ";
		cout << rnd.next(1, MAXN);
	}
	cout << endl;

	for (int i = 1; i <= k; i++) {
		if (i > 1)
			cout << " ";
		cout << rnd.next(1, MAXN);
	}
	cout << endl;

	for (int i = 1; i <= n; i++) {
		cout << 1 << " " << i << endl;
	}

	for (int i = 1; i <= n; i++) {
		cout << 1 << " " << i << endl;
	}

	return 0;
}