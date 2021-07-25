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

using namespace std;

int n;
string str, ans;

int mass[270];

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    cin >> str;
}

void solution()
{
    for (int i = 0; i < str.SZ; i++)
    {
        mass[str[i]-'0']++;
    }
    if (mass[0] == 0 || mass['x'-'0'] == 0) return;
    ans += "0x";
    mass[0]--;
    for (int i = 'F'-'0'; i >= 'A'-'0'; i--)
    {
        while (mass[i] > 0)
        {
            ans += (char)(i+'0');
            mass[i]--;
        }
    }
    for (int i = 9; i >= 0; i--)
    {
        while (mass[i] > 0)
        {
            ans += (char)(i+'0');
            mass[i]--;
        }
    }
    if (ans[2] == '0') ans = "0x0";
}

void out()
{
    //ofstream cout("output.txt");
    if (ans.SZ < 3) cout << "No\n";
    else            cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
