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

string s1, s2;
int n;
VEC <multiset <string> > ans;
multiset <string> st;
multiset <string>:: iterator it;

void in()
{
    //ifstream cin("input.txt");
    cin >> s1 >> s2;
    st.insert(s1);
    st.insert(s2);
    cin >> n;
    ans.resize(n);
    for (int i = 0; i < n; ++i){
        string str1, str2;
        cin >> str1 >> str2;
        //cout << str1 << " " << str2 << "\n";
        st.erase(st.find(str1));
        st.insert(str2);
        ans[i] = st;
    }
}

void out()
{
    //ofstream cout("output.txt");
    cout << s1 << " " << s2 << "\n";
    for (int i = 0; i < n; ++i){
        it = ans[i].begin();
        cout <<(*it) << " ";
        it++;
        cout << (*it) << "\n";
    }
}

int main()
{
    in();
    out();
    return 0;
}
