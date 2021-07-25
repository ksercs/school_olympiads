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
#define LL long long

using namespace std;

string str, ans, S;
int M;

void get_ans(int ind, int cnt)
{
   // cout << ind+cnt << " " << str.SZ << endl;
    if (ind+cnt > str.SZ) {/*cout << "END\n";*/ return;}
    char s = str[ind];
    string s1="";
    int fl = 0;
    for (int i = ind+1; i < ind+cnt; i++)
    {
        if (str[i] == s) {s1 += s;}
        else {fl=1; break;}
    }
    //cout << s << " " << s1 << endl;
    if (!fl){
        S += s+s1;
        //cout << s+s1 << " " <<S << endl;
        get_ans(ind+cnt, cnt+1);
    }
    else    {
        if (S.SZ > ans.SZ) ans = S;
        S = "";
    }
}

void in()
{
    ifstream cin("input.txt");
    cin >> str;
}

void solution()
{
    M = 0;
    for (int i = 0; i < str.SZ-M; i++)
    {
      get_ans(i, 1);
      if (S.SZ > ans.SZ) ans = S;
      S="";
      M = ans.SZ;
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
