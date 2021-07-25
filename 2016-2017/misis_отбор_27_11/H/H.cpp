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

const int MOD = (int)1e9+7;

LL n, k, ans, M, Last, T, X;
VEC <LL> answer;

void in()
{
    ifstream cin("input.txt");
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n >> k;
        ans = 0;
        if (k >= n) answer.PB(n);
        else{
        M = ((n+k-1)/k)%MOD;
        X = (n-(1+(M-1)*k))%MOD;
        ans += X+1;
        LL ch = 2;
        cout << X << " " << M << endl;
        for (int i = 0; i <= M-2; i++)
        {
            ans += (ch*(X-i))%MOD;
            ans %= MOD;
            ch++;
        }
        answer.PB(ans);
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 0; i < answer.SZ; i++)
    {
        cout << answer[i] << "\n";
    }
}

int main()
{
    in();
    out();
    return 0;
}
