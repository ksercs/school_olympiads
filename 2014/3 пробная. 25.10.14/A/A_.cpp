#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
//#include <conio.h>

using namespace std;

char stone[100000];
int stone_count;
int zcount[26+2];

int main()
{
    ifstream cin ("A_.in");
    ofstream cout ("A_.out");

    cin >>stone;
    cin >>stone_count;

 for (int i=0; i<strlen(stone); i++)
 {
  zcount[stone[i]-'a']++;
 }
 
 /*for (int i=0; i<26; i++)
 {
  cout <<zcount[i] <<" ";
 }*/
 sort(zcount,zcount+26);
 for (int i=0; i<strlen(stone); i++)
 {
  cout <<zcount <<" ";
 }
 

return 0;
}
