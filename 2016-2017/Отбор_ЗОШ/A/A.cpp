#include <iostream>
#include <fstream>

using namespace std;

int a, b, sum;

void in()
{
    ifstream cin("input.txt");
    cin >> a >> b;
}

void solution()
{
    sum = a+b;
}

void out()
{
    ofstream cout("output.txt");
    cout << sum << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
