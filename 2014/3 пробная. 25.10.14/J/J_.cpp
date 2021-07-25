#include <iostream>
//#include <fstream>
#include <string>
#include <cstring>
#include <set>
//#include <conio.h>

using namespace std;

string friends, device;
int zen, zmax, p, min_zen, ans1, ch;
pair <string, string> pi1;
pair < pair <string, string>, int> pi2;
typedef pair < pair <string, string>, int> pi;
pi mass[8];
int dev[8], ans[8];
string dex[8];

int main()
{
    //ifstream cin ("J_.in");
    //ofstream cout ("J_.out");
    for (int i=0; i<6; i++)
     {
         cin >>friends >>device >>zen;
         pi1.first=friends; pi1.second=device;
         pi2.first=pi1; pi2.second=zen;
         dex[i]= device;
         mass[i]=pi2;
         //cout <<pi2.first.first <<"\n" <<pi2.first.second <<"\n" <<pi2.second <<"\n";
     }
     for (int i=0; i<6; i++)
     {
     //cout <<mass[i].first.second <<" " << dex[i] <<"\n";
       for (int j=0; j<6; j++)
         {
            if (mass[i].first.second == dex[j]){dev[i]+=1;}
         }
     }
     zmax = dev[0];
     for (int i=0; i<6; i++)
     {
       if (zmax < dev[i]) {zmax=dev[i];}
     }
     //cout <<zmax <<"\n";
     for (int i=0; i<6; i++)
     {
       if (dev[i]==zmax) {ans[p]=i; p++;}
     }
     /*for (int i=0; i<p; i++)
     {
       //cout <<dev[i] <<" ";
       cout <<ans[i] <<" ";
     }*/
     min_zen=mass[ans[0]].second;
     //cout <<min_zen <<"\n";
     for (int i=0; i<p; i++)
     {
       if (min_zen > mass[ans[i]].second) {/*cout <<"dfgfdgh" <<"\n";*/ min_zen = mass[ans[i]].second; ans1=ans[i];}
       else                               {ch+=1;} 
     }
     if (ch==p) {ans1=ans[0];}
     //cout <<min_zen <<"\n";
   //  cout <<ans1 <<"\n";
     cout <<mass[ans1].first.second <<"\n";

return 0;
}
