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

int n, a, b, ans;

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> a >> b;
    int one = 0, two = 0, half = 0;
    for (int i = 1; i <= n; ++i){
        int t;
        cin >> t;
        if (t == 1){
            if (one < a) ++one;
            else if (two+half < b) ++half;
                 else if (half > 0){
                        --half;
                        ++two;
                     }
                     else ++ans;
        }
        else if (two+half < b) ++two;
             else              ans += 2;
    }
}


void out()
{
    //ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
