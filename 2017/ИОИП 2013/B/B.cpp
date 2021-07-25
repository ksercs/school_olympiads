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
#include <queue>
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

int q;
LL p;
VEC <LL> ans;

LL get_S(LL num)
{
    if (num == 1LL*1) return 1LL*0;
    LL ch = 1;
    while (ch*2 < num)
        ch *= 2;
    //cout << ch << "\n";
    return ((get_S(num - ch)+1)%p);
}

void in()
{
    ifstream cin("input.txt");
    cin >> q;
    ans.resize(q);
    for (int i = 0; i < q; ++i){
        LL n;
        cin >> n >> p;
        ans[i] = get_S(n);
    }
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 0; i < q; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
