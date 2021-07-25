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

int n, L, R, A;
vector <int> p, st;
int dp[1 << 4][10][1010];
int mask[1010];

int getmask(int a) {
    int ans = 0;
    for(int i = 0; i < sz(p); i++) {
        int k = 0;
        while(a % p[i] == 0) {
            a /= p[i];
            k++;
        }
        if(k >= st[i]) ans |= (1<<i);
    }
    return ans;
}

int calc(int mask1, int ind, int last) {
    if(ind == n) return mask1==(1<<sz(p))-1;
    int &ans = dp[mask1][ind][last];
    if(ans != -1) return ans;
    ans = 0;
    int st = max(max(1, L), last);
    for(int i = st; i <= R; i++) {
        int nmask = mask[i];
        ans = (ans + calc(mask1|nmask, ind+1, i));
        if(ans >= mod) ans -= mod;
    }
    return ans;
}

int main(){
    
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);

    
    cin >> n >> L >> R >> A;
    
    if(n > 10 || A > 1000 || L > 1000 || R > 1000) {
        cout << "TL!" << endl;
        return 0;
    }
    
    for(int i = 2; i * i <= A; i++) {
        if(A % i == 0) {
            p.pb(i);
            st.pb(0);
            while(A % i == 0) {
                A /= i;
                st.back()++;
            }
        }
    }
    if(A > 1) {
        p.pb(A);
        st.pb(1);
    }
    
    memset(dp, -1, sizeof dp);
    
    for(int i = 1; i < 1010; i++) mask[i] = getmask(i);
    
    cout << calc(0, 0, 0) << endl;
        
    return 0;
}
