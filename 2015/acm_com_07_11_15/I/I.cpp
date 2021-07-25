#include <iostream>
#include <fstream>

using namespace std;

string a;
int ans=0;

void in()
{
   // ifstream cin ("text.in");
    cin >> a;
}

void solution()
{
    ans=a.size();
    for (int i=0; i<1000; i++)
    {
        if (a[i]=='A') {ans=ans+1;}
        if (a[i]=='E') {ans=ans+1;}
        if (a[i]=='F') {ans=ans+1;}
        if (a[i]=='H') {ans=ans+2;}
        if (a[i]=='I') {ans=ans+2;}
        if (a[i]=='J') {ans=ans+1;}
        if (a[i]=='K') {ans=ans+2;}
        if (a[i]=='Q') {ans=ans+1;}
        if (a[i]=='R') {ans=ans+1;}
        if (a[i]=='T') {ans=ans+1;}
        if (a[i]=='X') {ans=ans+1;}
        if (a[i]=='Y') {ans=ans+1;}
    }
}

void out()
{
  //  ofstream cout ("text.out");
    cout << ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
