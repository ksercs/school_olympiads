#include <iostream>
#include <algorithm>

using namespace std;

int k2, k3, k5, k6, d1, d2;
long long ans;

void in()
{
    cin >> k2 >> k3 >> k5 >> k6;
}

void solution()
{
  d2 = min(k2, k5);
  d2 = min(d2, k6);
  ans += d2*256;
  k2 -= d2;
  d1 = min(k2, k3);
  ans += d1*32;
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
