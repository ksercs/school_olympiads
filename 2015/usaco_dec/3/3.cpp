#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX_COUNT = 1e5 + 5;

int n, q, L, R;

long long sum[MAX_COUNT][5];

int main()
{
    ifstream cin ("bcount.in");
    ofstream cout ("bcount.out");
    cin >> n >> q;
    for (int i = 1; i<= n; i++)
    {
        int ch;
        cin >> ch;
        sum[i][ch%3] = sum[i-1][ch%3]+1;
        sum[i][(ch+1)%3] = sum[i-1][(ch+1)%3];
        sum[i][(ch+2)%3] = sum[i-1][(ch+2)%3];
    }
   /* for (int i = 1; i <= n; i++)
    {
        cout << sum[i][1] << " " << sum[i][2] << " " <<sum[i][3] << "\n";
    }
    cout << "\n";*/
    for (int i = 1; i<= q; i++)
    {
      cin >> L >> R;
      for (int g = 1; g < 3; g++)
      {
          cout << sum[R][g%3]-sum[L-1][g%3] << " ";
      }
      cout << sum[R][3%3]-sum[L-1][3%3];
      cout << "\n";
    }
return 0;
}
