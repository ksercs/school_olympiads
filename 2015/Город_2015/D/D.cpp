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


int n, x;
string two_ch;

int f(int  ch, int  pos, long long  lg)
{
    //cout << ch << " " << pos << " " <<lg << "\n"; system("PAUSE");
    //if (lg == 1) {return 1;}
    if (pos == lg/2+1) {return ch;}
    if (pos < lg/2+1) {return f(ch-1, pos, lg/2);}
    if (pos > lg/2+1) {return f(ch-1, pos-(lg/2+1), lg/2);}

}

void in()
{
  ifstream cin("D.in");
  cin >> n >> x;
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        ln*=2;
    }
    ln--;
}

void out()
{
  ofstream cout("D.out");
  cout << f(n, x, ln) << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}

