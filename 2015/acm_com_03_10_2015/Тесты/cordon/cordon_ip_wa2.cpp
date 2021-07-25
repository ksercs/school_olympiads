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
    return 0;
}
