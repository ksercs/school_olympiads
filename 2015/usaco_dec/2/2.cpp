#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX_COUNT = 50000 + 5;

vector <pair <int, int> > vec;

int used[2*MAX_COUNT];

int n, ans, b_c, ind;

void in()
{
    ifstream cin ("highcard.in");
    cin >> n;
    for (int i = 1; i<= n; i++)
    {
        int ch;
        cin >> ch;
        vec.push_back(make_pair(ch, 1));
        used[ch] = 1;
    }
}

void solution()
{
    for (int i = 1; i <= 2*n; i++)
    {
        if (used[i] ==  0) {vec.push_back(make_pair(i, 2));}
    }
    sort(vec.begin(), vec.end());
  for (int i = 0 ;i < vec.size(); i++)
  {
      if (vec[i].second == 1) {ans++;}
      else                    {if (ans != 0) {ans--;} }
      //cout << ans << "\n";
  }
}

void out()
{
     ofstream cout ("highcard.out");
     cout << (n - ans) << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
