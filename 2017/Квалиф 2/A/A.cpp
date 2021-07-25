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
string ans;

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> k;
}

void solution()
{
    int ind = 0;
    while (n != 0){
        ans += (char)(ind+(int)'a');
        --n;
        (ind == k-1) ? ind = 0 : ++ind;
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
    solution();
    out();
    return 0;
}
