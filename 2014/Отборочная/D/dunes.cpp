#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <conio.h>

using namespace std;

const int MAXcount=1000;
int n, m;
int zbegin[MAXcount+2], zend[MAXcount+2], zpow[MAXcount+2], place[MAXcount+2];
long long hight[MAXcount+2];


int main()
{
     ifstream cin ("dunes.in");
     ofstream cout ("dunes.out");
     cin >>n >>m;
     for(int i=1; i<=n; i++)
     {
             cin >>zbegin[i] >>zend[i] >>zpow[i];
            /* for (int j=zbegin[i]; j<=zend[i]; j++)
             {
                 if (zbegin[i]%2==0)
                 {
                 if (j%2==0) {hight[j]+=zpow[i];}
                 else        {hight[j]-=zpow[i];} 
                 }
                 else
                 {
                 if (j%2==0) {hight[j]-=zpow[i];}
                 else        {hight[j]+=zpow[i];} 
                 }
                 //cout <<i <<" " <<hight[j] <<"\n"; getch();
             }*/
     }
     for (int i=1; i<=m; i++)
     {
         cin >>place[i];
        // cout <<hight[place[i]] <<"\n";
     }
     for (int i=1; i<=m; i++)
     {
         for (int j=1; j<=n; j++)
         {
             if ( (place[i]>=zbegin[j]) && (place[i]<=zend[j]) ) {if (zbegin[j]%2==0)
                 {
                 if (i%2==0) {hight[place[i]]+=zpow[j];}
                 else        {hight[place[i]]-=zpow[j];} 
                 }
                 else
                 {
                 if (i%2==0) {hight[place[i]]-=zpow[j];}
                 else        {hight[place[i]]+=zpow[j];} 
                 }}
         }
         cout <<hight[place[i]] <<"\n";
     }
return 0;
}
