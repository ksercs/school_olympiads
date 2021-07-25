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
#define LD long double

using namespace std;

const LD EPS = 1e-6;

int answer;
VEC <LD> ans;
LL d, a, b, c;

void in()
{
    ifstream cin("roots.in");
    cin >> a >> b >> c;
}

void sol()
{
    if (a == 0){
        if (b == 0){
            if (c == 0)
                answer = -1;
        }
        else{
            answer = 1;
            ans.PB(1.0*(-c)/b);
        }
    }
    else{
        d = b*b - 4*a*c;
        if (d == 0){
            answer = 1;
            ans.PB(1.0*(-b)/2/a);
        }
        if (d > 0){
            double x1, x2;
            x1 = 1.0*(-b+sqrt(d))/2/a;
            x2 = 1.0*(-b-sqrt(d))/2/a;
            answer = 2;
            ans.PB(min(x1,x2));
            ans.PB(max(x1,x2));
        }
    }
}

void out()
{
    ofstream cout("roots.out");
    cout << answer << "\n";
    if (answer != -1){
        cout.precision(12);
        for (int i = 0; i < answer; ++i)
            cout << fixed << ans[i] << "\n";
    }
}

int main()
{
    in();
    sol();
    out();
    return 0;
}
