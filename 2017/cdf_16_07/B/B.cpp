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

int fl;
char mass[15][15];

void in()
{
    //ifstream cin("input.txt");
    for (int i = 1; i <= 10; ++i)
        for (int j = 1; j <= 10; ++j)
            cin >> mass[i][j];
}

void solution()
{
    for (int k = 1; k <= 10; ++k){
        for (int i = 1; i <= 6; ++i){
            int x1 = 0, p1 = 0, x2 = 0, p2 = 0;
            for (int j = i; j < i+5; ++j){
                //cout << mass[i][j] << " ";
                if (mass[k][j] == 'X') ++x1;
                if (mass[k][j] == '.') ++p1;
                if (mass[j][k] == 'X') ++x2;
                if (mass[j][k] == '.') ++p2;
            }
            if (x1 == 4 && p1 == 1 || x2 == 4 && p2 == 1){
                fl = 1;
                return;
            }
        }
    }
    for (int k = 1; k <= 6; ++k){
        for (int i = 1; i <= 6; ++i){
            int x1 = 0, p1 = 0, x2 = 0, p2 = 0;
            for (int j = 0; j < 5; ++j){
                //cout << mass[i][j] << " ";
                if (mass[k+j][i+j] == 'X') ++x1;
                if (mass[k+j][i+j] == '.') ++p1;
                if (mass[10-k+1-j][i+j] == 'X') ++x2;
                if (mass[10-k+1-j][i+j] == '.') ++p2;
            }
            if (x1 == 4 && p1 == 1 || x2 == 4 && p2 == 1){
                fl = 1;
                return;
            }
        }
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
    solution();
    out();
    return 0;
}
