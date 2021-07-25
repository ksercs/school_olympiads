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

int n, ans=-1, st;
string str;

void get_ans(string s)
{
    st++;
    if (s.SZ % 2) return;
    string s1, s2;
    s1 = s.substr(0,s.SZ/2);
    s2 = s.substr(s.SZ/2, s.SZ/2);

}

void in()
{
    ifstream cin("input.txt");
    cin >> str;
}

void solution()
{
    get_ans(str);
}

void out()
{
    ofstream cout("output.txt");
    if (ans == 1) cout << "Alice\n";
    if (ans == 2) cout << "Bob\n";
    if (ans == -1) cout << "Draw\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
