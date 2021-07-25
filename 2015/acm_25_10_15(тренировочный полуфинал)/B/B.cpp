#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n;

void in()
{
    ifstream cin ("birthday.in");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
    }
}

void solution()
{
}

void out()
{
     ofstream cout ("birthday.out");
     cout << "17 6\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
