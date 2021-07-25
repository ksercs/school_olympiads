#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#define PB push_back
#define SZ size()

using namespace std;

int n;
double v, S, ans;

struct point
{
    double x, y;
};

struct polygon
{
    vector <point> points;
};

double get_S_Pol(polygon Pol)
{
    double answer = 0.0;
    int s = Pol.points.SZ;
    for (int i = 0; i < s; i++)
    {
        double ax = Pol.points[i].x;
        double ay = Pol.points[i].y;
        double bx = Pol.points[(i+1)%s].x;
        double by = Pol.points[(i+1)%s].y;
        answer += (ax*by - ay*bx);
    }
    return answer*0.5;
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
  ans = v/S;
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
