#include <cstdio>
#include <algorithm>
#include <iostream>

int main() {
    freopen("cinema.in", "r", stdin);
    freopen("cinema.out", "w", stdout);
    int n, a, b;
    std::cin >> n >> a >> b;
    if (a > n / 2 || b > n / 2) {
        std::cout << 0 << '\n';
    } else {
        std::cout << std::max(0, 4 * (n / 2 - a + 1) * (n / 2 - b + 1) - 1) << '\n';
    }
    return 0;
}