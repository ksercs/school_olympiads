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

int n, m, dif = 1;
string s1, s2, u, ans;
map <char, int> tim, mp;

void check ()
{
    string s;
    for (int i = 0; i < n; ++i){
        if (u[i] == '1'){
            s += s1[i];
        }
    }
    int ind = 0;
    for (int i = 0; i < s.SZ; ++i){
        if (s[i] == s2[ind]){
            ++ind;
        }
    }
    if (ind != m && s.SZ > ans.SZ){
        ans = s;
    }
}

void DFS (int ind)
{
    if (ind == n){
        check();
        return;
    }
    u[ind] = '0';
    DFS(ind+1);
    u[ind] = '1';
    DFS(ind+1);
}

void in()
{
    ifstream cin("input.txt");
    cin >> s1 >> s2;
}

void solution()
{
    n = (int)s1.SZ;
    m = (int)s2.SZ;
    for (int i = 0; i < s2.SZ; ++i){
        tim[s2[i]]++;
        if (tim[s2[i]] == 2){
            dif = 0;
        }
    }
    if (n <= 15){
        u.resize(n);
        DFS(0);
    }
    if (ans.SZ == 0 && dif){
        int mini = 55;
        for (int i = 0; i < s1.SZ; ++i){
            mp[s1[i]]++;
        }
        char c;
        for (auto item : mp){
            if (mini > item.SS){
                mini = item.SS;
                c = item.FF;
            }
        }
        for (int i = 0; i < n; ++i){
            if (s1[i] != c)
                ans += s1[i];
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
