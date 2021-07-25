#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

int n;
LL t, s, ans;

void in()
{
    ifstream cin("beasts.in");
    cin >> t >> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        LL L, R;
        cin >> L >> R;
        if (R < L) swap(L,R);
        //cout << L << " " << R << endl;
        for (LL j = t; j <= R; j+=s)
        {
            if (j >= L && j <= R) {/*cout << j << " ";*/ ans++;}
        }
    }
}

void solution()
{

}

void out()
{
    ofstream cout("beasts.out");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
