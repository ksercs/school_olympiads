#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX_count=1000000+5;

int mur, lov, ch, ind, zp;

//int a;

int lv[MAX_count], ans[MAX_count], m[MAX_count];

int mass[100000000]; 

/*void b_search(int y, int lb, int rb)
{
       a++;
    cout <<a <<":  " <<lb <<" " <<rb <<"\n";system("PAUSE");
    if (lb>=rb) {
                //cout <<"22222:  ";system("PAUSE"); 
                ind=lb; return;
                }
    int mid = lb+(rb-lb)/2;
    if ( m[mid]==y ) {
                   //cout <<"33333:  ";system("PAUSE"); 
                   ind=mid; return;
                   }
    if (m[mid]>y) {b_search(y, lb, mid-1);}
    if (m[mid]<y) {b_search(y, mid+1, rb );}
}*/


void in()
{
    ifstream cin ("ant.in");
    cin >>mur >>lov;
    for (int i=1; i<=mur; i++)
    {
        cin >>ch; 
        mass[ch]=1;
    }
    for (int i=1; i<=lov; i++)
    {
        cin >>lv[i];
    }
}

void solution()
{
      for (int i=1; i<=mur; i++)
    {
        if (m[i]>lv[lov]) {if (zp==0) {zp=i-1;} m[i]=-5;}
    }
 /*   for (int i=1; i<=mur; i++)
    {
        if (m[i]>lv[lov]) {if (zp==0) {zp=i-1;} m[i]=-5;}
    }
   for (int i=1; i<=lov; i++)
   {
   b_search(lv[i], 1, zp);
   ans[ind]=i; 
   m[i]=-5;
   }  */
}

void out()
{
     ofstream cout ("ant.out");
   /*  cout <<mur <<" " <<lov <<"\n";
    for (int i=1; i<=mur; i++)
    {
        cout <<m[i] <<" ";
    }
    cout <<"\n";
    for (int i=1; i<=lov; i++)
    {
        cout <<lv[i] <<" ";
    }*/
    for (int i=1; i<=mur; i++)
    {
        if (ans[i]==0) {cout <<"-1\n";} 
        else           {cout <<ans[i] <<"\n";}
    }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
