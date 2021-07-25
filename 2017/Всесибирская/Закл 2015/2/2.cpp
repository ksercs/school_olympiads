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

int n, siz, k, j;

string convert(int number, int base)
{
    vector<char> representation;
    while(number != 0)
    {
        int remainder = number % base;
        number /= base;
        if(remainder <= 9) representation.push_back(remainder + '0');
        else representation.push_back((remainder - 10) + 'A');
    }
    reverse(representation.begin(), representation.end());
    string s = "";
    for (int i = 0; i < representation.SZ; ++i)
        s += representation[i];
    //while (s.SZ != pow(2,n-1)) s = '0'+s;
    siz += s.SZ;
    return s;
}

string ans;
VEC <string> v;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    n--;
}

void solution()
{
    /*for (int i = 0; i < pow(2,n); ++i){
        string ss = convert(i,2);
        //cout << ss << "\n";
        v.PB(ss);
    }
   // cout << siz <<"\n";
    ans.resize(siz+1);
    for (int i = 0; i < v.SZ; ++i)
        for (int j = 0; j < v[i].SZ; ++j){
            //cout << (i+1) + j*pow(2, n) << "\n";
            int p = pow(2, n);
            ans[(i+1) + j*p] = v[i][j];
        }
    ans.erase(0,1);
    //cout << ans.SZ << "\n";*/
    j = k = pow(2, n);
    while (j > 0){
        for (int i = 0; i < k/j; ++i){
            for (int c = 0; c < j; ++c)
                ans += '0';
            for (int c = 0; c < j; ++c)
                ans += '1';
        }
        j /= 2;
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
