#include <bits/stdc++.h>
#define NAME "parts"
typedef unsigned long long ull;
using namespace std;
int n;

int main() {
    freopen(NAME".in", "r", stdin);
    freopen(NAME".out", "w", stdout);
    scanf("%d", &n);
    ull a = 0;
    ull b = 0;
    for (int i = 0; i < n; ++i) {
        int a1, b1;
        scanf("%d%d", &a1, &b1);
        a += a1;
        b += b1;
    }
    int i = 63;
    int cnt = 0;
    while (i >= 0 && (a&(1LL<<i)) == (b&(1LL<<i))) {
        cnt += ((a&(1LL<<i)) > 0);
        --i;
    }
    cnt += i+1;
    printf("%d\n", cnt);
    return 0;
}
