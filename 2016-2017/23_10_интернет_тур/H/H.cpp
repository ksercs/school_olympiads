#include <iostream>

using namespace std;

int n;

long long ans[]={0, 100, 200, 400, 800, 1600, 3200, 6400, 13000, 26000, 52000, 104000, 208000, 416000, 832000, 1670000, 3340000, 6680000, 13360000, 26720000, 53440000, 106900000, 213800000, 427600000, 855200000, 1710400000};

void in()
{
  cin >> n;
}

void out()
{
  for (int i = 1; i <= n; i++)
  {
      cout << ans[i] << endl;
  }
}

int main()
{
    in();
    out();
    return 0;
}
