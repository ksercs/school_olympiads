#include <iostream>
#include <fstream>
#include <algorithm>

#define LL long long

using namespace std;

const int MAXN = (int)1e5+50;

LL n, g, sum, cnt;
LL num[MAXN];

LL gcd_R(LL a, LL b)
{
    return ( (a&&b) ? gcd_R(b, a%b) : (a|b)  );
}


void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        //sum += num[i];
        //if (num[i] == 0) continue;
        //g = gcd_R(g, num[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        sum += num[i];
        if (num[i] == 0) continue;
        if (g == 0) g = num[i];
        else        g = gcd_R(g, num[i]);
    }
}

void solution()
{
   cnt = sum/g;
}

void out()
{
    ofstream cout("output.txt");
    cout << g << endl << cnt << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
