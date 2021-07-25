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

int n, k;
VEC <int> ans;

void in()
{
    ifstream cin("haircut.in");
    cin >> n >> k;
}

void solution()
{
    for (int i = k; i >= 1; --i)
        ans.PB(i);
    if (k%2){
        int ind = k/2+1;
        int ch = ans[ind];
        ans[ind] = ans[ind-1];
        ans[ind-1] = ch;
    }
    int ch = 0;
    for (int i = k+1; i <= n; ++i){
        ans.PB(ch%k+1);
        ch++;
    }
}

void out()
{
    ofstream cout("haircut.out");
    for (int i = 0; i < n-1; ++i)
        cout << ans[i] << " ";
    cout << ans[n-1] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
