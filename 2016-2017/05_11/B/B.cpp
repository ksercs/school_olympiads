#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 2*10000 + 5;

int n, k, fl, nul;
int mass[MAXN], u[MAXN];

void in()
{
    ifstream cin("exhibition.in");
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> mass[i];
        if (mass[i] == 0) nul++;
    }
}

void solution()
{
    if (k > 1)
    {
    for (int i = 1; i <= n-k+1; i++)
    {
        int ch = 1, num = mass[i];
       // if (!u[i])
        for (int j = i+1; j <= n; j++)
        {
            //if (i == j) break;
            //cout << num << " " << mass[j] << " " << (num&mass[j]) << endl;
            if ( (num&mass[j]) == 0)
            {
                //cout << "URA!\n";
                num = (num&mass[j]);
                ch ++;
            }
        }
        if (ch >= k) {fl = 1; break;}
    }
    }
}

void out()
{
    ofstream cout("exhibition.out");
    if (k == 1)
    {
        if (nul > 0) cout << "YES\n";
        else         cout << "NO\n";
    }
    else{
    if (fl) cout << "YES\n";
    else    cout << "NO\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
