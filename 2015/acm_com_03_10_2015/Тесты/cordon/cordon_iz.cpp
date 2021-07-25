#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    freopen("cordon.in", "r", stdin);
    freopen("cordon.out", "w", stdout);

    int n, m, k;
    while (cin >> n >> m >> k) {
	if (k > n + m - 3) {
		cout << "NO";
		return 0;
	}
        vector<vector<char> > a(n, vector<char>(m, '.'));
        int l = 1, r = n + m - 3;
        while (k) {
            int x;
            if (k-- % 2 == 0) x = l++;
            else x = r--;

            for (int i = 0; i < n; i++) {
                int j = x - i;
                if (0 <= j && j < m) {
                    a[i][j] = 'C';
                }
            }
        }
	cout << "YES" << endl;
        for (int i = 0; i < n; i++, cout << endl) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j];
            }
        }
    }

    return 0;
}