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

const int MAXN = 100 + 5;

int n, answer;
int dp[MAXN];
VEC <int> ans;
VEC < VEC <string> > v;
set <string> st;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    v.resize(n+1);
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        v[i].resize(k);
        for (int j = 0; j < k; j++)
            cin >> v[i][j];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++){
        string s;
        cin >> s;
        st.insert(s);
    }
}

void solution()
{
    for (int i = 1; i  <= n; i++){
        for (int j = 0; j < v[i].SZ; j++){
            if (st.count(v[i][j])) dp[i]++;
            answer = max(answer, dp[i]);
        }
    }
    for (int i = 1; i <= n; i++)
        if (dp[i] == answer) ans.PB(i);
}

void out()
{
    ofstream cout("output.txt");
    cout << ans.SZ << " " << answer << "\n";
    for (int i = 0; i < ans.SZ-1; i++)
        cout << ans[i] << " ";
    cout << ans[ans.SZ-1] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
