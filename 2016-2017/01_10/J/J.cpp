#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define db double

using namespace std;

db tr[4][4];
db ans;

db get_S(db a, db b, db c)
{
    double p = (a+b+c)/(2.0);
    return sqrt( p*(p-a)*(p-b)*(p-c) );
}

void in()
{
    ifstream cin ("triangles.in");
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> tr[i][j];
        }
    }
}

void solution()
{
    ans = sqrt( (get_S(tr[1][1], tr[1][2], tr[1][3]) + get_S(tr[2][1], tr[2][2], tr[2][3]) + get_S(tr[3][1], tr[3][2], tr[3][3]) )/6.0 );
}

void out()
{
     ofstream cout ("triangles.out");
     cout << fixed << setprecision(10) << ans << endl;
}

int main()
{
    in();
    solution();
    out();
return 0;
}
