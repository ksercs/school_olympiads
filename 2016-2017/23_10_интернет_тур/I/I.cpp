#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>

#define PII pair <int, int>
#define MP make_pair
#define SS second
#define FF first
#define VEC vector
#define SZ size()
#define PB push_back
#define RSZ resize

using namespace std;

const int MAXN = (int)1e5+5;

int n, m, ans, L=1, R, index;
int u[MAXN];

VEC <VEC <int> > gr;
VEC < PII > ed;
VEC <int> tst;

void dfs (int v)
{
	u[v] = 1;
	for (int i=0; i < gr[v].SZ; ++i)
	{
		int to = gr[v][i];
		cout << "TO = " << to << endl;
        if (!u[to]) dfs (to);
	}
	cout << "V = " << v << endl;
	tst.PB(v);
}

void top_sort()
{
    fill(u, u+n+1, 0);
    tst.clear();
	for (int i = 1; i <= n; ++i)
	{
	    cout <<"I = " << i << endl;
        if (!u[i]) dfs(i);
	}
	tst.PB(0);
	reverse (tst.begin(), tst.end());
}

void get_ans()
{
    top_sort();
    for (int i = 1; i <= n; i++)
    {
        cout << tst[i] << " ";
    }
    cout << endl;
    int ch = 0;
    for (int i = 1; i < n; ++i)
    {
        int a = tst[i];
        VEC <int> help = gr[a];
        sort(help.begin(), help.end());
        cout << a << " " << tst[i+1] << " :: \n";
        for (int j = 0; j < help.SZ; j++)
        {
            cout << help[j] << ", ";
        }
        cout << endl;
        if (binary_search(help.begin(), help.end(), tst[i+1]))   ch++;
    }
    cout << "CH = " << ch << endl;
    if (ch == n-1)
    {
        ans = index;
        R = index;
        index = (L+R)/2;
    }
    else
    {
        L = index;
        index = (L+R)/2;
    }
    cout << "IND = " << index << " L = " << L << " R = " << R << endl;
    system("PAUSE");
    if (index == m || R-L <= 1) return;
    gr.clear();
    gr.RSZ(n+1);
    for (int i = 1; i <= index; i++)
    {
        int a = ed[i].FF;
        int b = ed[i].SS;
        gr[a].PB(b);
    }
    get_ans();
}

void in()
{
  ifstream cin("A.in");
  cin >> n >> m;
  gr.RSZ(n+1);
  ed.RSZ(m+1);
  for (int i = 1; i <= m; i++)
  {
      int a, b;
      cin >> a >> b;
      gr[a].PB(b);
      ed[i] = MP(a, b);
  }
}

void solution()
{
    index = m;
    R = m;
    R = m;
    get_ans();
}

void out()
{
  ofstream cout("A.out");
  if (!ans)      cout << "-1\n";
  else           cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
