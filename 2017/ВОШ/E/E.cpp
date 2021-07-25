#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_SIZE = 500;

int n, m, sx, sy, fx, fy, p, g, f;
int used[MAX_SIZE][MAX_SIZE];
int dx[]={1, 1, -1, -1},
    dy[]={1, -1, 1, -1};

pair <int, int> pred[MAX_SIZE][MAX_SIZE];
queue <pair <int, int> > q;
vector <pair <int, int> > ans;

void get_ans(int x, int y)
{
    int px = pred[x][y].first, py = pred[x][y].second;
    ans.push_back(make_pair(x, y));
    if (pred[px][py].first) get_ans(px, py);
}

void BFS()
{
    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        if (x == fx && y == fy) break;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i]*p, ny = y + dy[i]*g;
            //cout << "1 :" << nx << " " << ny << "\n";
            if (!used[nx][ny])
            {
                //cout << x << " " << y << " -> " << nx << " " << ny << "\n";
                pred[nx][ny] = make_pair(x,y);
                used[nx][ny] = 1;
                q.push(make_pair(nx,ny));
            }
            nx = x + dx[i]*g, ny = y + dy[i]*p;
            //cout << "2 :" << nx << " " << ny << "\n";
            if (!used[nx][ny])
            {
                //cout << x << " " << y << " -> " << nx << " " << ny << "\n";
                pred[nx][ny] = make_pair(x,y);
                used[nx][ny] = 1;
                q.push(make_pair(nx,ny));
            }
        }
        q.pop();
    }
}

void in()
{
    //ifstream cin("horse.in");
    cin >> m >> n;
    cin >> g >> p;
    cin >> sy >> sx;
    cin >> fy >> fx;
}

void solution()
{
  for (int i = 0; i <= 400; i++)
  {
      for (int j = 0; j <= 400; j++)
      {
          used[i][j] = 1;
      }
  }
  f = max(p, g);
  for (int i = f; i <= n+f-1; i++)
  {
      for (int j = f; j <= m+f-1; j++)
      {
          used[i][j] = 0;
      }
  }
  if (!(sx >= 1 && sx <= n && fx >= 1 && fx <= n && sy >= 1 && sy <= m && fy >= 1 && fy <= m) ) {used[fx][fy] = 0; return;}
  sx+=f-1; fx+=f-1; sy+=f-1; fy+=f-1;
  if (sx == fx && sy == fy) {used[fx][fy] = 1;return;}
  q.push(make_pair(sx,sy));
    /*for (int i = 0; i < 10; ++i){
    for (int j = 0; j < 10; ++j)
        cout << used[i][j] << " ";
    cout << "\n";
  }
  cout << "\n";*/
  used[sx][sy] = 1;
  BFS();
  if (used[fx][fy])get_ans(fx, fy);
  /*for (int i = 0; i < 10; ++i){
    for (int j = 0; j < 10; ++j)
        cout << used[i][j] << " ";
    cout << "\n";
  }*/
}

void out()
{
    //ofstream cout("horse.out");
    if (used[fx][fy]){
        cout << ans.size() << "\n";
        cout << sy-f+1<< " " << sx-f+1 << "\n";
        for (int i = ans.size()-1; i >= 0; i--)
            cout << ans[i].second-f+1 << " " << ans[i].first-f+1 << "\n";
    }
    else cout << "-1\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
