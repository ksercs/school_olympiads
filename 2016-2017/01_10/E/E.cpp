#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = (int)10e5+5;

int n, ans;
int mass[MAXN];

void in()
{
    ifstream cin ("powerstower.in");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> mass[i];
    }
}

void solution()
{
  if (mass[1]%3 == 0) ans = 0;
  if (mass[1]%3 == 1) ans = 1;
  if (mass[1]%3 == 2)
  {
      if (mass[2]%2 == 1 || n == 1) ans = 2;
      else ans = 1;
  }
}

void out()
{
     ofstream cout ("powerstower.out");
     cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
return 0;
}
