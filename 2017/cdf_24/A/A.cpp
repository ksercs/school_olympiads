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

LL n, ans, x, a, b, c;

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> x;
}

void get_ans(int ch)
{
    //cout << ch << " : " << a << " " << b << " " << c << "\n";
    if (ch == 0){
        if (a == 1) ans = 0;
        if (b == 1) ans = 1;
        if (c == 1) ans = 2;
        return;
    }
    if (!(ch%2)) swap(b, c);
    else       swap(a, b);
    get_ans(ch-1);
}

void solution()
{
    n %= 6;
    if (x == 0) a = 1;
    else if(x == 1) b = 1;
         else       c = 1;
    get_ans(n);
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
