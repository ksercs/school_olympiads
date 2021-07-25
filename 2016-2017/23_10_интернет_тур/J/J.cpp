#include <iostream>
#include <string>

#define SZ size()

using namespace std;

string s1, s2;
int ans, fl, n;

void check()
{
    for (int i = s2.SZ-1; i >= 0; i--)
    {
        if (s2[i] == s1[0])
        {
            int cnt = (int)s2.SZ-i;
            if (s1.substr(0, cnt) == s2.substr(i, cnt))
            {
                fl = 1;
                s1.erase(0, cnt);
                s2.erase(i, cnt);
                break;
            }
        }
    }
    if (s1.SZ == 0) ans = 1;
    else
    {
        if (fl)
        {
            fl = 0;
            check();
        }
        else return;
    }
}

void in()
{
    cin >> n;
    cin >> s1 >> s2;
}

void solution()
{
  if (s1.SZ == s2.SZ) check();
}

void out()
{
  if (ans) cout << "Yes\n";
  else     cout << "No\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
