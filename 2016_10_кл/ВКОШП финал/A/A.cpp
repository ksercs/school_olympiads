#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN =  200000+15;

int mass[MAXN];
int n, ans1, ans2, ans;

void in()
{
    ifstream cin ("input.txt");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> mass[i];
    }
}

void solution()
{
    int st=1, fn=1, fl = 0;
    for (int i = 1; i <= n-2; i++)
    {
        if (mass[i] == mass[i+1] && mass[i] == mass[i+2])
        {
            if (i+2 == n) fl=1;
            fn = i+1;
            if (fn-st+1 > ans) {ans = fn-st+1; ans1 = st; ans2 = fn;}
            st = i+1; fn = i+1;
        }
    }
    if (!fl && n-st+1 > ans) {ans = n-st+1; ans1 = st; ans2 = n;}
}

void out()
{
     ofstream cout ("output.txt");
    cout << ans1 << " " << ans2 << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
