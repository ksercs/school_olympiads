#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int a, b, c, d, k;

void in()
{
    ifstream cin ("luigi.in");
    cin >> a >> b >> c >> d >> k;
}

void out()
{
    ofstream cout("luigi.out");
    if (b+d <= k) {cout << "-1\n";}
    else          {cout << min(b,d) << " " << max(b,d)-(b+d)%k << "\n";}
}

int main()
{
    in();
    out();
return 0;
}
