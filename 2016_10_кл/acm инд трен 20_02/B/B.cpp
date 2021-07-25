#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int tab[2*100000+15];

vector <int> ans, v;

void in()
{
    ifstream cin("stairs.in");
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        vec.push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int t;
        cin >> t;
        if (t == 1) {int ind; cin >> ind; vec.erase(ind);}  //{int ind; cin >> ind; tab[ind] = 1; tab[ind+n]=1;}
        if (t == 2)
        {
            int st, fn
            cin >> st >> fn;
            if (st > fn) swap(st, fn);
        }
    }
}


void out()
{
    ofstream cout("stairs.out");
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
}

int main()
{
    in();
    out();
    return 0;
}
