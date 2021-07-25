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

int mass[6][6], ans;

void in()
{
    //ifstream cin("input.txt");
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> mass[i][j];
    for (int i = 0; i < 4; ++i){
        if (!mass[i][3]) continue;
        if (mass[i][0] || mass[i][1] || mass[i][2] || mass[(i+1)%4][0] || mass[(i+2)%4][1] || mass[(i+3)%4][2])
            ans = 1;
    }
}

void out()
{
    //ofstream cout("output.txt");
    if (ans) cout << "YES\n";
    else     cout << "NO\n";
}

int main()
{
    in();
    out();
    return 0;
}
