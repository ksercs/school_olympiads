#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MOD = (int)1e9+7;

long long P[100+5][100+5], ans;
int n;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
}

void solution()
{
    for (int i = 0; i < 100; i ++) P[i][0] = 1;
    for (int j = 0; j < 100; j ++) P[0][j] = 1;
    for (int i = 1; i < 100; i ++)
    {
        for (int j = 1; j < 100; j ++) P[i][j] = P[i - 1][j] + P[i][j - 1];
    }
    for (int a = 1; a <= n; a++)
    {
        for (int b = 1; b <= n-a; b++)
        {
            int c = n-a-b;
            ans += (P[b+a-1][a-1]%MOD * P[c+b-1][b-1]%MOD)%MOD;
        }
    }
    ans %= MOD;
    if (n == 1 || n == 2) ans++;
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
