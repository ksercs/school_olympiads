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

int a, b, ans;

int gcd_R(int a, int b)
{
    return (a && b) ? gcd_R(b, a%b) : (a|b);
}

void in()
{
    //ifstream cin("input.txt");
    cin >> a >> b;
}

void solution()
{
    ans = gcd_R(a,b);
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
