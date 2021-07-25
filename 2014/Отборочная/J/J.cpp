#include<iostream>
#include<fstream>

using namespace std;

int v,anss,n,h,mas[200000],ans[200000];

int proschet(int c)
{
  int answ=0;
  for(int v=0;v<n;v++)
  {
    if(v+1-mas[c+v]<0){return -1;}
    answ=answ+(v+1-mas[c+v]);
  }
  return answ;
}

int minim()
{
  int m=ans[0];
  for(int c=1;c<v;c++)
  {
    if(m>ans[c]){m=ans[c];}
  }
  return m;
}

void in()
{
  ifstream cin("seq.in");
  cin >>n >>h;
  for(int c=0;c<n;c++)
  {
    cin >>mas[c];
  }
}

void solution()
{
  for(int c=0;c<n;c++)
  {
    if(mas[c]<2)
    {
      int g=proschet(c);
      if(g>=0){ans[v]=g;v++;}
    }
  }
  if(v==0){anss=-1;}
  else
  {
    anss=minim();
  }
}

void out()
{
  ofstream cout("seq.out");
  cout <<anss;
}

int main()
{
  in();
  solution();
  out();
  return 0;
}
