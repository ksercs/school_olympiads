#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

const int n_MAX = 1000+10,
          n_MIN = 2,
          DIR = 4;
const char answer[2][4] = {"NO", "YES"};

vector < vector <int> > gr(1010);

int direc[]={1,2,4,8},
    n;

int dx[]={-1, 1, 0, 0},
    dy[]={0, 0, 1, -1};

char ind,
     used[n_MAX * n_MAX + 1];

void DFS(int vrt)
{
    //cout << vrt << " ";
    if(!used[vrt])
    {
        used[vrt] = true;
        if( vrt == (n-1)*(n-1)) ind = true;
        else
        {
            for (int i=0; i < gr[vrt].size(); i++)
            {
                DFS(gr[vrt][i]);
            }
        }
    }
}

void in()
{
    ifstream cin("boat.in");
    cin >> n;
    for( int c = 0; c < n; c++ )
    {
        for( int v = 0; v < n; v++ )
        {
            int k;
            cin >> k;
            int ver = n*c + v;
            for(int g=DIR-1; g>=0; g--)
            {
                int new_x=c+dx[g], new_y = v+dy[g];
                if( ( k - direc[g] >= 0  ))
                {
                    k-=direc[g];
                    if ((new_x > -1 && new_x < n) && (new_y > -1 && new_y < n))
                    {
                        gr[ver].push_back(n*(new_x)+new_y);
                        /*cout << ver << " " << new_x << " " << new_y << " " << n*(new_x)+new_y << "\n";*/
                    }
                }
            }
        }
    }
}

void solution()
{
    DFS(0);
    /*for (int i = 0; i <= n*n; i++)
    {
        cout << i <<": ";
        for (int j = 0; j < gr[i].size(); j++)
        {
            cout << gr[i][j] << " ";
        }
        cout << "\n";
    }*/
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
