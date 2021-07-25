#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int n, t;
long long sum;
int a[100000], b[100000];
long long ans[1000000];

void in()
{
    ifstream cin ("vase.in");
    cin >>n >>t;
    for (int i=0; i<n; i++)
    {
        cin >>a[i] >>b[i];
        sum+=a[i];
    }
    for (int i=0; i<t; i++)
    {
      for (int g=0; g<n; g++)
      {
          if (a[g]!=0) 
          {
             if ((a[g]-b[g])>=0) {ans[i]+=b[g]; a[g]-=b[g];}
             else                {ans[i]+=a[g]; a[g]=0;}
          }
      }
    }
}

void solution()
{
}

void out()
{
     ofstream cout ("vase.out");
     /*cout <<n <<" " <<t <<"\n";
    for (int i=0; i<n; i++)
    {
        cout <<a[i] <<" " <<b[i] <<"\n";
    }*/
    cout <<sum <<"\n";
    for (int i=0; i<t; i++)
    {
        cout <<sum-ans[i] <<"\n"; sum-=ans[i];
    }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
