#include <iostream>
#include <algorithm>

using namespace std;

int n, d, ans;

int mass[200000+15];

int main()
{
  cin >> n >> d;
  for (int i = 0; i < n; i++)
  {
      cin >> mass[i];
  }
  sort(mass, mass+n);
  for(int i = 0; i < n-1; i++)
  {
      if (mass[i+1]-mass[i]<=d) {ans++;i++;}
  }
  cout << ans << "\n";
  return 0;
}
