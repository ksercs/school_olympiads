#include <iostream>
#include <fstream>

using namespace std;

long long a, b, a1, a2, b1, b2;

int main()
{
    ifstream cin("B.in");
    ofstream cout("B.out");
    cin >> a >> b;
    a1 = a/2*b; b1 = (a/2+a%2)*b;
    a2 = b/2*a; b2 = (b/2+b%2)*a;
    if (a2 < a1)  cout <<a1 << " " << b1 << "\n";
    else          cout <<a2 << " " << b2 << "\n";
}
