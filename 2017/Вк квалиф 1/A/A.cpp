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

int n, sum;

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        sum += a;
    }
}

void out()
{
    //ofstream cout("output.txt");
    cout << sum/n << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
