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

int n, m, k;
char mass[12][12];

void in()
{
    ifstream cin("cowsignal.in");
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mass[i][j];
}


void out()
{
    ofstream cout("cowsignal.out");
    for (int i = 0; i < n; i++)
        for (int c = 0; c < k; c++)
        {
            for (int j = 0; j < m; j++)
                for (int g = 0; g < k; g++)
                    cout << mass[i][j];
            cout <<"\n";
        }
}

int main()
{
    in();
    out();
    return 0;
}
