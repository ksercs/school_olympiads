#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string str;
int ans, a, w, length;

void in()
{
    ifstream cin ("laugh.in");
    cin >> length;
    cin >> str;
}

void solution()
{
    for (int i = 0; i < length; i++)
    {
        if (str[i] == 'a' && (w == 0 || w == 1) ) {w = 2; a++;}
        else
        {
           if (str[i] == 'h' && (w == 0 || w == 2) ) {w = 1; a++;}
           else
                {
                    if (str[i] == 'a') {w = 2; ans = max(ans, a); a = 1;}
                    else
                    {
                        if (str[i] == 'h') {w = 1; ans = max(ans, a); a = 1;}
                        else {w = 0; ans = max(ans, a); a = 0;}
                    }
                }
        }
    }
    ans = max(ans, a);
}

void out()
{
     ofstream cout ("laugh.out");
     cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
