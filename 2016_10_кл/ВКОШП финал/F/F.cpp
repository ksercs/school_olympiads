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

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 200000+15;

int mass[MAXN];
int ans, ch, n;

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> mass[i];
    }
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        if (mass[i] > ch+(mass[i]!=0)) {ans = max(mass[i],ans); ch = mass[i];}
        else                {ans = max(ch+(mass[i]!=0), ans); ch+=(mass[i]!=0);}
    }
}

void out()
{
   // ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
