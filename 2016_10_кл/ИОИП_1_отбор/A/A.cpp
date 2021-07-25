#include <iostream>
#include <fstream>

using namespace std;

int a, b, h, w, ans1, ans2;

void in()
{
    ifstream cin ("bb8.in");
    cin >> a >> b >> h >> w;
}

void solution()
{
    ans1 += h/a;
    h%=a;
    if (h != 0) ans1++;
    ans2 += w/b;
    w%=b;
    if (w != 0) ans2++;
}

void out()
{
     ofstream cout ("bb8.out");
     cout << ans1*ans2 <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
