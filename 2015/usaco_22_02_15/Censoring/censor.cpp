#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>


using namespace std;

const int MAX_s = 1000000;

string S, T; 

int T_length;

void fun()
{
   int ct = S.find(T,0);
   if (ct>=0 && ct<S.size()) {S.erase(ct,T_length); fun();}
   else  {return;}
}

void in()
{
    ifstream cin ("censor.in");
    getline(cin, S);
    getline(cin, T);
}

void solution()
{
     T_length=T.size(); 
     fun();
}

void out()
{
     ofstream cout ("censor.out");
     cout <<S <<"\n";
    //cout << <<"\n";
    
}

int main()
{
    in();
    solution();
    out();
return 0;
}
