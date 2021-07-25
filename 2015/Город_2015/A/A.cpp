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

int ans, ch;

string s, t;

void in()
{
  ifstream cin("A.in");
  cin >> s >> t;
}

void solution()
{
  if (t.size() > s.size()) {swap(s, t);}
  for (int i = 0; i < s.size(); i++)
  {
      int ln = 0;
      ch = 0;
      for (int g = 0; g < t.size(); g++)
      {
          if (i+ch >= s.size()) {break;}
          else
          {
             if (s[i+ch] == t[g]) {ch++; ln++; ans = max(ans,ln);}
             else                {ln =  0;ch = 0;}
          }
      }
  }
}

void out()
{
  ofstream cout("A.out");
  cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
