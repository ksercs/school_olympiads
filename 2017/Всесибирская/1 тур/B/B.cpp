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
#include <queue>
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long
#define LB lower_bound

using namespace std;

int n, m;
string s;

VEC <int> num, v;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    num.resize(n-1);
    for (int i = 0; i < n-1; ++i)
        cin >> num[i];
    cin >> m;
    v.resize(m);
    for (int i = 0; i < m; ++i)
        cin >> v[i];
}

void solution()
{
    sort(num.begin(), num.end());
    for (int i = 0; i < m; ++i){
        int ind = LB(num.begin(), num.end(), v[i]) - num.begin() + 1;
        if (ind%2) s += '0';
        else       s += '1';
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << s << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
