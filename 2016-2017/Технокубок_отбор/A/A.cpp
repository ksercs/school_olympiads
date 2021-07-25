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

using namespace std;

const string STR ="ogo", S = "go", NEWS="***";

int n, fl;
string str;

void check()
{
    fl = 0;
    for (int i = 0; i < str.SZ; i++)
    {
        if (str.substr(i, 3) == STR)
        {
            str.erase(i, 3);
            while (str.substr(i,2) == S)
            {
                str.erase(i,2);
            }
            str = str.substr(0,i) + NEWS + str.substr(i, str.SZ-i);
            fl = 1;
            break;
        }
    }
    if (fl) check();
}

void in()
{
    //ifstream cin("input.txt");
    cin >> n;
    cin >> str;
}

void solution()
{
    check();
}

void out()
{
    //ofstream cout("output.txt");
    cout << str << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
