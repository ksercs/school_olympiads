#include <iostream>
#include <fstream>

using namespace std;

const int MOD = 1000000000 + 7;
const int MAXK = (int)1e5 + 5;

int n, k, ans;
long long dp[MAXK];

void in()
{
    ifstream cin("strength.in");
    cin >> n >> k;
}

void solution()
{
  dp[0] = 1;
  dp[1] = 2;
  dp[2] = 5;
  for (int i = 3; i <= k; i++)
  {
      dp[i] = ((dp[i-1]*3) - dp[i-2]);
      if (dp[i] %5 == 0) dp[i] %= MOD;
      cout << i <<": " << dp[i] << endl;
  }
  ans = (dp[k]*n)%MOD;
}

void out()
{
    ofstream cout("strength.out");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
