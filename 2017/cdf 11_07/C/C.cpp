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

const int MAXN = (int)1e6+15;

int n, last;
map <int, set <string> > mp;
string ans;

void in()
{
    //ifstream cin("input.txt");
    ios_base:: sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i){
        string str;
        cin >> str;
        int t;
        cin >> t;
        for (int j = 0; j < t; ++j){
            int ind;
            cin >> ind;
            mp[ind].insert(str);
            last = max(last, ind);
        }
    }
}


void out()
{
    //ofstream cout("output.txt");
    for (int i = 1; i <= last; ++i){
        if (!mp[i].empty()){
            string str = (*mp[i].rbegin());
            //cout << str << "\n";
            int Ss = (int) str.SZ;
            int As = (int) ans.SZ;
            //cout << Ss - (i+Ss-As) << " " << (i+Ss-As) << "\n";
           // cout << str.substr(Ss - (i+Ss-As), i+Ss-As) << "\n";
            if (ans.SZ < i+Ss) ans += str.substr(Ss - (i+Ss-As-1), i+Ss-As-1);
        }
        if (ans.SZ < i) ans += 'a';
    }
    cout << ans << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
