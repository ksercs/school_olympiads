#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

long long a, b, c, d;
int ans, p;

void in()
{
    ifstream cin ("numbers.in");
    cin >>a >>b >>c >>d;
}

void solution()
{
     if (a+b+c==d) {ans=1; p+=1;}
     if (a*a+b*b+c*c==d) {ans=2; p+=1;}
     if (a*a*a+b*b*b+c*c*c==d) {ans=3; p+=1;}         
}

void out()
{
     ofstream cout ("numbers.out");
     if (p==1) {cout <<ans  <<"\n";}
     else      {cout <<"-1\n";}
}

int main()
{
    in();
    solution();
    out();
return 0;
}
