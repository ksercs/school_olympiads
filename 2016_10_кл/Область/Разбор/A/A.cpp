#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

const int MAX_NUM = 3*1e5+15;

int s, f;

int ans[MAX_NUM];

void in()
{
    ifstream cin ("A.in");
    cin >> s >> f;
}

void solution()
{
    ans[s] = 0;
    for (int i = s+1; i <= f; i++)
    {
        ans[i] = INT_MAX;
    }
    for (int i = s; i <= f; i++)
    {
        ans[i+1] = min(ans[i+1], ans[i]+1);
        ans[2*i] = min(ans[2*i], ans[i]+1);
        ans[3*i] = min(ans[3*i], ans[i]+1);
    }
}

void out()
{
     ofstream cout ("A.out");
     cout << ans[f] << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
