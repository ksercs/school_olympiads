#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int main() {
    freopen("cinema.in", "r", stdin);
    freopen("cinema.out", "w", stdout);
    scanf("%d%d%d", &n, &a, &b);
    int x = n * ((a-1)*2 + 1);
    int y = n * ((b-1)*2 + 1);
    int z = x + y - (1 + (a-1)*2) * (1 + (b-1)*2);
    printf("%d\n", max(0, n*n - z - 1));
    return 0;
}