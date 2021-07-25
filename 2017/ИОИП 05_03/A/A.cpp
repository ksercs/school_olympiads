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

int n;
set <int> ans;

void in()
{
    ifstream cin("tips.in");
    ios_base:: sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        ans.insert(x+y);
    }
}

void out()
{
    ofstream cout("tips.out");
    cout << ans.SZ << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
