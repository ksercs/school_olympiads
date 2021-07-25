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

const int MAXN = (int)1e5+2;

string str;
int ans[10], ch[10];
VEC <int> gr[10], gr1[10];

void iniz()
{
    gr[8].PB(7);
    gr[8].PB(4);
    gr[8].PB(1);
    gr[7].PB(5);
    gr[7].PB(2);
    gr[5].PB(4);
    gr[5].PB(1);
    gr[4].PB(2);
    gr[2].PB(1);
    gr1[1].PB(7);
    gr1[1].PB(4);
    gr1[2].PB(8);
    gr1[2].PB(5);
    gr1[4].PB(7);
    gr1[4].PB(1);
    gr1[5].PB(8);
    gr1[5].PB(2);
    gr1[7].PB(4);
    gr1[7].PB(1);
    gr1[8].PB(5);
    gr1[8].PB(2);
}

void dop()
{
    for (int i = 8; i >= 1; --i){
        if ( !(i%3) ) continue;
        for (int j = 0; j < gr1[i].SZ; ++j){
            int to = gr1[i][j];
            if (ch[i] >= 2 && ch[to] >= 1){
                int m = min(ch[i]/2, ch[to]);
                ans[i] += 2*m;
                ans[to] += m;
                ch[i] -= 2*m;
                ch[to] -= m;
            }
        }
    }
}

void in()
{
    ifstream cin("divisible.in");
    cin >> str;
}

void solution()
{
    iniz();
    for (int i = 0; i < str.SZ; ++i){
        int n = (int)(str[i]-'0');
        ch[n]++;
        if (!(n%3)) ans[n]++;
    }
    for (int i = 8; i >= 2; --i){
        if (!(i%3)) continue;
        for (int j = 0; j < gr[i].SZ; ++j){
            int to = gr[i][j];
            if (ch[i] <= ch[to]){
                ans[i] += ch[i];
                ans[to] += ch[i];
                ch[to] -= ch[i];
                ch[i] -= ch[i];
                break;
            }
            else{
                ans[i] += ch[to];
                ans[to] += ch[to];
                ch[to] -= ch[to];
                ch[i] -= ch[to];
            }
        }
    }
    for (int i = 8; i >= 2; --i){
        if ( !(i%3) ) continue;
        ans[i] += (ch[i]/3)*3;
    }
    dop();
}

void out()
{
    ofstream cout("divisible.out");
    for (int i = 9; i >= 0; --i)
        for (int j = 0; j < ans[i]; ++j)
            cout << i;
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
