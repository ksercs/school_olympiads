#include <fstream>
using namespace std;

ifstream cin("luigi.in");
ofstream cout("luigi.out");

int main()
{
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    int s = b + d;
    int t = s % k;
    if (b - t >= a) return (cout << b - t << " " << d << endl), 0;
    if (d - t >= c) return (cout << b << " " << d - t << endl), 0;

    cout << "-1\n";
    return 0;
}
