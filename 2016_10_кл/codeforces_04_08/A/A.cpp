#include <iostream>
//#include <fstream>

using namespace std;

//ifstream fin(".in");
//ofstream fin(".out");

int n, M, C;

void in()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b) M++;
        if (a < b) C++;
    }
}

void out()
{
    if (M > C) cout <<"Mishka\n";
    if (M < C) cout <<"Chris\n";
    if (M == C) cout <<"Friendship is magic!^^\n";
}

int main()
{
    in();
    out();
    return 0;
}
