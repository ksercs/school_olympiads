#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, m;
long long ans;

void in()
{
    ifstream cin ("squares.in");
    cin >> n >> m;
}

void solution()
{
    if (n > m) swap(n, m);
	for (int i = 1; i <= n;)
	{
		int j = min(n / (n / i), m / (m / i)) + 1;
		ans += 1LL * (n / i) * (m / i) * (j - i);
		i = j;
	}
}

void out()
{
     ofstream cout ("squares.out");
     cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
return 0;
}
