#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>


using namespace std;

int n, x, a, ch, num, m, ans;

vector <int> q;
vector <int> v;

void in()
{
    ifstream cin ("longqueue.in");
    cin >>n >>x;
    for (int i=0; i<n; i++)
    {
        cin >>a; q.push_back(a);
    }
    cin >>m;
    for(int i=0; i<m; i++)
    {
        cin >>ch;
        if (ch==1) {cin >>num; q.push_back(num);}
        if (ch==2) {q.erase(q.begin());}
        if (ch==3) {
                    cin >>num;
                    for(int c=0; c<num; c++)
                    {
                        if (q[c]>=x) {ans++;}
                    }
                   // cout <<ans <<"\n";
                    v.push_back(ans);
                    ans=0;
                   }
    }
}

void solution()
{
}

void out()
{
     ofstream cout ("longqueue.out");
     for (int i=0; i<v.size(); i++)
     {
         cout <<v[i] <<"\n";
     }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
