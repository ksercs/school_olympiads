#include <iostream>
#include <fstream>

using namespace std;

int N, i, g, w, m, ans; 
int a[202];
 
int main()
{
    ifstream cin ("D.in");
    ofstream cout ("D.out");
    cin >>N;
  for (i=0; i<N; i++)
    {
        cin >> a[i];  
    }
  for (g=0; g<N; g++)
    {
            for (w=g+1; w<N; w++)
            {
                for (m=w+1; m<N; m++)
                  {
                          if (a[g]+a[w]+a[m]==0) {ans++;}
                  }
            }
    }
  for (g=N; g>0; g--)
    {
            for (w=N-1; w<0; w--)
            {
                for (m=N-1; m<0; m--)
                  {
                          if (a[g]+a[w]+a[m]==0) {ans++;}
                  }
            }
    } 
    
  if (ans>0) {cout <<"YES\n";}
  else       {cout <<"NO\n";}
return 0;
}
