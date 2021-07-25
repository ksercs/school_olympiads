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

const int MAXN = (int)1e5+5;

int n, L, R, fl;
int num[MAXN], srt[MAXN];

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> num[i];
        srt[i] = num[i];
    }
}

void solution()
{
    sort(srt, srt+n);
    for (int i = 0; i < n; ++i)
        if (num[i] != srt[i]){
            L = i+1;
            break;
        }
    for (int i = L; i <= n; ++i)
        if (num[i] == srt[i] && num[i+1] == srt[i+1]){
            R = i;
            break;
        }
}

void out()
{
    ofstream cout("output.txt");
    cout << L << " " << R << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
