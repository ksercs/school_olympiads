#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>


using namespace std;

int const MAX_s=15;

int R, C, ans;
char a;

int mass[MAX_s+2][MAX_s+2];

void fun(int a, int b)
{
  if (a==R-1 && b==C-1) {ans++;}
  for (int i=a+1; i<R; i++)
  {
      for(int g=b+1; g<C; g++)
      {
              if (mass[a][b]!=mass[i][g]) {fun(i, g);}
      }
  }
}

void in()
{
    ifstream cin ("hopscotch.in");
    cin >>R >>C;
    for (int i=0; i<R; i++)
    {
        for (int g=0; g<C; g++)
        {
            cin >>a; 
            if (a=='R') {mass[i][g]=1;}
            else  {mass[i][g]=2;}    
        }
    }
}

void solution()
{
 fun(0,0); 
}

void out()
{
     ofstream cout ("hopscotch.out");
    /* for (int i=0; i<3*R; i++)
     {
         for (int g=0; g<3*C; g++)
         {
             cout <<mass[i][g] <<" ";
         }
         cout <<"\n";
     }*/
     /*for (int g=0; g<R-1; g++)
         {
             cout <<dx[g] <<" ";
         }
         cout <<"\n";
     for (int g=0; g<C-1; g++)
         {
             cout <<dy[g] <<" ";
         }*/
         cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
