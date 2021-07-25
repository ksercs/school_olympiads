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

const int INF = int(2*1e9);

int n, k, ans, delt = INF, cnt;
VEC <int> v;
string s;

void check()
{
    int ch = 0;
    cnt++;
    for (int i = 0; i < n; ++i)
        if (s[i] == '1'){
            ch += v[i];
            //cout << v[i] << " ";
        }
        else{
            ch -= v[i];
            //cout << -v[i] << " ";
        }
    //cout << "\n";
    //cout << ch << "\n";
    if (abs(k-ch) < delt || (abs(k-ch) == delt && ch < ans)){
        ans = ch;
        delt = abs(k-ch);
        //cout << s << "\n";
       // cout << ch << " END\n"; system("PAUSE");
    }
}

void DFS(int ind)
{
    if (s[1] == '1' && s[s.SZ-1] == '0') return;
    //cout << s << "\n";
    if (ind == n) check();
    else{
        s[ind] = '0';
        DFS(ind+1);
        s[ind] = '1';
        DFS(ind+1);
    }
}

void in()
{
    ifstream cin("nearest.in");
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }
}

void solution()
{
    s += '1';
    for (int i = 1; i < n; ++i)
        s += '0';
    if (n > 1) DFS(1);
    else       ans = v[0];
    //cout << cnt << "\n";
}

void out()
{
    ofstream cout("nearest.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
