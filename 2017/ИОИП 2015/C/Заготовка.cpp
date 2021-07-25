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

const int MAXN = (int)1e5+5;

int n, fl, sum;
VEC <int> num;
multiset < int > ms;
set <int> st;
int ans[MAXN], cnt[MAXN];
map <int, VEC <int> > mp;
//VEC <int> v;

void get_ans(int ch)
{
    while (sum != n){
        int f = n-sum;
        multiset < int >:: iterator it = ms.lower_bound(f);
        if (it == ms.end()) it--;
        else if ( (*it) != f && it != ms.begin()){
            //cout << "HERE = " << distance(ms.begin(), it) << "\n";
            it--;
        }
        int to = (*it);
        if (to > f) break;
        //cout << "IT = " << to << " IND = " << distance(ms.begin(), it) << "\n";
        sum += (*it);
        ans[mp[to][cnt[to]]] = 1;
        cnt[to]++;
        ms.erase(it);
        if (ms.SZ == 0) return;
        /*cout << "BAL = " << bal << "\nMS : ";
        for (multiset < int >:: iterator it = ms.begin(); it != ms.end(); it++)
            cout << (*it) << " ";
        cout << "\n";*/
    }
    if (sum == n) fl = 1;
}

void in()
{
    ifstream cin("parties.in");
    cin >> n;
    num.resize(n);
    for (int i = 0; i < n; ++i){
        cin >> num[i];
        num[i]++;
        ms.insert(num[i]);
        mp[num[i]].PB(i);
        st.insert(num[i]);
    }
}

void solution()
{
    for (set <int>:: iterator it = st.begin(); it != st.end(); it++){
        //v.PB(*it);
        ms.erase(ms.find(*it));
        ans[mp[*it][cnt[*it]]] = 1;
        cnt[*it]++;
        sum = (*it);
        get_ans(*it);
        if (fl) break;
        fill(cnt+1, cnt+n+1, 0);
        fill(ans+1, ans+n+1, 0);
        ms.clear();
        for (int i = 0; i < num.SZ; ++i)
            ms.insert(num[i]);
    }
}

void out()
{
    ofstream cout("parties.out");
    if (fl){
        cout << "YES\n";
        for (int i = 0; i < n-1; ++i)
            cout << (ans[i]+2)%2+1 << " ";
        cout << (ans[n-1]+2)%2+1 << "\n";
    }
    else    cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
