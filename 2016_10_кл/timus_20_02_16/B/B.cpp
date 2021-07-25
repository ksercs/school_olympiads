#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int n;

set <pair <string, long long> > ev;
set <pair <string, long long> >:: iterator it;

struct s_cmp
{
  bool operator ()(const pair <string, int> &a, const pair <string, int> &b )
  {
      for (int c = 0; c < min(a.first.size(), b.first.size()); c++)
      {
          if (a.first[c] == b.first[c]) continue;
          return (a.first[c] < b.first[c]);
      }
      return (a.first.size() < b.first.size());
  }
};

void in()
{
    ifstream cin("b.in");
    cin >> n;
    int ch = 0;
    while(ch < n)
    {
        int t;
        string s;
        long long h;
        cin >> t >> s;
        //if (s != "fire")
        //{
            cin >> h;
            if (s == "Oleg")
            {
                int st = h;
                 while (s != "fire")
                {
                    for ()
                }
            }
            else  ev.insert(make_pair(s, h));
            ch++;
       // }
    }
}

void solution()
{

}

void out()
{
    ofstream cout("b.out");
  /*for (it = ev.begin(); it != ev.end(); it ++)
  {
      cout << (*it).first << " " << (*it).second << "\n";
  }*/
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
