#include <bits/stdc++.h>

void go_back(std::string &s, std::vector<int> &digit_count, int different_digits, int index) {
    int n = s.size();
    if (index == 0) {
        assert(s[index] != '9');
        s[index]++;
        for (int i = 1; i < n; i++) {
            s[i] = s[index];
        }
        std::cout << s << '\n';
        exit(0);
    }
    int digit = s[index] - '0';
    digit_count[digit]--;
    if (digit_count[digit] == 0) {
        s[index]++;
        digit_count[digit + 1]++;
        if (digit_count[digit + 1] > 1) {
            for (int i = index + 1; i < n; i++) {
                s[i] = '0';
            }
        } else {
            int minimal_digit = 10;
            for (int i = 0; i < 10; i++) {
                if (digit_count[i] > 0) {   
                    minimal_digit = i;
                    break;
                }
            }
            for (int i = index + 1; i < n; i++) {
                s[i] = minimal_digit + '0';
            }
        }
        std::cout << s << '\n';
        exit(0);
    }
    for (int need_digit = 0; need_digit < 10; need_digit++) {
        if (need_digit > digit && digit_count[need_digit] > 0) {
            s[index] = need_digit + '0';
            int minimal_digit = 10;
            for (int i = 0; i < 10; i++) {
                if (digit_count[i] > 0) {   
                    minimal_digit = i;
                    break;
                }
            }
            for (int i = index + 1; i < n; i++) {
                s[i] = minimal_digit + '0';
            }
            std::cout << s << '\n';
            exit(0);
        }
    }
    go_back(s, digit_count, different_digits, index - 1);
}

int main() {
    freopen("knumbers.in", "r", stdin);
    freopen("knumbers.out", "w", stdout);
    int k;
    std::string s;
    std::cin >> k >> s;
    int n = s.size();
    std::vector<int> digit_count(10, 0);
    int different_digits = 0;
    int minimal_digit = 10;
    for (int i = 0; i < n; i++) {
        int digit = s[i] - '0';
        if (digit_count[digit] == 0) {
            different_digits++;
        }
        digit_count[digit]++;
        if (different_digits == k + 1) {
            for (int need_digit = 0; need_digit < 10; need_digit++) {
                if (digit_count[need_digit] > 0 && need_digit > digit) {
                    s[i] = need_digit + '0';
                    for (int j = i + 1; j < n; j++) {
                        s[j] = minimal_digit + '0';
                    }
                    std::cout << s << '\n';
                    return 0;
                }
            }
            different_digits--;
            digit_count[digit]--;
            go_back(s, digit_count, different_digits, i - 1);
        }
        minimal_digit = std::min(minimal_digit, digit);
    }
    std::cout << s << '\n';
    return 0;
}