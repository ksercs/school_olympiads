#include <iostream>
#include <fstream>

using namespace std;

int N, D, g, i, x1=1, x2=1, m=0;
 
int main()
{
    ifstream cin ("C.in");
    ofstream cout ("C.out");
    cin >>N >>D;
    for (i=1; i<N; i++)
    {
        x1=x1*10;
        x2=x2*10;
    }
    x2=x2*10;
  //cout <<x1 <<" " <<x2 <<"\n";
   for (g=x1; g<x2; g++)
     {
            if (g%10!=D)            { m=m+1;}  
            if ((g/10)%10!=D)       { m=m+1;} 
            if ((g/100)%10!=D)      { m=m+1;} 
            if ((g/1000)%10!=D)     { m=m+1;} 
            if ((g/10000)%10!=D)    { m=m+1;} 
            if ((g/100000)%10!=D)   { m=m+1;} 
            if ((g/10000000)%10!=D) { m=m+1;} 
         //cout <<g <<" " <<m <<"\n"; 
         if (D==0) {
                      if (m==N) {cout <<g <<"\n";}
                   }
         else      {
                      if (m==7) {cout <<g <<"\n";}
                   }
         m=0;
     }
     cout <<"\n";
return 0;
}
