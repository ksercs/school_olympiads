#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 200000+5;
const int MOD = 1000000000 + 7;

long long dp[MAX];

int n, k, ans;

void in()
{
    ifstream cin("strength.in");
    cin >> n >> k;
}

void solution()
{
    dp[1] = 1; dp[2] = 1;
    for (int i = 3; i <= 2*k+1; i++)
    {
        dp[i] = (dp[i-1]+dp[i-2])%MOD;
    }
  ans = (dp[2*k+1]*n)%MOD;
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
