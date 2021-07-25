#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
const int M = 1e5 + 10;

struct Event {
    int tp, p, q, id;

    Event(int tp, int p, int q):tp(tp), p(p), q(q) {}
    Event(int tp, int p, int q, int id):tp(tp), p(p), q(q), id(id) {}
    bool operator < (const Event& a) const {
        if (1LL * p * a.q == 1LL * a.p * q)
            return tp < a.tp;
        return 1LL * p * a.q < 1LL * a.p * q;
    }
};
vector<Event> a;
double ans[M];

int main() {
    freopen("railroad.in", "r", stdin);
    freopen("railroad.out", "w", stdout);
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) {
        int ai, bi, vi;
        scanf("%d%d%d", &ai, &bi, &vi);
        int absv = (ai < bi ? 1 : -1);
        if ((x - ai) * absv <= 0) continue;
        if ((x - bi) * absv >= 0) a.push_back(Event(0, (x - bi) * absv, vi));
        else a.push_back(Event(0, 0, 1));

        a.push_back(Event(1, (x - ai) * absv, vi));
    }
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        a.push_back(Event(2, t, 1, i));
    }
    sort(a.begin(), a.end());
    vector<int> ids;
    int balance = 0;
    for (int i = 0; i < a.size(); ++i)
        if (a[i].tp == 2) {
            if (balance == 0) ans[a[i].id] = a[i].p;
            else ids.push_back(a[i].id);
        } else if (a[i].tp == 0)
            ++balance;
        else {
            --balance;
            if (balance == 0) {
                for (int j = 0; j < ids.size(); ++j)
                    ans[ids[j]] = 1.0 * a[i].p / a[i].q;
                ids.clear();
            }
        }
    for (int i = 0; i < m; ++i)
        printf("%.9f\n",ans[i]);
    return 0;
}
