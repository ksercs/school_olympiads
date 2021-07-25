#include <iostream>

using namespace std;

int n, k, ans;

void in()
{
    cin >> n >> k;
}

void solution()
{
    if (k == 0) {ans = 1; return;}
    if (k == 1) {ans = 2; return;}
    if ( n%2 == 0 )
    {
        if (k < n/2) ans = k+1;
        else         ans = n/2;
    }
    else
    {
        if (k < n) ans = k+1;
        else       ans = n;
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
