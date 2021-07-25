#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int x, n, ans;

pair <pair <int, int>, int> mass[115];

void in()
{
   cin >> x >> n;
   for (int i = 1; i <= n; i++)
   {
       int a;
       cin >> a;
       mass[i].first.first = a;
   }
   for (int g = 1; g <= n; g++)
   {
       int b;
       cin >> b;
       mass[g].first.second = b;
       mass[g].second = g;
   }
}

void solution()
{
    sort(mass+1, mass+n+1);
    for (int i = n; i >= 1; i--)
    {
        x = max(0, x-mass[i].first.first);
        ans += max(0, mass[i].first.second-x);
    }
}

void out()
{
    cout << ans << "\n";
    for (int i = n; i > 1; i-- )
    {
        cout << mass[i].second << " ";
    }
    cout << mass[1].second << "\n";
}

int main()
{
	in();
	solution();
	out();
	system("PAUSE");
	return 0;
}
