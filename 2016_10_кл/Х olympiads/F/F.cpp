#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX_COUNT = 1e5+15;

int n, m, k, s, f;

vector <pair<int,int> > gr[MAX_COUNT];
set <int> ans;
set <int>:: iterator it;
vector <int> vec;

int used[MAX_COUNT], cmp[MAX_COUNT];

void dfs(int ver)
{
    //cout << ver << "\n";
    used[ver] = 1;
    //cout << ver << ":";
    for (int i = 0; i < gr[ver].size(); i++)
    {
        pair <int,int> p = gr[ver][i];
       // cout << "<" <<p.first <<"," <<p.second << ">, ";
        if (used[p.first]==0)
        {
            if (p.first == f)
            {
                cmp[p.second]++;
                for (int g = 1; g <= k; g++)
                {
                    if (cmp[g] == 0) {ans.insert(g);}
                }
                cmp[p.second]--;
            }
            else
            {
              cmp[p.second]++;
              dfs(p.first);
              cmp[p.second]--;
              used[p.first] = 0;
            }
        }
    }
}

void in()
{
   // ifstream cin ("A.in");
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        gr[a].push_back(make_pair(b, c));
        gr[b].push_back(make_pair(a, c));
    }
    cin >> s >> f;
}

void solution()
{
  /*  for (int i = 1; i <= n; i++)
    {
        for(int g = 0; g < gr[i].size(); g++)
        {
            cout << "<" << gr[i][g].first << "," << gr[i][g].second << ">, ";
        }
        cout << "\n";
    }*/
    dfs(s);
}

void out()
{
    //ofstream cout ("A.out");
    cout << ans.size() << "\n";
    if (ans.size() != 0) {
    for(it = ans.begin(); it != ans.end(); it++)
    {
        vec.push_back(*it);
    }
    for (int i = 0; i < vec.size()-1; i++)
    {
        cout << vec[i] << " ";
    }
    cout <<vec[vec.size()-1] << "\n";}
}

int main()
{
    in();
    solution();
    out();
return 0;
}
