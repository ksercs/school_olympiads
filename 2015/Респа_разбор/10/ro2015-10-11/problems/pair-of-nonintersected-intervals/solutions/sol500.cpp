#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n;
int a[100100];
map <int, int> id;
vi v;

int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    
    for(int i = 0; i < n; i++) v.pb(a[i]);
    
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    
    for(int i = 0; i < sz(v); i++) id[v[i]] = i;
    
    for(int i = 0; i < n; i++) a[i] = id[a[i]];
    
    ll ans = 0;
    for(int l1 = 0; l1 < n; l1++) {
        vi used(n, 0);
        for(int r1 = l1; r1 < n; r1++) {
            used[a[r1]] = 1;
            vi v;
            v.pb(r1);
            for(int i = r1+1; i < n; i++)
                if(used[a[i]]) v.pb(i);
            v.pb(n);
            for(int i = 1; i < sz(v); i++) {
                int sz = v[i] - v[i-1] - 1;
                ans += sz * (sz + 1) / 2;
            }
            
        }
    }
    
    cout << ans << endl;
        
    return 0;
}
