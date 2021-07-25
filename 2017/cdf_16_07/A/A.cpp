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
string str, ans;

void in()
{
   // ifstream cin("input.txt");
    cin >> n;
    cin >> str;
}

void solution()
{
    if (str.SZ == 0) {ans = "0"; return;}
    int ind = 0;
    while (ind < n){
        int ch = 0;
        while (str[ind] == '1'){
            ++ch;
            ++ind;
        }
        ++ind;
        ans += char(ch+'0');
    }
    if (str[str.SZ-1] == '0') ans += '0';
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
