#include <iostream>

using namespace std;

const int MAX_N = 1e5+15;

int n, k;
int C[MAX_N], cap[MAX_N];

long long ans;

void in()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> C[i];
    }
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        cap[a] = 1;
    }
}

void solution()
{
    if (cap[1])
    {
        for (int i = 3; i < n; i++)
        {
            ans += C[1]*C[i];
        }
    }
    if (cap[n])
    {
        for (int i = 2; i < n-1; i++)
        {
            if (!cap[i]) ans += C[n]*C[i];
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (cap[i])
        {
            for (int j = 1; j < i-1; j++)
            {
                if (!cap[j]) ans += C[i]*C[j];
            }
            for (int j = i+2; j <= n; j++)
            {
                ans += C[i]*C[j];
            }
        }
    }
    ans += C[1]*C[n];
    for (int i = 1; i < n; i++)
    {
        ans += C[i]*C[i+1];
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
