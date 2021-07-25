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

int n, ans = 1;
int mass[100+15];

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> mass[i];
}

void solution()
{
    int ind = 1;
    while (mass[ind+1] > mass[ind] && ind <= n)
        ++ind;
    if (ind == n+1){
        ans = 0;
        return;
    }
    while (mass[ind+1] == mass[ind] && ind <= n)
        ++ind;
    while (mass[ind+1] < mass[ind] && ind <= n)
        ++ind;
    if (ind != n+1)
        ans = 0;

}

void out()
{
    ofstream cout("output.txt");
    if (ans) cout << "YES\n";
    else     cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
