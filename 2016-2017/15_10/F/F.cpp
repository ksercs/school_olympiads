#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define sp " "

using namespace std;

const int MAXN = (int)1e6+5, INF = (int)(2e9);

int n, ans;
int a[MAXN];

void in()
{
    ifstream cin ("secretroom.in");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] += i;
        //cout << a[i] << sp;
    }
    //cout << endl;
}

void solution()
{
    vector <int> dp(n+1, INF);
    dp[0] = -1;
    for (int i = 0; i < n; i++)
    {
		dp[lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin()] = a[i];
	}
	/*for (int i = 0; i < n; i++)
	{
	    cout << dp[i] << sp;
	}
	cout << endl;*/
    for (int i = n; i >= 0; i--)
        if (dp[i] != INF) {
            ans = i;
            break;
        }
}

void out()
{
    ofstream cout ("secretroom.out");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
