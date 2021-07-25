#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream cin("A.in");
    ofstream cout("A.out");
    long long sum=0, k=0, st, c;
    int n;
    cin >> n;
    n--;
    for (int i=1; i<=n/8; i++)
    {
        sum+=8*k+36+90;
        st=1;
        for (int j=1; j<=2*i+4; j++)
            st*=2;

        sum+=2*st-2;
        k=k+21+st-1;
    }
    if (!(n%8==0))
    for (int i=1; i<=n%8; i++)
    {
                 if (i==1 || i==2)
                      sum+=k+3;
                 else if (i==3 || i==4)
                      sum+=k+18;
                 else if (i==5 || i==6)
                      sum+=21+k;
                 else if (i==7)
                      {
                      sum+=21+k;
                      i=n/8+1;
                      st=1;
                      for (int j=1; j<=2*i+4; j++)
                              st*=2;
                      }             
        
    }
    cout << sum << endl;
    return 0;
}
