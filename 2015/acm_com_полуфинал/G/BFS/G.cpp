#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int MAX_SIZE = 1e4 + 10, DIR = 4;

int n, t, ch = 2;

int graph[MAX_SIZE][MAX_SIZE], used[MAX_SIZE][MAX_SIZE], direc[]={1,2,4,8};

int dx[]={-1, 1, 0, 0},
    dy[]={0, 0, 1, -1};

queue <pair <int, int> > q;

void bfs()
{
     q.push(make_pair(1, 1));
     used[1][1] = 1;
     while (!(q.empty()))
     {
           int i1 = q.front().first;
           int i2 = q.front().second;
           //cout << "<" << i1 << ", " << i2 <<">\n";
           t = graph[i1][i2];
           for(int i=DIR-1; i>=0; i--)
           {
                   int new_x = i1+dx[i];
                   int new_y = i2+dy[i];
                   if ( ( (t - direc[i]) >= 0  ) )
                              {
                                //cout << t << "\n";
                                t -= direc[i];
                                if ((graph[new_x][new_y] != -1) && (!used[new_x][new_y])){
                               // cout << "GOTO: <" << new_x << ", " << new_y << ">, DIRECT " << direc[i] << " ";
                                used[new_x][new_y] = ch;
                                q.push(make_pair(new_x, new_y));}
                              }
           }
           q.pop(); ch++; //cout <<"\n";
     }
    /*for( int c = 1; c <= n; c++ )
    {
        for( int v = 1; v <= n; v++ )
        {
            cout << used[c][v] << " ";
        }
        cout << "\n";
    }*/
}

void in()
{
    ifstream cin ("boat.in");
    cin >> n;
   // cout << n << "\n";
    for( int c = 0; c <= n+1; c++ )
    {
        for( int v = 0; v <= n+1; v++ )
        {
            graph[c][v]=-1;
        }
    }
    for( int c = 1; c <= n; c++ )
    {
        for( int v = 1; v <= n; v++ )
        {
            cin >> graph[c][v];
           // cout << graph[c][v] << " ";
        }
        //cout << "\n";
    }
}

void solution()
{
    bfs();
}

void out()
{
     ofstream cout ("boat.out");
     if (used[n][n] == 0) {cout << "NO\n";}
     else         {cout << "YES\n";}
}

int main()
{
    in();
    solution();
    out();
return 0;
}
