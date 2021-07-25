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

string s1, s2, str, ans;
map <char, char> mp;

void in()
{
    //ifstream cin("input.txt");
    cin >> s1 >> s2 >> str;
}

void solution()
{
    ans = str;
    for (int i = 0; i < 26; ++i){
        mp[s1[i]] = s2[i];
        mp[char((int)s1[i]-32)] = char ((int)s2[i]-32);
    }
    for (int i = 0; i < str.SZ; ++i)
        if (str[i] >= 97 && str[i] <= 122 || str[i] >= 65 && str[i] <= 90) ans[i] = mp[str[i]];
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
