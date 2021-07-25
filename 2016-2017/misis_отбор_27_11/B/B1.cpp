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

string str;

const int MAXN = 100000+15;

VEC <int> v;
int ans, index, n=1;
char mass[MAXN];

void in()
{
    ifstream cin("input.txt");
    cin >> str;
}

void solution()
{
    for (int i = 0; i < str.SZ; i++)
    {
        //cout << i << " " << n << endl;
        char s = str[i];
        int j = i+1, ch = 1, fl = 0;
        while (ch < n)
        {
            if (str[j] != s) {fl = 1; break;}
            ch++;
            j++;
        }
        if (ch == n) {
            n++;
            i = j-1;
            v.PB(ch);
            mass[(int)v.SZ-1] = s;
        }
        else    {n = 1;i=max(0,i-2);}
    }
    for (int i = 0; i < v.SZ; i++)
    {
        int ch = v[i];
        int j = i+1;
        while (v[j] == ch+1)
        {
            ch++;
            j++;
        }
       if (ch > ans) {ans = ch; index = i;}
        j--;
    }
}

void out()
{
    ofstream cout("output.txt");
    /*for (int i = 0; i < v.SZ; i++)
    {
        cout << v[i] << " ";
    }*/
    //cout << ans << " " << index ;
    int ch = 1;
    /*for (int i = 0; i < v.SZ; i++)
    {
        cout << v[i] << " " << mass[i] << endl;
    }*/
    for (int i = index; i <= index+ans-1; i++)
    {
        for (int j = 0; j < ch; j++)
        {
          cout << mass[i];
        }
        ch++;
    }
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
