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

string n, ans;
int s;

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
}

string get_ans(string ss)
{
    while(ss[0] == '0')
        ss.erase(0,1);
    return ss;
}

void check(string str, int ind)
{
    if (str[ind] == '0') return;
    int sum = 0;
    for (int i = 0; i < ind; ++i)
        sum += int(str[i]-'0');
    str[ind]--;
    sum += int(str[ind]-'0');
    for (int i = ind+1; i < str.SZ; ++i){
        str[i] = '9';
        sum += 9;
    }
    if (sum >= s){
        s = sum;
        ans = get_ans(str);
    }
}

void solution()
{
    int res = 0;
    for (int i = 0; i < n.SZ-1; ++i){
        res += int(n[i]-'0');
        string str = n;
        check(str, i);
    }
    res += int(n[n.SZ-1]-'0');
    if (res >= s)
        ans = n;
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
