#include <iostream>

using namespace std;

int x, y, a, b, ans, pir, br;

void in()
{
    cin >> x >> y >> a >> b;
}

void solution()
{
    a--; b--;
    pir = a*y;
    br = b*x;
    if (pir < br) ans = 2;
    if (pir > br)          ans = 1;
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
