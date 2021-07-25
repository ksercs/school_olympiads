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

const int MAXCH = int(1e5)+3;

int n;
int u[MAXCH];

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
}

void solution()
{
    n++;
    if (n <= 3) cout << "1\n";
    else        cout << "2\n";
    for (LL i = 2; i <= n; ++i){
        if (!u[i]){
            u[i] = 1;
            for (LL j = i*i; j <= n; j += i)
                u[j] = 2;
        }
        if (i == n) cout << u[i] << "\n";
        else    cout << u[i] << " ";
    }
}


int main()
{
    in();
    solution();
    return 0;
}
