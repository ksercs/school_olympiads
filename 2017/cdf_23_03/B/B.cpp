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

using namespace std;

int fl, n, m;

void in()
{
    //ifstream cin("input.txt");
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        int t;
        cin >> t;
        set <int> st;
        int tmp = 0;
        for (int j = 0; j < t; ++j){
            int a;
            cin >> a;
            st.insert(a);
            if (st.count(-a)) tmp = 1;
        }
        if (!tmp) fl = 1;
    }
}


void out()
{
    //ofstream cout("output.txt");
    if (fl) cout << "YES\n";
    else    cout << "NO\n";
}

int main()
{
    in();
    out();
    return 0;
}
