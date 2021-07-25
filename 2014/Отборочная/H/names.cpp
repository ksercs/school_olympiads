#include<iostream>
#include<fstream>
#include<algorithm>
#include<set>

using namespace std;

string s1[1000],s2[1000],s3[1000];
int masi[1000],n;


int func(int a,int b)
{
  if(s1[a]>s2[b]){return 1;}
  return 0;
}

void in()
{
  ifstream cin("names.in");
  cin >>n;
  for(int c=0;c<n;c++)
  {
    cin >>s1[c] >>s2[c] >>s3[c];
  }
}

void solution()
{
  for(int c=0;c<n;c++)
  {
    set <int> st;
    set <int>::iterator it;
    for(int v=0;v<n;v++)
    {
      if(s1[c]==s1[v]){st.insert(c);st.insert(v);}
      if(s1[c]==s2[v]){st.insert(c);}
    }
    for(it=st.begin();it!=st.end();it++)
    {
      string dop=s1[*it];
      s1[*it]=s2[*it];
      s2[*it]=dop;
    }
  }
  for(int c=0;c<n;c++)
  {
    masi[c]=c;
  }
  sort(masi,masi+n,func);
}

void out()
{
  ofstream cout("names.out");
  for(int c=0;c<n;c++)
  {
    cout <<s1[masi[c]] <<" " <<s2[masi[c]] <<" " <<s3[masi[c]] <<"\n";
  }
}

int main()
{
  in();
  solution();
  out();
  return 0;   
}
