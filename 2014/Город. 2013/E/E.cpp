#include <iostream>
#include <fstream>

using namespace std;

int N, i, g, ans=0;
int a[1000], b[1000];
 
int main()
{
    ifstream cin ("E.in");
    ofstream cout ("E.out");
  cin >>N;
  for (i=1; i<=N; i++) 
    {
        cin >>a[i]; //cout <<a[i] <<" ";
    }
  //cout  <<"\n";
  for (i=1; i<=N; i++) 
    {
        cin >>b[i]; //cout <<b[i] <<" ";
    }
  for (g=1; g<=N; g++)
    {
        if (b[a[g]]==g) {ans++;}
    }
   // cout <<ans <<"\n";
 if (ans==N) {cout <<"YES\n";}
 else        {cout <<"NO\n";}
return 0;
}
