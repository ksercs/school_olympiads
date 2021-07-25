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
		cout << rnd.next(MAXN - 50, MAXN);
	}
	cout << endl;

	for (int i = 1; i <= k; i++) {
		if (i > 1)
			cout << " ";
		cout << rnd.next(MAXN - 50, MAXN);
	}
	cout << endl;

	for (int i = 1; i <= m; i++)
		vm.push_back(i);
	for (int i = 1; i <= k; i++)
		vk.push_back(i);
	
	int left = MAX_REL / 2;
	for (int i = 1; i <= left; i++) {
		int p = rnd.next(1, n);
		if ((int) a[p].size() == m) 
			continue;
		set <int> st;
		left--;
		for (int j = 0; j < (int) a[p].size(); j++) {
			st.insert(a[p][j]);
		}
		for (int j = 1; j <= m; j++)
			if (st.count(j) == 0) {
				a[p].push_back(j);
				break;
			}
	}

	for (int i = 1; i <= n; i++) {
		cout << (int) a[i].size();
		shuffle(a[i].begin(), a[i].end());
		for (int j = 0; j < (int) a[i].size(); j++) {
			cout << " " << a[i][j];
		}
		cout << endl;
	}

	left = MAX_REL / 2 + left;
	for (int i = 1; i <= left; i++) {
		int p = rnd.next(1, n);
		if ((int) b[p].size() == k) 
			continue;
		left--;
		set <int> st;
		for (int j = 0; j < (int) b[p].size(); j++) {
			st.insert(b[p][j]);
		}
		for (int j = 1; j <= k; j++)
			if (st.count(j) == 0) {
				b[p].push_back(j);
				break;
			}
	}

    for (int i = 1; i <= n; i++) {
		cout << (int) b[i].size();
		shuffle(b[i].begin(), b[i].end());
		for (int j = 0; j < (int) b[i].size(); j++) {
			cout << " " << b[i][j];
		}
		cout << endl;
	}

	return 0;
}