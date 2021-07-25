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

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

int n, m, k, ans1, ans2, ans3;

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> m >> k;
}

void solution()
{
    ans1 = k/(m*2)+(k%(m*2)>0);
    if ((k%(m*2)) == 0)  ans2 = m;
    else                 ans2 = (k%(m*2))/2+((k%(m*2))%2>0);
    ans3 = k%2;
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans1 << " " << ans2 << " ";
    (ans3 == 1)? cout <<"L\n" : cout <<"R\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
