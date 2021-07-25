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

int n, need;
set <int> st, tmp;
VEC <VEC <int> > ans;

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    need = n;
    ans.resize(n+1);
    for (int i = 1; i <= n; ++i)
        st.insert(i);
    for (int i = 1; i <= n; ++i){
        int c;
        cin >> c;
        //cout << c << "\n";
        st.erase(c);
        if (c == need){
            //cout << c << "\n";
            tmp.insert(c);
            set <int>:: reverse_iterator it = tmp.rbegin();
            while (!tmp.empty() && (*it) == need){
                ans[i].PB(need);
                need --;
                tmp.erase(--tmp.end());
            }
        }
        else
            tmp.insert(c);
    }
}

void out()
{
    //ofstream cout("output.txt");
    for (int i = 1; i <= n; ++i){
        if (ans[i].SZ > 1)
            for (int j = 0; j < ans[i].SZ-1; ++j)
                cout << ans[i][j] << " ";
        if (ans[i].SZ > 0) cout << ans[i][ans[i].SZ-1];
        cout << "\n";
    }
}

int main()
{
    in();
    out();
    return 0;
}
