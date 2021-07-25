#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <string>
#include <set>
#include <map>

using namespace std;


int n;
string x, ln = "1";

string mass[1000 + 15];

void mn(string s1, int p, int c)
{
    if (p == 0 && s1[p] == 1) {s1.erase(0, 1);}
    else
    {
        int z = s1[p] - '0';\
        z--;
        if (z != -1) {s1[p] = z+'0';}
        else         {s1[p] = '9'; mn(s1, p-1, 1);}
    }
}

void dl_mn(string s1, string s2)
{
    int ind = s1.size()-1;
    for (int i = s2.size()-1; i >=0; i--)
    {
        mn(s1, ind, s2[i]-'0');
        ind--;
    }
}

void pl(string s, int pos, int num)
{
    if (pos == -1) {s = "1"+s;}
    else{
    int z = s[pos]-'0';
    z += num;
    if (z < 10) {s[pos] = z+'0';}
    else        {s[pos] = z%10 +'0'; pl(s, pos-1, 1);}}
}

void ymn(string str, int ch)
{
    int z = str[str.size()-1]-'0';
    z*=ch;
    if (z > 10) {str[str.size()-1] = z%10+'0'; pl(str, str.size()-2, 1);}
    else        {str[str.size()-1] = z+'0';}
}

int f(int  ch, string  pos, int ind)
{
    //cout << ch << " " << pos << " " <<lg << "\n"; system("PAUSE");
    //if (lg == 1) {return 1;}
    pl(mass[ind-1], mass[ind-1].size()-1, 1);
    if (pos == mass[ind-1]) {return ch;}
    if (pos < mass[ind-1]) {return f(ch-1, pos, ind--);}
    if (pos > mass[ind-1]) {dl_mn(pos, mass[ind-1]); return f(ch-1, pos, ind--);}

}

void in()
{
  ifstream cin("D1.in");
  cin >> n >> x;
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        ymn(ln, 2);
        mass[i] = ln;
    }
    mn(ln, ln.size()-1, 1);
}

void out()
{
  ofstream cout("D1.out");
  cout << f(n, x, n) << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}

