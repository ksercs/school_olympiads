#include <iostream>
#include <fstream>
#include <algorithm>

#define LL long long

using namespace std;

LL w, h, x0, y0, x1, y1, dx, dy, ans;

void in()
{
    ifstream cin("input.txt");
    cin >> w >> h >> x0 >> y0 >> x1 >> y1;
}

void solution()
{
   if (x1 < x0) swap(x1, x0);
   if (y1 < y0) swap(y1, y0);
   dx = x1-x0;
   dx = min(dx, w-x1+x0);
   dy = y1-y0;
   dy = min(dy, h-y1+y0);
   ans = dx+dy;
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
