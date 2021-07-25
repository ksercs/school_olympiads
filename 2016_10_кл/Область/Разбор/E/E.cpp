#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

// –≈ÿ≈Õ» «¿ 5*10^5 + 25*10^6

int n, p, q;

vector <pair <int, int > > num;
vector <string> ans;
set <int> hlp;

void dfs(int L, int R, int res)
{

}

int binary_search_R(int zleft, int zright, int x)
{
    int mid = zleft+(zright-zleft)/2;
    //cout <<zleft <<" " <<zright <<"\n";
    if (zleft>zright) { return zleft;}
    if (num[mid].first == x) { return mid;}
    if (num[mid].first < x) { binary_search_R(mid+1, zright); }
    if (num[mid].first > x) { binary_search_R(zleft, mid-1); }
}


void in_solution()
{
    ifstream cin ("E.in");
    cin >> n >> p;
    num.resize(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (!hlp.count(a%51))
        {
            num.push_back(make_pair(i, a%51));
            hlp.insert(a&51);
        }
    }
    sort(num.begin(), num.end();
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r, ost;
        dfs(binary_search_R(0, n-1, l), binary_search_R(0, n-1, r), ost);
    }
}

void out()
{
     ofstream cout ("E.out");
}

int main()
{
    in_solution();
    out();
return 0;
}
