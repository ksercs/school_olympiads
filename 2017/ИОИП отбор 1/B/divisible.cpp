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

int sum, fl;
int mass[10];
string str;
multiset <int> st;

void in()
{
    ifstream cin("divisible.in");
    cin >> str;
}

void solution()
{
    for (int i = 0; i < str.SZ; ++i){
        int n = (int)(str[i]-'0');
        sum += n;
        mass[n]++;
        st.insert(n);
    }
    if (sum%3 != 0){
        for (int i = 1; i <= 8; ++i){
            if (i%3 == 0) continue;
            if ((sum-i)%3 == 0 && st.count(i)) {
                st.erase(st.find(i));
                fl = 1;
                break;
            }
        }
        if (!fl){
            for (int i = 1; i <= 8; ++i){
                if (i%3 == 0) continue;
                for (int j = i; j <= 8; ++j){
                    if (j%3 == 0) continue;
                    if ((sum-i-j)%3 == 0 && st.count(i) && st.count(j)) {
                        if (i == j && mass[i] == 1) continue;
                        st.erase(st.find(i));
                        st.erase(st.find(j));
                        fl = 1;
                        break;
                    }
                }
            }
        }
    }
}

void out()
{
    ofstream cout("divisible.out");
    multiset <int>:: reverse_iterator it;
    for (it = st.rbegin(); it != st.rend(); it++)
        cout << (*it);
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
