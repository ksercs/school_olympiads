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

int ob = 500, ind;
LL ans= (LL)(1e18);

void in()
{
    //ifstream cin("input.txt");
}

void solution()
{
  for (int i = 1; i <= 500; i++)
  {
      LL res = 0;
      int n = ob/i;
      int ch = n/10;
      int ost = n%10;
      res += i*(ch*(ch+1)*5 + ost*(ch+1));
      //cout << res << endl;
      res += (i-1)*25;
      if (ob%i != 0)
      {
        int zn = ob%i;
        int ch = zn/10;
        int ost = zn%10;
        res += ch*(ch+1)*5 + ost*(ch+1);
        res += 25;
      }
      //cout << res << endl; //system("PAUSE");
      if (ans > res) {ind = i; ans = res;}
  }
}

void out()
{
    //ofstream cout("output.txt");
    cout <<ind<< " "<< ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
