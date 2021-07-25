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

void in()
{
    ifstream cin("interesting.in");
}

void solution()
{

}

void out()
{
    ofstream cout("interesting.out");
    int ch = 0;
    for (int i = 1000; i < 10000; ++i)
        if (i%10 == (i%100)/10 || (i%1000)/100 == (i%100)/10 || (i%1000)/100 == i/1000) ch++;
    cout << ch << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
