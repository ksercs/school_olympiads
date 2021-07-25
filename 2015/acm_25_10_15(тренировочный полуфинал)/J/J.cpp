#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int a, b, c, d, e;

int point_in_segment(pair <int, int> pi, int p)
{
    if (pi.first > pi.second) {swap(pi.first, pi.second);}
    if (p >= pi.first && p <= pi.second) {return 1;}
    return 0;
}

int e_ravno_d(int a1, int a2)
{
    if (a1 == a2) {return 0;}
    return 1;
}

void in()
{
    ifstream cin ("stars.in");
    cin >> a >> b >> c >> d >> e;
}

void out()
{
     ofstream cout ("stars.out");
     cout << max((min(b, c)-a-(e-d)-point_in_segment(make_pair(a, b), c)), 0) << " " << max((b-a-e_ravno_d(e, d)),0) << "\n";
}

int main()
{
    in();
    out();
return 0;
}
