#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

FILE* file;

const int MAX_SIZE = 2000+15;

int n, m, answer, ax, ay, us, fl;
char tabl[MAX_SIZE][MAX_SIZE];
int ans[MAX_SIZE][MAX_SIZE], used[MAX_SIZE][MAX_SIZE],
    dx[] = {-1, 1, 0, 0},
    dy[] = {0, 0, -1, 1};

vector <pair <int, int> > vec;
queue <pair <int,int> > q;

void BFS()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        //cout << x << " " << y << "\n"; system("PAUSE");
        used[x][y] = us;
        for (int g = 0; g < 4; g++)
        {
            int tx = x+dx[g];
            int ty = y+dy[g];
            //cout << "      " << tx << " " << ty << "\n";
            if ( (used[tx][ty] != us || ans[tx][ty] > ans[x][y]+1) && tabl[tx][ty] != '#' && tabl[tx][ty] != '*')
            {
                q.push(make_pair(tx, ty));
                used[tx][ty] = us;
                ans[tx][ty] = min(ans[tx][ty], ans[x][y]+1);
            }
        }
        q.pop();
    }
}

void in()
{
   //ifstream cin("input.txt");
   file = fopen("input.txt", "r");
   //cin >> n >> m;
   fscanf(file, "%d%d", &n, &m);
   //cout << n << " " << m << "\n";
   ios_base:: sync_with_stdio(false);
   for (int i = 0; i <= n+1; i++)
   {
       for (int j = 0; j <= m+1; j++)
       {
           tabl[i][j] = '#';
           ans[i][j] = 20000000;
       }
   }
   for (int i = 1; i <= n; i++)
   {
       char smb;
       fscanf(file, "%c", &smb);
       for (int j = 1; j <= m; j++)
       {
           //cin >> tabl[i][j];
           fscanf(file, "%c", &tabl[i][j]);
           //cout << tabl[i][j];
           if (tabl[i][j] == '*')
           {
               ans[i][j] = 0;
               vec.push_back(make_pair(i,j));
           }
       }
       //cout << smb << "\n";
   }
}

void solution()
{
    us++;
  for (int i = 0; i < vec.size(); i++)
  {
      //us++;
      int xx = vec[i].first;
      int yy = vec[i].second;
      q.push(make_pair(xx, yy));
      used[xx][yy] = us;
  }
  BFS();
}

void out()
{
    //ofstream cout("output.txt");
    file = fopen("output.txt", "w");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            fprintf(file, "%d ", ans[i][j]);
            //cout << ans[i][j] << " ";
        }
        fprintf(file, "%d\n", ans[i][m]);
        //cout << ans[i][m] << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
