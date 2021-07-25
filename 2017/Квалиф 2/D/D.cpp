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

const int MAXN = 115;

int n, h, vert;
string s;
VEC <string> ans;

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    cin >> s;
}

void solution()
{
    int bal = 1;
    h = 1;
    int len = 1;
    for (int i = 1; i < n; ++i){
        if (s[i] == ']' && s[i-1] == '[') len+=3;
        len++;
        if (s[i] == '[') ++bal;
        else             --bal;
        h = max(bal, h);
    }
    vert = 3+2*(h-1);
    ans.resize(vert);
    bal = vert;
    //cout << len << "\n";
    for (int i = 0; i < vert; ++i)
        ans[i].resize(len, ' ');
    ans[0][0] = '+';
    for (int i = 1; i < vert-1; ++i)
        ans[i][0] = '|';
    ans[vert-1][0] = '+';
    ans[0][len-1] = '+';
    for (int i = 1; i < vert-1; ++i)
        ans[i][len-1] = '|';
    ans[vert-1][len-1] = '+';
    int indx = 0;
    for (int i = 0; i < n-1; ++i){
        //cout << indx << " " << i  << "\n";
        if (s[i] == '['){
            int ind = (vert-bal)/2;
            if (i > 0 && s[i-1] == '['){
                ans[ind-1][indx] = '-';
                ans[ind+bal][indx] = '-';
            }
            ans[ind][indx] = '+';
            for (int j = ind+1; j < ind+bal-1; ++j)
                ans[j][indx] = '|';
            ans[ind+bal-1][indx] = '+';
            if (s[i+1] == ']'){
                ans[ind][indx+1] = '-';
                ans[ind+bal-1][indx+1] = '-';
                ans[ind][indx+3] = '-';
                ans[ind+bal-1][indx+3] = '-';
                indx += 3;
            }
            else    bal -= 2;
        }
        else{
            int ind = (vert-bal)/2;
            if (s[i+1] == ']' && s[i] == ']'){
                ans[ind-1][indx] = '-';
                ans[ind+bal][indx] = '-';
            }
            ans[ind][indx] = '+';
            for (int j = ind+1; j < ind+bal-1; ++j)
                ans[j][indx] = '|';
            ans[ind+bal-1][indx] = '+';
            if (s[i+1] == ']' && s[i] == ']') bal+=2;
        }
        /*for (int k = 0; k < vert; ++k)
            cout << ans[k] << "\n";
         cout << "\n";*/
        indx++;
    }
}

void out()
{
    //ofstream cout("output.txt");
    for (int i = 0; i < vert; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
