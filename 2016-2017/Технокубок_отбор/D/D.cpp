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

const int MAXN = 2*100000 + 15;

int n, a, b, k, m, mind;
string str, S;

VEC < PII > v;
VEC <int> ans;

bool comp(PII a, PII b)
{
    if (a.FF != b.FF) return a.FF < b.FF;
    else              return a.SS > b.SS;
}

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    str = '0'+s;
}

void solution()
{
    for (int i = 0; i < b; i++) S +='0';
    for (int i = 1;  i < str.SZ; i++)
    {
        if (str[i] == '0' && str.substr(i,b) == S) {
            v.PB(MP(i,1));
            v.PB(MP(i+b-1, -1));
        }
    }
    sort(v.begin(), v.end(), comp);
    /*for (int i = 0; i < v.SZ; i++)
    {
        cout << v[i].FF << " " << v[i].SS << endl;
    }*/
    int ch = 0;
    for (int i = 0;  i < v.SZ; i++)
    {
        if (v[i].SS == 1) {
            ch++;
            if (ch > m) {m = ch; mind = v[i].FF;}
        }
        else {
            ch--;
            if (ch == 0)  {ans.PB(mind); m = 0;}
        }
    }
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans.SZ << endl;
    if (ans.SZ != 1)
    for (int i = 0; i < ans.SZ-1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[ans.SZ-1] << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
