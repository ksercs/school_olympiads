#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

const char coi[2][10]={"Incorrect","Correct"},
           trueb[3]="io";
           
char s[11];

int ans;

int provka1()
{
  if((s[0]==trueb[0])&&(s[1]==trueb[1])){return 1;}
  return 0;
}

int provka2()
{
  for(int c=2;c<strlen(s);c++)
  {
    if((s[c]>='0')&&(s[c]<='9')){return 1;}
    return 0;
  }
}

void in()
{
  ifstream cin ("logins.in");
  cin >>s;
}

void solution()
{
  if((provka1()==1)&&(provka2()==1)){ans=1;}
  if(strlen(s)>10){ans=0;}
}

void out()
{
  ofstream cout ("logins.out");
  cout <<coi[ans] <<"\n";
}

int main()
{
  in();
  solution();
  out();
  return 0;
}
