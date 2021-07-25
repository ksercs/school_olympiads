#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 100+15;

int n, ans;
int mass[MAXN];

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> mass[i];
    }
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        if(mass[i] == 0)
        {
            int ch = 1;
            int j = i+1;
            while(mass[j] == 0 && j <= n)
            {
                ch++;
                j++;
            }
            i = j-1;
            ans = max(ans, ch);
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
