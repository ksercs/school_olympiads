#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

#define SZ size()

using namespace std;

const int MAXN = (int)1e5+5;

int n, x, y, fl;
string mass[MAXN];

void in()
{
    ifstream cin ("presuf.in");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> mass[i];
    }
}

void solution()
{
    for (int i = 1; i < n; i++)
    {
        for (int g = i; g <= n; g++)
        {
            for (int c = 1; c <= min(mass[i].SZ, mass[g].SZ); c++)
            {
                //cout << mass[i].substr(0, c) << " " << mass[g].substr(mass[g].SZ-c, c) << endl;
                if (mass[i].substr(0, c) == mass[g].substr(mass[g].SZ-c, c))
                {
                    x = i; y = g;
                    fl = 1;
                    break;
                }
                if (mass[g].substr(0, c) == mass[i].substr(mass[i].SZ-c, c))
                {
                    x = g; y = i;
                    fl = 1;
                    break;
                }
                if (fl) break;
            }
            if (fl) break;
        }
        if (fl) break;
    }
    if (n == 1)
    {
            for (int c = 1; c < max(2, (int)mass[1].SZ); c++)
            {
                if (mass[1].substr(0, c) == mass[1].substr(mass[1].SZ-c, c))
                {
                    x = 1; y = 1;
                    fl = 1;
                    break;
                }
                if (fl) break;
            }

    }

}

void out()
{
     ofstream cout ("presuf.out");
     if (x != 0) cout << x << " " << y;
     else        cout <<"-1\n";

}

int main()
{
    in();
    solution();
    out();
return 0;
}
