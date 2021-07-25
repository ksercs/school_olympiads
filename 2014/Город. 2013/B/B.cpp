#include <iostream>
#include <fstream>

using namespace std;

char ans[10+2], str[100+2];
int y, i, g;

int main()
{
    ifstream cin ("B.in");
    ofstream cout ("B.out");
    cin.getline (str,102);
    y=strlen(str);
    for (i=0; i<y; i++)
        {
          if ( ('0'<=str[i]) && (str[i]<='9') )    
          {
               ans[str[i]-'0']='#'; 
          }
        }  
    for (g=0; g<=9; g++)
    {
        if (ans[g]=='#') { cout <<g;}
    } 
    cout <<"\n";
  
return 0;
}
