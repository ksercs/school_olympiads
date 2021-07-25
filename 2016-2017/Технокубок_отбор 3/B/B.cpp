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

string str1, str2;
int ans;

map <char, char> mp;
map <char, char>:: iterator it;

void in()
{
    ifstream cin("B.in");
    cin >> str1 >> str2;
}

void solution()
{
    if (str1 == str2) return;
    for (char s = 'a'; s <= 'z'; s++)
        mp[s] = s;
    for (int i = 0; i < str1.SZ; i++)
        if (str2[i] != mp[str1[i]]){
            //cout << str2[i] << " " << mp[str1[i]] << "\n";
            if (mp[str1[i]] == str1[i]) {ans++; mp[str1[i]] = str2[i]; mp[str2[i]] = str1[i];}
            else    {ans = -1; break;}
        }
}

void out()
{
    ofstream cout("B.out");
    cout << ans << "\n";
    if (ans > 0)
        for (it = mp.begin(); it != mp.end(); it++)
            if (it->FF != it->SS){
                cout << it->FF << " " << it->SS << "\n";
                mp[it->SS] = it->SS;
            }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
