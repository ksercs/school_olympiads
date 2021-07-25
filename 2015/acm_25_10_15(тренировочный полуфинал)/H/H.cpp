#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX_COUNT = 18+2;

int n, k, ch;
long long ans;
int cnt[MAX_COUNT];
int way[MAX_COUNT][MAX_COUNT];


void in()
{
    ifstream cin ("run.in");
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> cnt[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> way[i][j];
        }
    }
}

void solution()
{
    for (int i = 0; i < k; i++)
    {
        int s = 0;
        for (int j = 1; j <= cnt[i]; j++)
        {
          ans += way[s][j+ch];
          s = j+ch;
         // cout << ans << "\n";
        }
        ans += way[cnt[i]+ch][0];
       //cout << ans << "\n";
        ch += cnt[i];
    }
}

void out()
{
     ofstream cout ("run.out");
     cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
