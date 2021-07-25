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

map <char, int> tmp1, tmp2, ans;
int n;

void in()
{
    ifstream cin("blocks.in");
    cin >> n;
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        for (int j = 0; j < str.SZ; j++)
            tmp1[str[j]]++;
        cin >> str;
        for (int j = 0; j < str.SZ; j++)
            tmp2[str[j]]++;
        for (char s = 'a'; s <= 'z'; s++)
            ans[s] += max(tmp1[s], tmp2[s]);
        tmp1.clear(); tmp2.clear();
    }
}

void out()
{
    ofstream cout("blocks.out");
    for (char s = 'a'; s <= 'z'; s++)
        cout << ans[s] << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
