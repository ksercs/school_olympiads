#include <iostream>
#include <vector>
#include <fstream>

#define VEC vector
#define SZ size()
#define PB push_back

using namespace std;

const int MAXN = (int)1e3 + 5;

int n, m, ans;
int u[MAXN][MAXN], gr[MAXN][MAXN];

int dx[]= {0,-1, 0, 1, 0},
    dy[]= {0, 0, 1, 0, -1},
    dir[]={0, 1, 2, 4, 8};

void DFS(int x, int y)
{
    //cout << x << " " << y << endl;
    u[x][y] = 1;
    for (int c = 1; c <= 4; c++)
    {
        int nx = x+dx[c]; int ny = y+dy[c];
        if ( gr[x][y]&dir[c] && (!u[nx][ny]) ) DFS(nx, ny);
    }
}

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char s;
            cin >> s;
            if (s == 'N') {gr[i][j] |= 1;  gr[i-1][j] |= 4;}
            if (s == 'E') {gr[i][j] |= 2;  gr[i][j+1] |= 8;}
            if (s == 'S') {gr[i][j] |= 4;  gr[i+1][j] |= 1;}
            if (s == 'W') {gr[i][j] |= 8;  gr[i][j-1] |= 2;}
        }
    }
}

void solution()
{
   for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < m; j++)
       {
           if (!u[i][j]) {ans++; DFS(i, j);/* cout << endl;*/}
       }
   }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
