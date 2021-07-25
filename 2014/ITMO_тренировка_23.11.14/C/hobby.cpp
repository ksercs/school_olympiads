#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int zcount, n, m, x, y;
pair < int, int > pi;
pair < int, int > mass[1002];
int arr[1002];
void in()
{
    ifstream cin ("hobby.in");
    cin >>zcount;
    for (int i=0; i<zcount; i++)
    {
        cin >>n >>m;
        if (m>=n) {pi.first=n; pi.second=m;}
        else      {pi.first=m; pi.second=n;}
        mass[i]=pi;
    }
}

void solution()
{ 
     sort(mass, mass+zcount);
     x=mass[0].first; y=mass[0].second;
    for (int i=1; i<zcount; i++)
    {
        for (int j=mass[i].first; j<=mass[i].second; j++)
        {
         arr[j]=1;   
        }
    }
}

void out()
{
     ofstream cout ("hobby.out");

        for (int i=1; i<zcount; i++)
        {
         if (arr[i]==0)  
        }

}

int main()
{
    in();
    solution();
    out();
return 0;
}
