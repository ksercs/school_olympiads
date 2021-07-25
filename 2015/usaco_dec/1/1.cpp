#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

const int MAX_SIZE = 100+5;

int n, m, ans;

map < pair <int, int>, vector <pair <int, int> > > mp;

int gr[MAX_SIZE][MAX_SIZE], u[MAX_SIZE][MAX_SIZE];

int dx[]={0, 1, -1, 0},
    dy[]={1, 0, 0, -1};

void dfs(int i, int j)
{
    //cout << i << " " << j << " || "; //system("PAUSE");
    pair <int, int> p;
    u[i][j] = 1;
    p = make_pair(i, j);
    vector <pair <int,int> > vec = mp[p];
    for(int g = 0; g < vec.size(); g++)
    {
      int x = vec[g].first, y = vec[g].second;
      //cout << "<" <<x <<"," <<y <<">, ";
      gr[x][y] = 1;
      if (!u[x][y])
      {
        for (int g = 0; g < 4; g++)
          {
              int n_i = x+dx[g],n_j = y+dy[g];
              if (u[n_i][n_j]) {dfs(x, y); break;}
          }
      }
    }
    for (int g = 0; g < 4; g++)
    {
        int n_i = i+dx[g],n_j = j+dy[g];
        if (!u[n_i][n_j] && gr[n_i][n_j]) {dfs(n_i, n_j);}
    }
    //cout << "\n\n";
}

void in()
{
    ifstream cin ("lightson.in");
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        mp[make_pair(a, b)].push_back(make_pair(c, d));
    }
}

void solution()
{
  gr[1][1] = 1;
  dfs(1,1);
  for (int i = 1; i <= n; i++)
  {
      for (int j = 1; j <= n; j++)
      {
          ans += gr[i][j];
      }
  }
}

void out()
{
     ofstream cout ("lightson.out");
     cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
