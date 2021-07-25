#include <iostream>
#include <fstream>

using namespace std;

int a, b, c;
long long ans;

void in()
{
     ifstream cin ("D.in");
     cin >>a >>b;
}

void solution()
{
 if (a>b) {c=a; a=b; b=c;}
 for (int i=a; i<=b; i++)
 {
     if (i%2==0) {ans+=i;}
 }
}

void out()
{
     ofstream cout ("D.out");
     cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
}
