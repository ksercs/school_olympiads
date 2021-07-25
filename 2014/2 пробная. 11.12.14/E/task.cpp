#include<iostream>
#include<fstream>
#include<algorithm>
//#include<conio.h>

using namespace std;

long long numb[100000+3];
int  n,k,sc;//save c,save k

void in()
{
  ifstream cin("task.in");
  cin >>n >>k;
  for(long c=0;c<n;c++)
  {
    cin >>numb[c];
  }
}

void solution()
{
  sort(numb,numb+n);
  long long minim=numb[k-1]-numb[0];
  //cout <<minim <<" " <<numb[k-1] <<"-" <<numb[0] <<endl;
  for(int c=0;c<n-k;c++)
  {
    if(minim>=numb[c+k-1]-numb[c])
    {
      minim=numb[c+k-1]-numb[c];
      sc=c;
      //cout <<minim <<" " <<numb[sk]<<"-" <<numb[sc] <<endl;
    }
  }
  //getch();
}

void out()
{
  ofstream cout("task.out");
  //cout <<sc <<" " <<sk <<endl;
  
  for(int j=sc;j<sc+k-1;j++)
  {
    cout <<numb[j] <<" ";
  }
  cout <<numb[sc+k-1] <<"\n";
  
}

int main()
{
  in();
  solution();
  out();
  return 0;
}

