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

const int MAXN = (int)1e6 + 5;

int n, ans, L = 1, R = 1, pos, sum, min_sum;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; ++i){
        char c;
        int ch;
        cin >> c;
        (c == 'W') ? ch = 1 : ch = -1;
        sum += ch;
        int cur = sum-min_sum;
        if (i == 1)
            ans = ch;
        //cout << L << " " << R << " " << ans << "\n";
        if (cur > ans || (cur == ans && (i-pos > R-L+1)) ) {
            ans = cur;
            L = pos + 1;
            R = i;
            //cout << " --- " << L << " " << R << " " << ans << "\n";
        }
        if (sum < min_sum) {
            min_sum = sum;
            pos = i;
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
    cout << L << " " << R << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
