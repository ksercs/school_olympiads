#include <iostream>
#include <fstream>

using namespace std;

int r1, r2, h1, h2, ans;

int gcd_R(int a, int b)
{
    return ( (a&&b) ? gcd_R(b, a%b) : (a|b)  );
}

void in()
{
    ifstream cin("input.txt");
    cin >> r1 >> r2 >> h1 >> h2;
}

void solution()
{
    int ch = r2*r2*h2;
    ans = ch / gcd_R(ch, r1*r1*h1);
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
