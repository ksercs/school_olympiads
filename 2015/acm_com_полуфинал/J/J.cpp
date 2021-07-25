#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, k, ind, ans, st=1;

void in()
{
    ifstream cin ("gold.in");
    cin >> n >> k;
}

void solution()
{
    if (n < 0) {n*=(-1);}
    int ch = n;
    while (ch >= k)
    {
        st*=k;
        ch/=k;
    }
    while (st > 1)
    {
        n%=st;
        st/=k;
    }
}

void out()
{
     ofstream cout ("gold.out");
     if (n == k) {cout << "10\n";}
     if (n < k) {cout << n << "\n";}
     if (n > k) {cout << ans << "\n";}
}

int main()
{
    in();
    solution();
    out();
return 0;
}
