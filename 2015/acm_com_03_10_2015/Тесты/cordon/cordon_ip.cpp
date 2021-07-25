#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1005;
char a[N][N];

int main() {
    freopen("cordon.in", "r", stdin);
    freopen("cordon.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    if (k > n + m - 3) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = '.';
    for (int s = 1; s <= (k + 1) / 2; ++s)
        for (int i = 0; i < n; ++i)
            if (0 <= s - i && s - i < m) 
                a[i][s - i] = 'C';

    for (int s = n + m - k / 2 - 2; s < n + m - 2; ++s)
        for (int i = 0; i < n; ++i)
            if (0 <= s - i && s - i < m) 
                a[i][s - i] = 'C';
    for (int i = 0; i < n; ++i, printf("\n"))
        for (int j = 0; j < m; ++j) 
            printf("%c", a[i][j]);
    return 0;
}
