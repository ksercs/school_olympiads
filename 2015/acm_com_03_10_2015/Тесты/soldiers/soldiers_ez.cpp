#include <bits/stdc++.h>
#define NAME "soldiers"
using namespace std;
int n, m, k;
char s[100000 + 10];


int main() {
    freopen(NAME".in", "r", stdin);
    freopen(NAME".out", "w", stdout);
    scanf("%d%d%d%s", &n, &m, &k, s);
    if (m == 0 || n == m) {
        printf("0\n");
        return 0;
    }
    int a = 0, b = 0, cnt = 0;
    for (int i = 0; i < k; ++i) {
        if (s[i] == 'L')
            a += 1, b -= 1;
        else if (s[i] == 'R')
            a -= 1, b += 1;
        a = (a + 4) % 4;
        b = (b + 4) % 4;
        if (a != b)++cnt;
    }
    printf("%d\n", cnt);
    return 0;
}
