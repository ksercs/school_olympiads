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
#include <climits>
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

int a, b, answer, ch = INT_MAX;
string s1, s2;
VEC <int> ans, v;

int cmp( string str )
{
    int res = 0;
    for (int i = 0; i < s1.SZ; ++i)
        if (s1[i] != str[i]){
            ++res;
            v.PB(i+1);
        }
    return res;
}

void in()
{
    //ifstream cin("input.txt");
    cin >> a >> b;
    cin >> s1 >> s2;
}

void solution()
{
    for (int i = 0; i <= s2.SZ-s1.SZ; ++i){
        //cout << i << " = i\n";
        int nch = cmp(s2.substr(i, s1.SZ));
        if (nch < ch){
            //cout << nch << "\n";
            ch = nch;
            ans = v;
        }
        v.clear();
    }
}

void out()
{
   // ofstream cout("output.txt");
    cout << ans.SZ << "\n";
    if (!ans.empty()){
        for (int i = 0; i < ans.SZ-1; ++i)
            cout << ans[i] << " ";
        cout << ans.back() << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
