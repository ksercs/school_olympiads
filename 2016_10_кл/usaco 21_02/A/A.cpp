#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_COUNT = 1e5+15;

int n, ans, fl;

vector <int> c;

void get_ans(int ind)
{
    if (ind <= 0) return;
    //cout << ind << "\n";
    for (int i = ind-1; i >=0; i--)
    {
        if (c[i] != 0)
        {
            while(c[i]!=0)
            {
                if (c[i+1]==1) {fl = 1;break;}
                c[i]--;
                c[ind]++;
                ans+=(ind-i)*(ind-i);
                //cout << ind << " " << i << " " << (ind-i)*(ind-i) << "\n";
                //cout << c[i] << " " << c[ind] << "\n\n";
                ind--;
               // if (ind == i) break;
            }
            if (!fl)get_ans(ind);
            break;
        }
    }
}

void check()
{
  for (int i = n-1; i>=0; i--)
  {
      if (c[i]==0)
      {
         // cout << i <<"\n";
            while(c[n-1] != 0)
            {
            c.insert(c.begin(), c[n-1]);
            c.pop_back();
            }
          get_ans(n-1); fl = 0; check(); break;
      }
  }
}

void in()
{
    ifstream cin("cbarn.in");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        c.push_back(a);
    }
}

void solution()
{
  /*for (int i = 0; i < n; i++)
  {
      cout << c[i] <<"\n";
  }*/
  check();
  /*for (int i = 0; i < n; i++)
  {
      cout << c[i] << " ";
  }*/
}

void out()
{
    ofstream cout("cbarn.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
