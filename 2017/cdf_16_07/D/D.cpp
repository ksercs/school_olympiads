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
#include <climits>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

string s1, s2, ans;
VEC <char> v;

map <char, int> mp1, mp2;
set <char> st;

void in()
{
    //ifstream cin("input.txt");
    cin >> s1 >> s2;
}

void solution()
{
    for (int i = 0; i < s2.SZ; ++i){
        mp2[s2[i]]++;
        st.insert(s2[i]);
    }
    if (st.empty()) return;
    for (int i = 0; i < s1.SZ; ++i)
        if (s1[i] != '?') mp1[s1[i]]++;
    int k = INT_MAX;
    for (set <char>:: iterator it = st.begin(); it != st.end(); it++){
        char c = (*it);
        k = min(k, mp1[c]/mp2[c]);
    }
    if (k)
        for (set <char>:: iterator it = st.begin(); it != st.end(); it++){
            char c = (*it);
            mp1[c] = mp1[c] - mp2[c]*k;
        }
    for (set <char>:: iterator it = st.begin(); it != st.end(); it++){
            char c = (*it);
            if (mp2[c] > mp1[c]){
                for (int i = 0; i < mp2[c]-mp1[c]; ++i)
                    v.PB(c);
                mp1[c] = 0;
            }
            else  mp1[c] -= mp2[c];
        }
}

void out()
{
    //ofstream cout("output.txt");
    int ind = 0;
    for (int i = 0; i < s1.SZ; ++i){
        if (ind == v.SZ){
            for (set <char>:: iterator it = st.begin(); it != st.end(); it++){
                char c = (*it);
                for (int i = 0; i < mp2[c]; ++i)
                    if (mp1[c])    --mp1[c];
                    else           v.PB(c);
            }
        }
        if (s1[i] == '?'){
            //cout << "!!! " << ind << " " << v[ind] << "\n";
            cout << v[ind];
            ++ind;
        }
        else    cout << s1[i];
    }
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
