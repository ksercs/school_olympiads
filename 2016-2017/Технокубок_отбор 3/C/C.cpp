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

int n, ans=1, fl;
string str;

map <char, int> mp;

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    cin >> str;
}

void solution()
{
    //if (n == 1) {ans = 1; return;}
    for (int i = 0; i < n; i++){
        mp[str[i]]++;
        fl = 0;
        if (mp['L'] > 0 && mp['R'] > 0 || mp['U'] > 0 && mp['D'] > 0) {fl = 1; ans++; mp.clear(); mp[str[i]]++;}
    }
    //if (!fl) ans++;
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
