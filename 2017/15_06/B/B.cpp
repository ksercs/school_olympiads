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

const int MAXN = (int)1e5 + 15;

int n, mass[MAXN];
LL ans = 1;
LL res;
map <int, int> mp;

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> mass[i];
        mp[mass[i]]++;
    }
}

void solution()
{
    sort(mass, mass+n);
    res = mass[0]*mass[1]*mass[2];
    set < PII > st;
    st.insert(MP(mp[mass[0]], mass[0]));
    st.insert(MP(mp[mass[1]], mass[1]));
    st.insert(MP(mp[mass[2]], mass[2]));
    LL ch = (*st.begin()).FF;
    if (st.SZ == 1) ans = ch*(ch-1)*(ch-2)/6;
    if (st.SZ == 3){
            ans *= (*st.begin()).FF;;
            st.erase(st.begin());
            ans *= (*st.begin()).FF;;
            st.erase(st.begin());
            ans *= (*st.begin()).FF;;
        }
    if (st.SZ == 2){
        if (mass[0] == mass[1]) ans = mp[mass[2]];
        else ans = mp[mass[2]]*(mp[mass[2]]-1)/2;
    }
}

void out()
{
    //ofstream cout("output.txt");
    cout << ans << "\n";
    /*int m[int(1e5)+15];
    for (int i = 2; i <= (int)1e5; ++i)
        for (int j = i*i; j <= (int)1e5; j += i)
            m[j] = 1;
    for (int i = 2; i <= (int)1e5; ++i)
        cout << i << "\n";*/
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
