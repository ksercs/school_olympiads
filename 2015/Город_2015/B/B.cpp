#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>

using namespace std;

int n, ans;

vector <int> vec;

void in()
{
  ifstream cin("B.in");
  cin >> n;
  int ch;
  for (int i = 0; i < n; i++)
  {
      cin >> ch;
      vec.push_back(ch);
  }
}

void solution()
{
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n-1; i++)
  {
      if (vec[i+1] != vec[i]+1) {ans = vec[i]+1;}
  }
  if (n == 1) {ans = 1;}
  if (ans == 0)
  {
      if (vec[0]== 2) {ans = 1;}
      else  {ans = n+1;}
  }
}

void out()
{
  ofstream cout("B.out");
  cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
