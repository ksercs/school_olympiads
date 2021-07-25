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

const int COST = 100;
const string DOP = "+one";

int ans, n;

void in()
{
    //ifstream cin("Ain.txt");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str.SZ >= 4 && str.substr(str.SZ-4,4) == DOP) ans++;
    }
}

void solution()
{
    ans += n+2;
    if (ans == 13) ans++;
}

void out()
{
    //ofstream cout("Aout.txt");
    cout << ans*COST << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
