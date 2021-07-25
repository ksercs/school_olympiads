#include <iostream>
#include <fstream>

using namespace std;

const int MAX_length = 100000;

int length, ans, zmin, zmax;
int mass[MAX_length + 5];

void in()
{
     ifstream cin ("A.in");
     cin >>length;
     for (int i=0; i<length; i++)
     {
         cin >>mass[i];
     }
}

void solution()
{
     zmin = mass[0];
     zmax = mass[0];
     for (int i=1; i<length; i++)
     {
         if (zmin > mass[i]) {zmin = mass[i];}
         if (zmax < mass[i]) {zmax = mass[i];}
     }

     ans = zmax - zmin;
}

void out()
{
     ofstream cout ("A.out");
    /* cout <<length <<"\n";
     for (int i=0; i<length; i++)
     {
         cout <<mass[i] <<" ";
     }*/
     cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
}
