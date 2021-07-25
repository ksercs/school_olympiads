#include <iostream>

using namespace std;

long long n, k, t, ans = 0;

int main()
{
  cin >> n >> k;
  t = n/k;
  if (t < k)
  {
   int d = k/t;
   int ost = k%t;
   ans = ((d-1)*(t-ost) + (d+1)*ost)/2*d*t;
  }
  cout << ans << "\n";
  return 0;
}
