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

const int MAXN = (int)2*1e5+5;

int n, k;
int mass[MAXN];

void in()
{
    ifstream cin("input.txt");
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> mass[i];
}

void solution()
{
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j < n; ++j)
            if (mass[j] > mass[j+1]) swap(mass[j], mass[j+1]);
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 1; i < n; ++i)
        cout << mass[i] << " ";
    cout << mass[n] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
