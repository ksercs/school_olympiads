#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX_PL_CNT = 1000 + 5;

int n, a, b, en_p, ans;
int cn[MAX_PL_CNT][MAX_PL_CNT];

void in()
{
    ifstream cin ("cinema.in");
    cin >> n >> a >> b;
    en_p = n/2 + 1;
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int g = 1; g <= n; g++)
        {
            if (abs(en_p - i) >= a && abs(en_p - g) >= b) {ans++;}
        }
    }
}

void out()
{
     ofstream cout ("cinema.out");
     if (ans == 0) {cout << "0\n";}
     else           {cout << ans-1 << "\n";}
}

int main()
{
    in();
    solution();
    out();
return 0;
}
