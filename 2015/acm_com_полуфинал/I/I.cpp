#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int s, sh, i=1;

void in()
{
    ifstream cin ("cheese.in");
    cin >> s;
}

void solution()
{
    sh=1;
    while (s>=4*sh)
    {
        sh=sh*4;
        i++;
    }
}

void out()
{
     ofstream cout ("cheese.out");
     cout << i <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
