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
	m = atoi(argv[2]);
	k = atoi(argv[3]);
	MAX_REL = atoi(argv[4]);
	
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

	for (int i = 1; i <= m; i++)
		vm.push_back(i);
	for (int i = 1; i <= k; i++)
		vk.push_back(i);
	
	int left = MAX_REL / 2;
	for (int i = 1; i <= n; i++) {
		int num = rnd.next(0, min(left, m));
		left -= num;

		shuffle(vm.begin(), vm.end());
		cout << num;
		for (int j = 1; j <= num; j++) {
			cout << " ";
			cout << vm[j - 1];
		}
		cout << endl;
	}

	left = MAX_REL / 2 + left;
	for (int i = 1; i <= n; i++) {
		int num = rnd.next(0, min(left, k));
		left -= num;

		shuffle(vk.begin(), vk.end());
		cout << num;
		for (int j = 1; j <= num; j++) {
			cout << " ";
			cout << vk[j - 1];
		}
		cout << endl;
	}                 

	return 0;
}