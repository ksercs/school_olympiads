#include <memory.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()
 
using namespace std;
 
int main() {
    freopen("luigi.in", "r", stdin);
    freopen("luigi.out", "w", stdout);
    int a, b, c, d, k;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
    int x = b, y = d;
    int t = (b + d) % k;
    int tt = min(t, b - a);
    t -= tt;
    x -= tt;
    y -= t;
    if (y < c) {
        puts("-1");
        return 0;
    }
    printf("%d %d\n", x, y);
}