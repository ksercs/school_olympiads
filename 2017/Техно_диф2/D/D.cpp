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

int n, fl1 = 1, fl2 = 1;
VEC <string> ans1, ans2;
set <string> st1, st2;

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    ans1.resize(n);
    ans2.resize(n);
    for (int i = 0; i < n; ++i){
        string s1, s2;
        cin >> s1 >> s2;
        ans1[i] = s1.substr(0,3);
        ans2[i] = s1.substr(0,2)+s2[0];
        if (st1.count(ans1[i])) fl1 = 0;
        if (st2.count(ans2[i])) fl2 = 0;
        st1.insert(ans1[i]);
        st2.insert(ans2[i]);
    }
}

void out()
{
    //ofstream cout("output.txt");
    if (fl1){
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
            cout << ans1[i] << "\n";
    }
    else
        if (fl2){
            cout << "YES\n";
            for (int i = 0; i < n; ++i)
                cout << ans2[i] << "\n";
        }
        else    cout << "NO\n";
}

int main()
{
    in();
    out();
    return 0;
}
