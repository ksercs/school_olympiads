#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define vec vector
#define SZ size()

using namespace std;

int n, k, cnt;
long long ans;

vec <int> num;

bool cmp(int a, int b)
{
    return a > b;
}

void in()
{
    ifstream cin ("digits.in");
    cin >> n >> k;
    num.resize(n*10+1);
    for (int i = 1; i <= n; i++)
    {
        int ch, st = 1;
        cin >> ch;
        while (ch > 0)
        {
           num[cnt] = ((9-ch%10)*st);
           cnt++;
           st*=10;
           ch /= 10;
        }
    }
    num.resize(cnt);
}

void solution()
{
    sort(num.begin(), num.begin()+cnt, cmp);
    for (int i = 0; i < min(cnt, k); i++)
    {
        ans += num[i];
    }
}

void out()
{
     ofstream cout ("digits.out");
     cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
