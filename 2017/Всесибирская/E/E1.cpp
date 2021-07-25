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
#include <queue>
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long
#define PDD pair <double, double>

using namespace std;

const int MAXN = 55;
const double EPS = 0.000001;

int n, answer;
PDD ans;
map < PDD, set <int> > mp;
VEC < PDD > yr;
map < PDD, PII > koor;

struct point
{
   double x, y;
} p[MAXN];

double getb(double x1, double y1, double x2, double y2)
{
    return 1.0*y1-x1*(y2-y1)/(x2-x1);
}

double getk(double x1, double y1, double x2, double y2)
{
    return 1.0*(y2-y1)/(x2-x1);
}

double getx(double k1, double b1, double k2, double b2)
{
    return 1.0*(b2-b1)/(k1-k2);
}
double gety(double k1, double b1, double k2, double b2)
{
    return 1.0*(b2-b1)/(k1-k2)*k1+b1;
}

bool intersec(PII p1, PII p2)
{
    int fl = 0;
    double x1, x2, x3, x4, y1, y2, y3, y4;
    x1 = p[p1.FF].x;
    x2 = p[p1.SS].x;
    y1 = p[p1.FF].y;
    y2 = p[p1.SS].y;
    x3 = p[p2.FF].x;
    x4 = p[p2.SS].x;
    y3 = p[p2.FF].y;
    y4 = p[p2.SS].y;
    if ( (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4) > -EPS && (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4) < EPS ) fl = 1;
    cout << fl << "\n";
    return fl;
}

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
}

void solution()
{
    for (int i = 1; i < n-1; i++)
        for (int j = i+1; j <= n; j++){
            if ( (abs(i-j)==1) || (abs(i-j)==n-1) ) continue;
            double k = getk(p[i].x, p[i].y, p[j].x, p[j].y);
            double b = getb(p[i].x, p[i].y, p[j].x, p[j].y);
            //cout << k << " " << b << "\n";
            yr.PB( MP(k,b) );
            koor[MP(k,b)] = MP(i,j);

        }
    for (int i = 0; i < yr.SZ-1; i++)
        for (int j = i+1; j < yr.SZ; j++){
            double X, Y;
            if ( intersec( koor[yr[i]], koor[yr[j]] ) ) continue;
            X = getx(yr[i].FF, yr[i].SS, yr[j].FF, yr[j].SS);
            Y = gety(yr[i].FF, yr[i].SS, yr[j].FF, yr[j].SS);
            //cout << X << " " << Y << "\n";
            mp[MP(X,Y)].insert(i);
            mp[MP(X,Y)].insert(j);
            if (mp[MP(X,Y)].SZ > answer){
                answer = mp[MP(X,Y)].SZ;
                ans = MP(X,Y);
            }
        }

}

void out()
{
    ofstream cout("output.txt");
    cout << answer << "\n";
    cout.precision(12);
    cout << fixed  << ans.FF << " " << ans.SS << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
