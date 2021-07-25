#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 1e5+15;

int n, m, ch, tmp;
int s[1000], ans[MAX_SIZE];

string ang, path;

vector <int> dir, dr, a;

void in()
{
    ifstream cin ("droids.in");
    cin >> n >> m;
    cin >> ang;
    cin >> path;
}

void solution()
{
    ang = '#'+ang+'#';
    for (int i = 0; i < ang.size(); i++)
    {
        if (ang[i] == 'D') dr.push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        if (dir.size() == 0) dir.push_back(path[i]-'0');
        else
        {
            if (dir[dir.size()-1] != path[i]-'0') dir.pop_back();
            else                               dir.push_back(path[i]-'0');
        }
        if (dir.size() != 0) s[dir[0]] = max(s[dir[0]], (int)dir.size());
    }
   // cout << s['L'-'0'] << " " << s['R'-'0'] << "\n";
    if (s['L'-'0']!=0)
    {
      for (int i = 0; i < ang.size(); i++)
      {
          if (ang[i] == 'D')
          {
              for (int g = max(0, i-s['L'-'0']); g <= i-1; g++)
              {
                  if (ang[g] == '#')  {ch=1;break;}
              }
              if (ch == 0) {/*cout << i <<" 1++\n";*/ans[i]++;}
              ch = 0;
          }
      }
    }
    if (s['R'-'0']!=0)
    {
      for (int i = 0; i < ang.size(); i++)
      {
         //cout <<i << " "<< s['R'-'0'] <<"\n"; system("PAUSE");
          if (ang[i] == 'D')
          {
             for (int g = i+1; g <= min((int)ang.size()-1, (i+s['R'-'0'])); g++)
              {
                  if (ang[g] == '#')  {ch=1;break;}
              }
              if (ch ==  0) {/* << i <<" 2++\n";*/ ans[i]++;}
              ch = 0;
          }
       }
    }
    if (s['R'-'0'] != 0 && s['L'-'0'] != 0) tmp = 2;
    else
    {
        if (s['R'-'0'] == 0 || s['L'-'0'] == 0) tmp = 1;
    }
    for (int i = 0; i < dr.size(); i++)
    {
       // cout << dr[i] <<": " << ans[dr[i]] << "\n";
        if (ans[dr[i]] >= tmp) a.push_back(dr[i]);
    }
}

void out()
{
     ofstream cout ("droids.out");
     cout << a.size() << "\n";
     if (a.size()!=0){
     for (int i = 0; i < a.size()-1; i++)
     {
         cout << a[i] << " ";
     }
     cout << a[a.size()-1] << "\n";}
}

int main()
{
    in();
    solution();
    out();
return 0;
}
