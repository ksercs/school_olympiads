#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define VEC vector
#define MP make_pair
#define PB push_back
#define SS second
#define FF first
#define SZ size()

const int MAXN = (int)1e5+5;

int n, m;

VEC < pii > P[MAXN];
VEC <int> Color;

void in()
{
    ifstream cin("magic.in");
    cin >> n >> m;
    //cout << n << " " << m << endl;
	Color.resize(n);
    for (int i = 0; i < m; i++)
    {
        //cout << i << endl;
		int a, b, e;
		cin >> a >> b >> e;
		a--, b--;
		P[a].PB(MP(b, e));
		P[b].PB(MP(a, e));
	}
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        //cout << i << endl;
		ll a, b;
		a = b = 0;
		for(int j = 0; j < P[i].SZ; j++)
		{
		    pii u = P[i][j];
			if(u.FF < i)
			{
				if(Color[u.FF])  a += u.SS;
				else             b += u.SS;
			}
		}
		if (a < b) Color[i] = 1;
	}
}

void out()
{
    ofstream cout("magic.out");
    for (int i = 0; i < n-1; i++)
    {
        cout << Color[i] << " ";
    }
    cout << Color[n-1] << endl;
}

int main()
{
	in();
	solution();
	out();
	return 0;
}
