/*
	Author: Adilet Zhaxybay
	Date: 09.03.15
	Description: Right solution with Ford-Fulkerson
*/               

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

using namespace std;

const int MAXN = 3050;
const int INF = (int) 1e9;

struct edge {
	int from, to, f, cap;
};

int n, m, k;

vector <edge> e;
vector <int> g[MAXN];
bool used[MAXN];
int s, t;
int ans;

void addEdge(int from, int to, int cap) {
	edge ed;

	ed.from = from; ed.to = to; ed.f = 0; ed.cap = cap;
	e.push_back(ed);
	g[from].push_back((int) e.size() - 1);

	ed.from = to; ed.to = from; ed.f = cap; ed.cap = cap;
	e.push_back(ed);
	g[to].push_back((int) e.size() - 1);
}

int pushFlow(int v, int flow = INF) {
	used[v] = true;
	if (v == t)
		return flow;	

	for (int i = 0; i < (int) g[v].size(); i++) {
		int ind = g[v][i];
		int to = e[ind].to; 
		int f = e[ind].f;
		int cap = e[ind].cap;

		if (used[to] || cap - f == 0)
			continue;

		int pushed = pushFlow(to, min(flow, cap - f));
		if (pushed > 0) {
			e[ind].f += pushed;
			e[ind ^ 1].f -= pushed;
			return pushed;
		}
	}

	return 0;	
}

int main() {
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);

	scanf("%d %d %d", &n, &m, &k);

	s = 0; t = m + 2 * n + k + 1;
	
	for (int i = 1; i <= n; i++) {
		addEdge(m + i, m + n + i, 1);
	}

	for (int i = 1; i <= m; i++) {
		int num;
		scanf("%d", &num);
		addEdge(s, i, num);
	}

	for (int i = 1; i <= k; i++) {
		int num;
		scanf("%d", &num);
		addEdge(m + 2 * n + i, t, num);
	}

	for (int i = 1; i <= n; i++) { 
		int num;
		scanf("%d", &num);
		for (int j = 1; j <= num; j++) {
			int x;
			scanf("%d", &x);
			addEdge(x, m + i, 1);
		} 
	}

    for (int i = 1; i <= n; i++) { 
		int num;
		scanf("%d", &num);
		for (int j = 1; j <= num; j++) {
			int x;
			scanf("%d", &x);
			addEdge(m + n + i, m + 2 * n + x, 1);
		} 
	}                                    

	while (true) {
		for (int i = s; i <= t; i++)
			used[i] = false;
		int add = pushFlow(s);
		if (add == 0)
			break;
		ans += add;
	}

	cout << ans << endl;

	return 0;
}