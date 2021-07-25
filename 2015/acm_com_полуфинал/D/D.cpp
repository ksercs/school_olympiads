#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

const int MAX_COUNT = 15;

int n, m;
double ans = -1;

char used[MAX_COUNT];

double d[MAX_COUNT];

pair <int, int> p[MAX_COUNT];
set <pair <int, int> >  tb;
set <pair <double, int> > st;

vector < vector < pair <int, double> > > gr(MAX_COUNT);

void dijkstra()
{
   d[1] = 0;
   st.insert(make_pair(0.0, 1));
   for (int i = 2; i <= n; i++)
   {
       d[i] = LLONG_MAX;
       st.insert(make_pair(LLONG_MAX, i));
   }
  while(!st.empty())
  {
      int ver = st.begin()->second;
      cout << ver << ": ";;
      for (int i = 0; i < gr[ver].size(); i++)
      {
          int f_v = gr[ver][i].first;
          double p = gr[ver][i].second;
          if (d[f_v] > d[ver]+p)
          {
             cout << f_v << " ";
             st.erase(make_pair(d[f_v], f_v));
             d[f_v] = d[ver]+p;
             st.insert(make_pair(d[f_v], f_v));
          }
      }
      cout << "\n";
      st.erase(make_pair(d[ver], ver));
  }
  cout << "\n";
}

void in()
{
    ifstream cin ("path.in");
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        //cout << a << " " << b << "\n";
        p[i] = make_pair(a, b);
    }
    for (int i = 0; i < m; i++)
    {
        string str;
        int a = 0, b = 0;
        cin >> str;
        int s = str.size();
        if (str[1] >='0' && str[1] <= '9') {a+=str[1]-'0'; a+= (str[0]-'0')*10;}
        else                               {a+=str[0]-'0';}
        if (str[s-2] >='0' && str[s-2] <= '9') {b+=str[s-1]-'0'; b+= (str[s-2]-'0')*10;}
        else                               {b+=(str[s-1]-'0');}
        tb.insert(make_pair(b, a));
        //cout << a << " " << b << "\n";
    }
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i!=j && tb.count(make_pair(i,j)) == 0)
            {
                int x = (p[j].first-p[i].first);
                int y = (p[j].second-p[i].second);
                double way = sqrt(x*x + y*y);
                gr[i].push_back(make_pair(j, way));
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout <<i <<": ";
        for (int j = 0; j < gr[i].size(); j++)
        {
            cout << "<" << gr[i][j].first << ", " << gr[i][j].second << ">,  ";
        }
        cout << "\n";
    }
    dijkstra();
}

void out()
{
     ofstream cout ("path.out");
     if (d[n] == LLONG_MAX) {cout << "-1\n";}
     else              {cout.precision(12); cout << d[n] << "\n";}
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
