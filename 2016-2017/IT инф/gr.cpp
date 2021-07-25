#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

string str="ABBBBAAA", str2, ans;
int n = 0;

void solution()
{
    //cout << str2 << endl;
    for (n = 0; n < 1111; n++)
    {
        for (int i = 0; i < str.SZ; i++)
        {
            str2 = str2+str[i]+str[i];
        }
        int ind = 0;
        while (ind < str2.SZ)
        {
            if (str2.substr(ind, 5) == "AAAAA") {str2[ind]='B'; str2.erase(ind+1, 4);}
            else if (str2.substr(ind,5)=="BBBBB") {str2[ind]='A'; str2.erase(ind+1, 4);}
            ind++;
        }
        str = str2;
        //cout << str2 << endl;
        str2.clear();
        //system("PAUSE");
    }
}

void out()
{
    cout << str;
}

int main()
{
    solution();
    out();
    return 0;
}
