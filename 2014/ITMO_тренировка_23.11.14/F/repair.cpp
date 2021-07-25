#include <iostream>
#include <fstream>
//#include <string>
#include <cstring>
#include <set>
//#include <conio.h>

using namespace std;

const int MAX_hight = 100000;

long long zwide, zcount, ans, zmin, ch, r;
long long zhight[MAX_hight+2];
multiset <long long> ms;
multiset <long long>::iterator it;
multiset <long long>::iterator m;
//multiset <long long>::iterator r;


void in()
{
    ifstream cin ("repair.in");
    cin >>zwide >>zcount;
    for (int i=0; i<zwide; i++)
    {
        cin >>zhight[i];
        ms.insert(zhight[i]);
    }
}

void solution()
{
    while(zcount>0)
    {
    it=ms.begin();
    ch=(*it);
    zmin=(*it);
    /*for (it=ms.begin(); it!=ms.end(); it++)
    {
        cout <<(*it) <<" ";
    }
    cout <<"\n"; getch();*/
    //cout <<ch <<"\n"; getch();
    //cout <<zmin <<"\n"; getch();

    ms.erase(ms.begin());
    /*for (it=ms.begin(); it!=ms.end(); it++)
    {
        cout <<(*it) <<" ";
    }*/
        //cout <<"\n\n"; getch();  
    it=ms.begin();
    //cout <<(*it) <<"\n"; getch();
    if ( ((*it)-ch)>zcount ) {zmin += zcount; zcount=0;}
    else                     {
                               if (((*it)-ch)!=0) {zmin += ((*it)-ch); zcount-=((*it)-ch);}
                               else  {
                                     m=ms.begin();
                                      for (it=ms.begin(); it!=ms.end(); it++)
                                      {
                                          if ((*m)==(*it)) {
                                                           r=(*it);
                                                           r+=1;
                                                           zcount-=1;
                                                           ms.erase(it);
                                                           ms.insert(r);
                                                           }
                                      }
                                      zmin += 1; zcount-=1;
                                     }
                             }
    ms.insert(zmin);
    }
    
    ans=(*(ms.begin()));
}

void out()
{
     ofstream cout ("repair.out");
     cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
