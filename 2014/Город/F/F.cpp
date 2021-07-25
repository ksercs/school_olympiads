#include <iostream>
#include <fstream>
#include <cstring>
//#include <conio.h>

using namespace std;

const int MAX_length = 1000+5;

char str[MAX_length], obr_str[MAX_length], cpy_str[MAX_length];
int length, ans, t, f;
void in()
{
     ifstream cin ("F.in");
     cin >>str;
}

void solution()
{
     length = strlen(str);
     for (int i=0; i<length; i++)
     {
            for (int j=i+1; j<length; j++)
            {
              for (int g=i; g<=j; g++)
              {
                  if (str[g] == str[j-f]) {t++;}
                  f++;
              }
              if ( (t==j-i+1) && ((j-i+1)%2==0)) { ans++; /*cout <<i <<" " <<j <<"\n"; getch();*/}
              f=0;t=0;
            }
     }
}

void out()
{
     ofstream cout ("F.out");
     //if ( (strcmp(str, "abaabaa")==0) || (strcmp(str, "aaaa")==0)) {cout <<"4" <<"\n";}
     //cout <<str <<"\n" <<obr_str <<"\n";
     cout <<ans <<"\n";
}

int main()
{
    in();
   solution();
    out();
}
