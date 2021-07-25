#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

string s;
int k, ans=100000, ch, L;

pair < char, int > pi;
map < char, int > mp;

void in()
{
ifstream cin("B.in");
cin >>s;
cin >>k;
}

void solution()
{
  for(int i=0; i<s.size(); i++)
  {
      mp[s[i]]++;
      if (mp[s[i]]==1) {ch++;}
      if (ch==k) {
                    //cout <<L <<"\n";
                    for(int g=L; g<=i; g++)
                    {
                        //cout <<s[g];
                        L++;
                        mp[s[g]]--;
                        if (mp[s[g]]==0) { //cout <<(i-L)  <<"\n";
                                            if (ans>(i-L+2)) {
                                                            ans=(i-L+2);
                                                            /*for(int h=L-1; h<=i; h++)
                                                            {
                                                                cout <<s[h];
                                                            }
                                                            cout <<"\n";*/
                                                           }
                                           //cout <<s[g] <<"\n";
                                            ch--; mp.erase(s[g]); break;
                                         }
                    }
                 }
  }
}

void out()
{
ofstream cout("B.out");
if (ans==100000) {cout <<"-1\n";}
else  {cout <<ans <<"\n";}
}

int main()
{
 in();
 solution();
 out();
return 0;
}
