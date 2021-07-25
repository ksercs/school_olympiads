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

const int MAXN = (int)1e5+15;

string str, ans;
map <char, VEC <int> > mp;
int dp[MAXN];
set <char> st;

void get_ans(int ind, char s)
{
    int zn = (*st.begin());
    int mn = 0, ind;
    st.erase(zn);
    ind = mp[zn].begin();

    st.insert(zn);
}

void in()
{
    ifstream cin("input.txt");
    cin >> str;
}

void solution()
{
    for (int i = str.SZ; i >= 0; i--){
        if (u[str[i]].SZ == 0){
            dp[i]= dp[i+1]+1;
        }
        else  dp[i] = dp[i+1];
        u[str[i]].PB(i);
    }
    get_ans(0, mp.begin()->FF);
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
