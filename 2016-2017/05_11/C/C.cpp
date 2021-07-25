#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#define PB push_back
#define SZ size()

using namespace std;

int n;
long long v, S;
double ans;

struct point
{
    int x, y;
};

struct polygon
{
    vector <point> points;
};

long long get_S_Pol(polygon Pol)
{
    long long answer = 0;
    int s = Pol.points.SZ;
    for (int i = 0; i < s; i++)
    {
        int ax = Pol.points[i].x;
        int ay = Pol.points[i].y;
        int bx = Pol.points[(i+1)%s].x;
        int by = Pol.points[(i+1)%s].y;
        answer += (long long)(1LL*ax*by - 1LL*ay*bx);
    }
    return answer;
}

void in()
{
    ifstream cin("glasses.in");
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
    {
       polygon Poly;
       int a;
       cin >> a;
       for (int i = 0; i < a; i++)
       {
           point p;
           cin >> p.x >> p.y;
          // cout << p.x << " " << p.y << endl;
           Poly.points.PB(p);
       }
       S += get_S_Pol(Poly);
       //cout <<"S = " << S << endl;
    }
}

void solution()
{
  ans = v*2.0/S;
}

void out()
{
    ofstream cout ("glasses.out");
    cout << fixed << setprecision(12) << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
