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

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const LL INF = (LL)2*1e18;

LL n, ans = INF, a, b, c;

void in()
{
    ifstream cin("input.txt");
    cin >> a >> b >> c >> n;
}

void solution()
{
    ans = min( n*a, min((n/7+(n%7>0))*b,  (n/28+(n%28>0))*c));
    ans = min(ans, n/28*c + (n%28)/7*b + ((n%28)%7)*a);
    ans = min(ans, n/28*c + (n%28)*a);
    ans = min(ans, n/7*b + (n%7)*a);
    ans = min(ans, n/28*c + ((n%28)/7 +((n%28)%7>0))*b);
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
