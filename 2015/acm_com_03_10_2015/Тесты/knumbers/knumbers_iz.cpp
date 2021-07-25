#include <vector>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("knumbers.in", "r", stdin);
    freopen("knumbers.out", "w", stdout);

    int k;
    string s;
    cin >> k >> s;   
    int n = s.length();

    vector<int> cnt(10);
    for (int i = 0; i < n; i++) cnt[s[i] - '0']++;

    int x = 0;
    for (int i = 0; i < 10; i++) x += cnt[i] != 0;
    if (x <= k) {
        cout << s << endl;
        return 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        cnt[s[i] - '0']--;
        if (s[i] == '9') continue;
        for (int d = 1; s[i] + d <= '9'; d++) {
            cnt[s[i] - '0' + d]++;
            int x = 0;
            for (int j = 0; j < 10; j++) x += cnt[j] != 0;
            if (x <= k) {
                s[i] += d;
                int mn = -1;
                for (int j = 9; j >= 0; j--) if (cnt[j]) mn = j;
                if (x < k) mn = 0;
                for (int j = i + 1; j < n; j++) s[j] = mn + '0';
                cout << s << endl;
                return 0;    
            }
            cnt[s[i] - '0' + d]--;
        }
    }

    return 0;
}