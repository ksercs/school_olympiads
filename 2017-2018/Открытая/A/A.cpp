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

using namespace std;

LL a, b, s;

void in()
{
    //ifstream cin("A.in");
    cin >> a >> b;
}

void solution()
{
    if (a > b)
        swap(a, b);
    s = a*a;
    if (a == b)
        return;
    b -= a;
    s += min(a,b)*min(a,b);
}

void out()
{
    //ofstream cout("A.out");
    cout << s << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
