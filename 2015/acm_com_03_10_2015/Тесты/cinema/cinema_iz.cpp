#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    freopen("cinema.in", "r", stdin);
    freopen("cinema.out", "w", stdout);

    int n, a, b;
    while (cin >> n >> a >> b) {
        cout << max(0, ((n + 1) / 2 - a) * ((n + 1) / 2 - b) * 4 - 1) << endl;    
    }

    return 0;
}