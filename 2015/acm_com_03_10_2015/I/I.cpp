#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, m, k, ans, nw = 1, old = 1;
string str;

void in()
{
    ifstream cin ("soldiers.in");
    cin >> n >> m;
    cin >> k;
    cin >> str;
}

void solution()
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'L') {nw++; old--;}
        if (str[i] == 'R') {nw--; old++;}
        if (str[i] == 'A')
        {
            if (nw == 1 || nw == 3) {nw = 4 - nw;}
            else
            {
                if (nw == 2) {nw = 4;}
                else {nw = 2;}
            }
            if (old == 1 || old == 3) {old = 4 - old;}
            else
            {
                if (old == 2) {old = 4;}
                else {old = 2;}
            }
        }
        if (nw == 0) {nw = 4;}
        if (nw == 5) {nw = 1;}
        if (old == 0) {old = 4;}
        if (old == 5) {old = 1;}
        if (nw != old) {ans++;}
        //cout << nw << " " << old << "\n";
    }
}

void out()
{
     ofstream cout ("soldiers.out");
     if (n == m || m == 0) {cout << "0\n";}
     else                  {cout << ans << "\n";}
}

int main()
{
    in();
    solution();
    out();
return 0;
}
