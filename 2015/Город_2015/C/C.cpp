#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>

using namespace std;

int L, R, ans;

set <int> st;

void in()
{
  ifstream cin("C.in");
  cin >> L >>R;
}

void solution()
{
  for (int i = L; i <= R; i++)
  {
      int ch = i, h = 0;
      //cout << ch << "\n";
      while(ch > 0)
      {
          st.insert(ch%10);
          ch/=10;
          //cout << ch << " ";
          h++;
      }
      // cout<< h << "\n";
      if (h == st.size()) {ans++;}
      st.clear();
  }
}

void out()
{
  ofstream cout ("C.out");
  cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
