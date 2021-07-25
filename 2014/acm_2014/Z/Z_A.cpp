#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
//#include <conio.h>

using namespace std;

long long n;

long long binary_search_R(long long zleft, long long  zright)
{
    //cout <<zleft <<" " <<zright <<"\n";
    long long mid = zleft+(zright-zleft)/2;
    int answer;
    cout <<mid <<"\n"; //getch();
    cin >>answer; 
    cout.flush();
    if (answer == -1){ binary_search_R(zleft, mid-1); }
    if (answer == 1) { binary_search_R(mid+1, zright); }
}

void in()
{
    //ifstream cin ("");
    cin >>n;
}

void solution()
{
    binary_search_R(0, n); 
}

void out()
{
     //ofstream cout ("");
     //cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
