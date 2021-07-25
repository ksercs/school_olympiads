#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

long long L, R, Lch, Rch;
int lcnt, rcnt, ans;

void get_L(long long left)
{
    while (left > 0)
    {
        left /= 10;
        lcnt++;
        Lch *= 10;
        Lch += 1;
    }
}

void get_R(long long right)
{
    while (right > 0)
    {
        right /= 10;
        rcnt++;
        Rch *= 10;
        Rch += 1;
    }
}

void in()
{
    ifstream cin("travelling.in");
    cin >> L >> R;
}

void solution()
{
    get_L(L);
    get_R(R);
    //cout << "L: " <<lcnt << " " << Lch << endl;
    //cout << "R: " <<rcnt << " " << Rch << endl;
    ans += max((rcnt-lcnt-1), 0)*9;
    if (lcnt != rcnt)
    {
        ans += 9 - L/Lch + R/Rch;
        if (L % Lch == 0) ans++;
       // if (R % Rch == 0) ans++;
    }
    else              ans += (R/Rch - L/Lch + (L%Lch==0));
    //if (R/Rch == 0 || lcnt == rcnt) ans++;
}

void out()
{
    ofstream cout("travelling.out");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
