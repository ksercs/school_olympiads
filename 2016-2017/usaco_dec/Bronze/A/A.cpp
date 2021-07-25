#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

VEC <int> m1, m2;
int ans, x, y;

void in()
{
    ifstream cin("square.in");
    int x1, y1, x2, y2;
    for (int i = 1; i <= 2; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        m1.PB(x1); m1.PB(x2);
        m2.PB(y1); m2.PB(y2);
    }
}

void solution()
{
    sort(m1.begin(), m1.end());
    sort(m2.begin(), m2.end());
    x = m1[3]-m1[0];
    y = m2[3]-m2[0];
    ans = max(x,y)*max(x,y);
}

void out()
{
    ofstream cout("square.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
