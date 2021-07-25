#include<iostream>
#include<fstream>

using namespace std;

const int n_MAX = 1000+10,
          n_MIN = 2,
          DIR = 4;
const char answer[2][4] = {"NO", "YES"};

int mas[n_MAX][n_MAX], direc[]={1,2,4,8},
    n;

int dx[]={-1, 1, 0, 0},
    dy[]={0, 0, 1, -1};

char ind,
     used[n_MAX + 1][n_MAX + 1];

void DFS(int i, int j)
{
    if(!used[i][j])
    {
        used[i][j] = true;
        if( (i == n - 1) && ( j == n - 1 ) ) ind = true;
        else
        {
            int k = mas[i][j];
            for(int g=DIR-1; g>=0; g--)
            {
                if( ( k - direc[g] >= 0  )) {k-=direc[g]; if ((mas[i+dx[g]][j+dy[g]] != -1) &&
                        (i+dx[g] != -1) && (j+dy[g] != -1)) {DFS(i+dx[g], j+dy[g]);}}
            }
        }
    }
}

void in()
{
    ifstream cin("boat.in");
    cin >> n;
    for( int c = 0; c <= n; c++ )
    {
        for( int v = 0; v <= n; v++ )
        {
            mas[c][v]=-1;
        }
    }
    for( int c = 0; c < n; c++ )
    {
        for( int v = 0; v < n; v++ )
        {
            cin >> mas[c][v];
        }
    }
}

void solution()
{
    DFS(0, 0);
}

void out()
{
    ofstream cout("boat.out");
    cout << answer[ind] << "\n";
}


int main()
{
    in();
    solution();
    out();
    return 0;
}
