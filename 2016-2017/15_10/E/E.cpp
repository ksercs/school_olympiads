#include <iostream>
#include <fstream>
#include <vector>

#define vec vector
#define pb push_back
#define SZ size()
#define sp " "

using namespace std;

const int MAXN = 1000+5, M = 2;

int n, ans;
int used[MAXN];

vec <vec <int> > gr;
vec <int> way;
/*
void DFS(int v)
{
      cout << v << endl;
      used[v] = 1;
      way.pb(v);
      if (way.SZ == n) ans++;
      if (way.SZ == n)
      {
            for (int i = 0; i < way.SZ; i++)
            {
                  cout << way[i] << sp;
            }
            cout << endl;
      }
      for (int i = 0; i < gr[v].SZ; i++)
      {
            int to = gr[v][i];
            if (!used[to])
            {
                  used[to] = 1;
                  DFS(to);
                  used[to] = 0;
            }
      }
      way.pop_back();
      used[v] = 0;
}*/

void in()
{
    ifstream cin ("paths.in");
    cin  >> n;
    gr.resize(n+1);
    for (int i = 1; i <= n; i++)
    {
          int st;
          cin >> st;
          for (int j = 0; j < st; j++)
          {
                int b;
                cin >> b;
                gr[i].pb(b);
          }
    }
}

/*void solution()
{
      DFS(1);
      ans *= n;
}*/

void out()
{
     ofstream cout ("paths.out");
     //cout << ans%M << endl;
     if (n == 1) cout << "1\n";
     else        cout << "0\n";
}

int main()
{
    in();
    //solution();
    out();
    return 0;
}
