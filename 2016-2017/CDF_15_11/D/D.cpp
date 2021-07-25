#include <iostream>
#include <algorithm>

using namespace std;

int n, x1, y1, fl;

void in()
{
    cin >> n;
    cin >> x1 >> y1;
    for (int i = 1; i <= n; i++)
    {
        char s;
        int x, y;
        cin >> s >> x >> y;
        if (s == 'R' && (x == x1 || y == y1)) fl = 1;
        if (s == 'B' && abs(x1-x) == abs(y1-y)) fl = 1;
        if (s == 'Q' && ((x == x1 || y == y1) || abs(x1-x) == abs(y1-y)) ) fl = 1;
    }
}

void out()
{
    if (fl) cout << "YES\n";
    else    cout << "NO\n";
}

int main()
{
    in();
    out();
    return 0;
}
