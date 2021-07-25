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

int used[10];

int n, d;
string s, str;
VEC <int> el;
VEC <string> num;
set <string> ans;

int get_M(int st)
{
    if (st == 0) return 1%d;
    return ((get_M(--st)%d)*(10%d))%d;
}

bool proc()
{
    string ss = s;
    //cout << ss << "\n";
    LL sum = 0;
    for (int i = 0; i < ss.SZ; ++i)
    sum += (((ss[i]-'0')%d)*(get_M(ss.SZ-i-1)%d))%d;
    sum %= d;
    if (!sum) return 1;
    return 0;
}

bool check()
{
    s.clear();
    //cout << "HEY\n";
    for (int i = 0; i < n; ++i){
        //cout << num[str[i]-'0'] << "\n";
        s += num[str[i]-'0'];
        //cout << s << "\n";
    }
    //cout << s << "\n";
    //cout << s.SZ << "\n";
    //for (int i = 0; i < s.SZ; ++i)
        //ch = s[i]+ch;
        //ch += (s[i]-'0')*pow(10, s.SZ-i-1);
    //cout << s << " " << ch << "\n";
    if (proc()) return true;
    return false;
}

void dfs_R(int ind)
{
    //cout << str << "\n";
    if (ind == n && check()){
        //cout << str << "\n";
        ans.insert(s);
        //cout << str << "\n";
    }
    else
        for (int i = 1; i <= n; i++)
            if (used[i] == 0)
            {
                used[i] = 1;
                str[ind] = (i+'0');
                dfs_R(ind+1);
                used[i] = 0;
            }
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> d;
    num.resize(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> num[i];
}

void solution()
{
    for (int i = 1; i <= n; i++){
        el.push_back(i);
        str+= ' ';
    }
    dfs_R(0);
}


void out()
{
    ofstream cout("output.txt");
    cout << ans.SZ << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
