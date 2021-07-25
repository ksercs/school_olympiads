#include <iostream>

using namespace std;

const int MOD = int(1e9) + 7;

int n, sum = 252, per, ost, tmp = 0;
long long ans;

int s[] = {0, 3, 3, 18, 18, 21, 21, 84, 84};

void in()
{
    cin >> n;
    n--;
}

void solution()
{
  per = n/8;
  ost = n%8;
  int st= 8;
  for (int i = 1; i <= per; i++ )
  {
      ans += sum + 8*tmp;
      ans %= MOD;
      //tmp += 84;
      tmp += (st*st)-1 + 105;
      st *= 2;
  }
  for (int i = 1; i <= ost; i++)
  {
      ans += s[i];
      ans %= MOD;
  }
  ans += tmp*ost;
  ans%= MOD;
}

void out()
{
    cout << ans%MOD << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
