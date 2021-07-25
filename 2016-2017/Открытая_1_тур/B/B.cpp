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

int n, cnt;
string str;
VEC <int> ev, ans;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    cin >> str;
}

void solution()
{
    for (int i = 0; i < str.SZ; i++)
        if (str[i] == '1'){
            ev.PB(i);
            cnt++;
        }
    ans.resize(cnt);
    for (int i = 0; i < cnt; i++)
        ans[i] = 2*(ev[min(i+n, cnt-1)]-ev[i]);
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 0; i < cnt-1; i++)
        cout << ans[i] << " ";
    cout << ans[cnt-1] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
