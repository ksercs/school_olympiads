#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int n, a, b, c, ans;

pair<int, int> mass[100000+15];

string answer[]={"Yes\n", "No\n"};

int main()
{
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i++)
    {
      int l, r;
      cin >> l >> r;
      mass[i] = make_pair(l,r);
    }
    sort(mass, mass+n);
    if (b != c)
    {
        for (int i = 0; i < n-1; i++)
        {
            int ch = mass[i].second - mass[i].first+1;
            if (ch > c) {ans = 1;}
            int tmp = ch;
            int h = i+1;
            while(h < n && mass[h].second <= mass[i].first+b-1)
            {
                int f = mass[h].second - mass[h].first+1;
                tmp+=f;
                h++;
            }
            if (h < n && mass[h].first <= mass[i].first+b-1) {tmp+=(mass[i].first+b-mass[h].first);}
            if (tmp > c) {ans = 1;}
        }
        int ch = mass[n-1].second - mass[n-1].first+1;
        if (ch > c) {ans = 1;}
    }
    cout << answer[ans];
    return 0;
}
