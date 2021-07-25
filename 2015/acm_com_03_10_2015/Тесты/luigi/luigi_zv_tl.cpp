#include <fstream>
using namespace std;

ifstream cin("luigi.in");
ofstream cout("luigi.out");

int main()
{
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    for (int i = 0; i < d; i++) {
        if ((b - i + d) % k != 0) continue;
        if (b - i >= a) return (cout << b - i << " " << d << endl), 0;
        if (d - i >= c) return (cout << b << " " << d - i << endl), 0;
    }

    cout << "-1\n";
    return 0;
}
