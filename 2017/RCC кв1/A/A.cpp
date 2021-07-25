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

int t;
VEC <int> ans;

void in()
{
    //ifstream cin("input.txt");
    cin >> t;
    //cout << t << "\n";
    ans.resize(t);
    for (int i = 0; i < t; ++i){
        int k, x, y;
        cin >> k >> x >> y;
        //cout << k << " " << x << " " << y << "\n";
        if (k <= max(x,y)){
            if (abs(x-y) >= 2) ans[i] = 0;
            else if (abs(x-y) == 1) ans[i] = 1;
            else    ans[i] = 2;
        }
        else{
            ans[i] = k-max(x,y);
            if (abs(x-y) == 1) ans[i] = max(1, ans[i]);
            else if (abs(x-y) == 0)    ans[i] = max(2, ans[i]);
            //cout << ans[i] << "\n";
        }
    }
}

void out()
{
    //ofstream cout("output.txt");
    for (int i = 0; i < t; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
