#include <iostream>
#include <fstream>

using namespace std;

int n, k, m1, m2, ans;

void in()
{
    ifstream cin ("cupboard.in");
    cin >> n >> k >> m1 >> m2;
    for (int i = 1; i <= n; i++)
    {
          int h;
          cin >> h;
          int ch;
          cin >> ch;
          for (int j = 1; j <= ch; j++)
          {
                int ob;
                cin >> ob;
               int minh = ob*m2;
               int maxh = ob*m1;
               if (! (h <= maxh && h*k >= minh) ) ans++;
          }
    }
}

void out()
{
    ofstream cout ("cupboard.out");
     cout << ans << endl;
}

int main()
{
    in();
    out();
    return 0;
}
