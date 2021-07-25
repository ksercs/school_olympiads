#include <iostream>
#include <fstream>

using namespace std;

const int MAX_length = 1000+5;

int length, ans;
char str[MAX_length];

void in()
{
     ifstream cin ("C.in");
     cin >>str;
}

void solution()
{
     length = strlen(str);
     for (int i=0; i<length; i++)
     {
        if ( (int(str[i])<=57) && (int(str[i])>48) && 
                        ( (int(str[i+1])>57) || (int(str[i+1])<=48) ) ) {ans++;} 
     }
}

void out()
{
     ofstream cout ("C.out");
     cout <<ans <<"\n";        
}

int main()
{
    in();
    solution();
    out();
}
