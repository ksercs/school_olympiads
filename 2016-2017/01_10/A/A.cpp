#include <iostream>
#include <fstream>

using namespace std;

int a, b, c, d, e, f;
long long ma, me;

void in()
{
    ifstream cin ("cinemaholics.in");
    cin >> a >> b >> c >> d >> e >> f;
}

void solution()
{
    ma = a*3+b*20+c*120;
    me = d*3+e*20+f*120;
}

void out()
{
     ofstream cout ("cinemaholics.out");
     if (ma > me) cout << "Max\n";
     if (ma < me) cout << "Mel\n";
     if (ma == me) cout << "Draw\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
