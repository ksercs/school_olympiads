#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int a, b;

void in()
{
    ifstream cin ("pay.in");
    cin >> a >> b;
}

void solution()
{
}

void out()
{
     ofstream cout ("pay.out");
     cout <<a*b <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
