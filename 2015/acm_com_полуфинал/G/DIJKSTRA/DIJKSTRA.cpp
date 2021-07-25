#include<iostream>
#include<fstream>
#include<vector>
#include<climits>
#include<set>
#include<algorithm>

using namespace std;

const int n_MAX = 1000+10,
          n_MIN = 2,
          DIR = 4;
const char answer[2][4] = {"NO", "YES"};

vector < vector <int> > gr(1010);
int d [n_MAX*n_MAX];

int direc[]={1,2,4,8},
    n;

int dx[]={-1, 1, 0, 0},
    dy[]={0, 0, 1, -1};

char ind,
     used[n_MAX * n_MAX + 1];

set <pair <int, int> > st;

void DIJKSTRA()
{
  for (int i = 0; i < n*n; i++)
  {
      st.insert(make_pair(INT_MAX, i));
      d[i] =INT_MAX;
  }
  st.erase(make_pair(INT_MAX, 0));
  d[0] = 0;
  st.insert(make_pair(0, 0));
  while(!st.empty())
  {
      int ver = st.begin()->second;
      //cout << ver << "\n";
      for (int i = 0; i < gr[ver].size(); i++)
      {
          int f_v = gr[ver][i];
          if (d[f_v] > d[ver]+1)
          {
             st.erase(make_pair(d[f_v], f_v));
             d[f_v] = d[ver]+1;
             st.insert(make_pair(d[f_v], f_v));
          }
      }
      st.erase(make_pair(d[ver], ver));
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
    DIJKSTRA();
    /*for (int i = 0; i <= n*n; i++)
    {
        cout << d[i] <<" ";
    }
    cout << "\n";*/
    ind = (d[(n-1)*(n-1)] != INT_MAX);
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
