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

const int MAXN = 105;

int n;
int u[MAXN];
VEC < PII > stud;
VEC < PII > ans;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    stud.resize(n);
    for (int i = 0; i < n; ++i){
        cin >> stud[i].FF;
        stud[i].SS = i+1;
    }
}

void solution()
{
    PII p = stud[0];
    stud.erase(stud.begin());
    sort(stud.begin(), stud.end());
    stud.PB(p);
    //for (int i = 0; i < n; ++i)
    //    cout << stud[i].FF << " " << stud[i].SS << "\n";
    u[p.SS] = 1;
    for (int i = n-1; i >= 0; --i){
        if (!u[stud[i].SS]) break;
        int j = i-1;
        int cnt = stud[i].FF;
        while (j >= 0 && cnt > 0){
            if (u[stud[j].SS]){
                --j;
                continue;
            }
            cnt--;
            ans.PB(MP(stud[i].SS, stud[j].SS));
            u[stud[j].SS] = 1;
            j--;
        }
    }

}

void out()
{
    ofstream cout("output.txt");
    if (!u[stud[0].SS]) cout << "-1\n";
    else{
        cout << ans.SZ << "\n";
        for (int i = 0; i < ans.SZ; ++i)
            cout << ans[i].FF << " " << ans[i].SS << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
