#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <set>

#define PII pair <int,int>
#define MP make_pair
#define SS second
#define FF first

using namespace std;

const int NMAX = (int)1e3+5;

int n, m, ans;

char tb[NMAX][NMAX];
PII dsu[NMAX][NMAX];
int siz[NMAX][NMAX];

set < PII > st;

void make_dsu()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			dsu[i][j] = MP(i, j);
			siz[i][j] = 1;
		}
	}
}

PII find_set(int i, int j)
{
	//cout << i << " " << j << "\n";
	if( dsu[i][j] != MP(i, j) ) dsu[i][j] = find_set(dsu[i][j].FF, dsu[i][j].SS);
	return dsu[i][j];
}

void union_sets(PII a, PII b)
{
	//cout << a.FF << " " << a.SS << " " << b.FF << " " << b.SS << "\n";
	a = find_set(a.FF, a.SS);
	b = find_set(b.FF, b.SS);
    if (siz[a.FF][a.SS] < siz[b.FF][b.SS]) swap(a, b);
    siz[a.FF][a.SS] += siz[b.FF][b.SS];
    dsu[b.FF][b.SS] = a;
}

void in()
{
	ifstream cin("input.txt");
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> tb[i][j];
		}
	}
}

void solution()
{
	make_dsu();
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			//cout << i << " " << j << "\n";
			if(tb[i][j] == 'N') union_sets( MP(i, j), MP(i - 1, j) );
			if(tb[i][j] == 'S') union_sets( MP(i, j), MP(i + 1, j) );
			if(tb[i][j] == 'W') union_sets( MP(i, j), MP(i, j - 1) );
			if(tb[i][j] == 'E') union_sets( MP(i, j), MP(i, j + 1) );
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			st.insert( find_set(i, j) );
		}
	}
	ans = st.size();
}

void out()
{
	ofstream cout("output.txt");
	cout << ans << "\n";
}

int main()
{
	in();
	solution();
	out();
	return 0;
}

