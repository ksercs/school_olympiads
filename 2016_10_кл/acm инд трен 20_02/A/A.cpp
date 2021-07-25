#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <stdio.h>

using namespace std;

const int MAX_SIZE = 1e6+15;

int n, ans;

int mass[MAX_SIZE];

vector <pair <int, int> > vec;

set <int> st;

void in()
{
    FILE* file_in = fopen("candies.in", "r");
    fscanf(file_in, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(file_in, "%d", &mass[i]);
    }
}

void solution()
{
    int ch=1;
    for (int i = 0; i < n-1; i++)
    {
        if (mass[i] == mass[i+1]) ch++;
        else    {vec.push_back(make_pair(ch, mass[i])); ch=1;}
    }
    if (mass[n-2] != mass[n-1]) vec.push_back(make_pair(1, mass[n-1]));
    if (mass[n-2] == mass[n-1]) vec.push_back(make_pair(ch, mass[n-1]));
    int s = 0, sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        //cout <<"vec[i]: " << vec[i].second << "\n";
        st.insert(vec[i].second);
        //cout <<"st.size(): " << st.size() << "\n";
        sum+=vec[i].first;
        if (st.size()>2) {st.clear(); ans = max(ans, sum-vec[i].first);/* cout << "\n\n";*/ sum = 0; i = i-2; s++;}
    }
    if (st.size() < 2 && ans == 0) ans = 0;
    else ans = max(ans, sum);
}

void out()
{
    FILE* file_out = fopen("candies.out", "w");
    /*for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i].first << " " << vec[i].second << "\n";
    }*/
    fprintf(file_out, "%d", ans);
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
