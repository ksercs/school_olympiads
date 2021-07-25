#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

long long n, m, ans, pl=1;


void in()
{
    ifstream cin("numbers.in");
    cin >> n >> m;
}

void solution()
{
    int c = n;
    while(c > 0)
    {
        pl*=10;
        c/=10;
    }
    ans = (m-n)/pl+1;
}

void out()
{
    ofstream cout("numbers.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
