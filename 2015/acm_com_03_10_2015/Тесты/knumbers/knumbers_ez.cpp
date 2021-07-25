#include <bits/stdc++.h>
using namespace std;
char s[2000000];
int was[11];
int k;
int main() {                           
    freopen("knumbers.in", "r", stdin);
    freopen("knumbers.out", "w", stdout);
    scanf("%d", &k);
    scanf("%s", s);
    int len = strlen(s);
    int cnt = 0;
    int i = 0;
    for (; i < len; ++i) {
        if (!was[s[i] - '0'])++cnt;
        if (cnt > k)break;
        was[s[i] - '0']++;
    }
    if (cnt <= k) {
        printf("%s", s);
        return 0;
    }
    char nc = -1;
    bool zr = false;
    while (nc == -1) {
        for (int t = s[i] - '0' + 1; nc == -1 && t < 10; ++t) {
            if (was[t]||was[s[i]-'0']==1) nc = t + '0';
        }
        if (nc != -1) {
            zr = was[s[i]-'0']==1 && was[nc-'0'] > 0;
            break;
        }
        was[s[i]-'0']--;
        was[s[i]-'0'] = max(0, was[s[i]-'0']);
        i--;
    }
    was[s[i]-'0']--;
    s[i] = nc;
    was[s[i]-'0']++;
    int nc1 = -1;
    if (zr)nc1 = '0';
   
    for (int t = 0; t < 10 && nc1 == -1; ++t) {
        if (was[t] > 0) { 
            nc1 = '0'+t;
        }
    }
    
    ++i;
    for (; i < len; ++i)
        s[i] = nc1;
    printf("%s\n", s);
    return 0;
}