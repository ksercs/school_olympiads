#include <iostream>
#include <fstream>

using namespace std;

const int MAX_length= 101 + 50;

char str[MAX_length];
long long length, sum;

void in()
{
     ifstream cin ("B.in");
     cin >>str;
}

void solution()
{
     length = strlen(str);
     for (int i=0; i<length; i++)
     {
         sum=sum+(str[i]-'0');
     }
}

void out()
{
     ofstream cout ("B.out");
     cout <<sum <<"\n";
}

int main()
{
    in();
    solution();
    out();
}
