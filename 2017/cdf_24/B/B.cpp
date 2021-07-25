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

int n, ans1, ans2;
multiset <int> m1, m2;
VEC <int> h;

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    h.resize(n);
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n; ++i)
        h[i] = (int)(s1[i]-'0');
    for (int i = 0; i < n; ++i){
        int a;
        a = (int)(s2[i]-'0');
        m1.insert(a);
        m2.insert(a);
    }
}

void solution()
{
    for (int i = 0; i < n; ++i){
        int ch = h[i];
        multiset <int>:: iterator it1, it2;
        it1 = m1.lower_bound(ch);
        if (it1 != m1.end()){
            //cout << "1 :" << (*it1) << "\n";
            //ans1++;
            m1.erase(it1);
        }
        else ans1++;
        it2 = m2.lower_bound(ch+1);
        if (it2 != m2.end()){
            //cout << "2 :" << (*it2) << "\n";
            ans2++;
            m2.erase(it2);
        }
        //else  ans2++;
    }
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans1 << "\n" << ans2 << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
