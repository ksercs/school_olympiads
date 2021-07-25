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

int n, m, q;
map <string, int> dsu, rank;
map <string, string> p;
set <string> st;
set <string>:: iterator it;
VEC <int> ans;

void make_set(string a)
{
 p[a]=a;
 rank[a]=1;
}

string find_set(string a)
{
 if (a==p[a]) {return a;}
 else
     {
	string res = find_set(p[a]);
	p[a]=res;
	return res;
     }
}

void union_set(string a, string b)
{
	a=find_set(a);
	b=find_set(b);
	if (rank[a]>rank[b]) {swap(a,b);}
	p[a]=b;
	if (rank[a]==rank[b]) {rank[b]++;}
}

void in()
{
    ifstream cin("D.in");
    cin >> n >> m >> q;
    string s;
    for (int i = 0; i < n; ++i)
        cin >> s;
    for (int i = 0; i < m; ++i){
        int t;
        cin >> t;
        string s1, s2;
        cin >> s1 >> s2;
        int fl1 = st.count(s1), fl2 = st.count(s2);
        if (fl1 && fl2){
            string ch1 = find_set(s1);
            string ch2 = find_set(s2);
            cout << s1 << " " << s2  << ": " << ch1 << " " << ch2 << "\n";
            if (t == 1)
                if (find_set(s1) == find_set(s2)) ans.PB(1);
                else                              ans.PB(0);
            else
                if (find_set(s1) != find_set(s2)) ans.PB(1);
                else                              ans.PB(0);
        }
        else{
            ans.PB(1);
            if (fl1){
                make_set(s2);
                if (t == 1) union_set(s1,s2);
            }
            else if (fl2){
                    make_set(s1);
                    if (t == 1) union_set(s1, s2);
                }
                else{
                    make_set(s1);
                    make_set(s2);
                    if (t == 1) union_set(s1, s2);
                }
        }
        st.insert(s1);
        st.insert(s2);
    }
    for (int i = 0; i < q; ++i){
        string s1, s2;
        cin >> s1 >> s2;
        if (!st.count(s1) || !st.count(s2)) ans.PB(3);
        else if (find_set(s1) == find_set(s2)) ans.PB(1);
             else                    ans.PB(2);
    }
    //for (it = st.begin(); it != st.end(); it++)
    //    cout << (*it) << " " << find_set(*it) << "\n";
}


void out()
{
    ofstream cout("D.out");
    for (int i = 0; i < m; ++i){
        if (ans[i]) cout << "YES\n";
        else        cout << "NO\n";
    }
    for (int i = m; i < q+m; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
