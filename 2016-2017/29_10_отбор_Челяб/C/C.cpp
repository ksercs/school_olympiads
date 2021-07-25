#include <iostream>

using namespace std;

int n, k, ans;

void del()
{
    int m = k%n;
    ans += m;
    k -= (m+k/n);
    //cout << ans << " " << k << endl << endl;
}

void in()
{
  cin >> n >> k;
}

void solution()
{
  for (int i = 1; i <= n+1; i++)
  {
      del();
  }
}

void out()
{
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
