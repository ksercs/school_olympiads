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
VEC <string> v, ans;

string getAns(string s1, string s2)
{
   // cout << s1 << " " << s2 << "\n";
    for (int i = 1; i < min(s1.SZ, s2.SZ); ++i)
        if (s1[i] > s2[i]) s1.erase(i, s1.SZ-i);
        else if (s1[i] < s2[i]) break;
    if (s1.SZ > s2.SZ && s1.substr(0, s2.SZ) == s2) s1.erase(s2.SZ, s1.SZ-s2.SZ);
    return s1;
}

void in()
{
    //ifstream cin("input.txt");
    ios_base:: sync_with_stdio(false);
    cin >> n;
    v.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    ans[n-1] = v[n-1];
    string str = v[n-1];
    for (int i = n-2; i >= 0; --i){
        ans[i] = getAns(v[i], str);
        str = ans[i];
    }
}

void out()
{
    //ofstream cout("output.txt");
    for (int i = 0; i < n; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
