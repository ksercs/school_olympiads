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
#include <climits>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

int a, b, c, d, fl, ch;
LL tm;

void in()
{
    ifstream cin("input.txt");
    cin >> a >> b >> c >> d;
}

void solution()
{
    if (a < c){
        swap(b,d);
        swap(a,c);
    }
    tm = b;
    while (tm < LLONG_MAX-a-1 && ch < (int)5*1e6){
        if ( (tm-d) >= 0 && (tm-d)%c == 0 ){
            fl = 1;
            break;
        }
        tm += a;
        ++ch;
    }
}

void out()
{
    fstream cout("output.txt");
    if (fl) cout << tm << "\n";
    else    cout << "-1\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
