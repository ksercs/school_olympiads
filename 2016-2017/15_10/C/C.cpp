#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int Mx= 1000, Mx1 = 1000000;
long long n, k, a[Mx + 10], sh1, ans[Mx + 10], otvet, ans1[Mx1];

void in()
{
    //ifstream cin ("digits.in");
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
          cin >> a[i];
    }
}

void solution()
{
      int sh = 0, x = 0, ost = 0, ost2 = 0, ost3 = 0, g = 0, g1 = 0;
      sort(a, a + n) ;
      for (int i = 0; i < n; i++)
      {
            x = a[i];
            sh = 0;
            while(x > 9)
            {
                  ost = x % 10;
                  x = x / 10;
                  ost2 = 9;
                  ost3 = ost;
                  for (int j = 0; j < sh; j++)
                  {
                        ost2 *= 10;
                        ost3 *= 10;
                  }
                  sh++;
                  //cout << ans[sh1 - 1] <<"(1) ";
                  ans[sh1] = ost2 - ost3; ans1[sh1] = ans[sh1]; sh1++;
            }
            if (sh == 0) {ans[sh1] = 9 - a[i]; ans1[sh1] = ans[sh1]; sh1++; /*cout << ans[sh1 - 1] << "(2) ";*/}
            else
            {
                  g = x, g1 = 9;
                  for (int l = 0; l < sh; l++)
                  {
                        g *= 10;
                        g1 *= 10;
                  }
                  ans[sh1] = g1 - g; ans1[sh1] = ans[sh1]; sh1++;
                  //cout << ans[sh1 - 1] <<"(3) ";
            }
      }
      sort(ans1, ans1 + sh1);
      //cout <<"\n";
}

void out()
{
     //ofstream cout ("digits.out");
     for (int i = 0; i < k; i++)
     {
           otvet += ans1[sh1 - i - 1];
           //cout << ans1[sh1 - i - 1] <<" ";
           if (sh1 - i - 1 == 0) {break;}
     }
    // cout <<"\n";
     cout << otvet <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
