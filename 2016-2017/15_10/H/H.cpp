#include <iostream>
#include <fstream>
#include <vector>

#define sp " "

using namespace std;

int n, m, T;
long long ans1, ans2;
vector <int> a;

void in()
{
    ifstream cin ("queue.in");
    cin >> n >> m >> T;
    a.resize(n);
    for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		ans1 += (long long) a[i];
    }
    for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		if ((n & 1) && t <= T)
		{
			++ans2;
		}
    }
}

void solution()
{
    if (n & 1)
	{
		ans1 -= (long long) a[0];
    }
}

void out()
{
     ofstream cout ("queue.out");
     cout << ans1 << sp << ans2 << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
