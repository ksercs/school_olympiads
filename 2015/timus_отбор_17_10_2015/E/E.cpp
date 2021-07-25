#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int m[5], otvet;

void in()
{
    cin >> m[0] >> m[1] >> m[2];
}

void solution()
{
    sort(m, m+3);
    otvet=m[0]-m[1]*m[2];
    if (m[0]-m[1]-m[2]<otvet) {otvet=m[0]-m[1]-m[2];}
}

void out()
{
    cout << otvet <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
