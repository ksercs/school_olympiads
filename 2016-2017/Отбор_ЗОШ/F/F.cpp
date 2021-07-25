#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double ans;

struct point
{
    double x, y;
};

point p1, p2, p3;

void in()
{
    ifstream cin("input.txt");
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
}

void solution()
{

}

void out()
{
    ofstream cout("output.txt");
    cout << fixed << setprecision(12) << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
