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

using namespace std;

int n=6, m=3;

int gr[n+5][m+5];

void obnul()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            gr[i][j]=0;
        }
    }
}

void out()
{
    ofstream cout("output.txt");

}

int main()
{
    solution();
    out();
    return 0;
}
