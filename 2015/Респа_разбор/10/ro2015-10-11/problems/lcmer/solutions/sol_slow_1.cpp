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

int main(){
    
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    
    cin >> n >> L >> R >> A;
    
    int ans = 0;
    
    if(n == 1) {
        for(int i = L; i <= R; i++) {
            if(i % A == 0) ans++;
        }
        cout << ans << endl;
    } else if(n == 2) {
        for(int i = L; i <= R; i++) {
            for(int j = i; j <= R; j++) {
                int cur = 1;
                while(cur % i || cur % j) cur++;
                if(cur % A == 0) ans++;
            }
        }
        cout << ans << endl;
    } else {
        cout << "TL!" << endl;
    }
    
    return 0;
}
