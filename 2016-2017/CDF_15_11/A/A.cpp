#include <iostream>
#include <string>

#define SZ size()

using namespace std;

int n, A, D;
string str;

void in()
{
    cin >> n;
    cin >> str;
}

void solution()
{
   for (int i = 0; i < str.SZ; i++)
   {
       if (str[i] == 'A') A++;
       else               D++;
   }
}

void out()
{
    if (A > D) cout << "Anton\n";
    if (A < D) cout << "Danik\n";
    if (A == D) cout << "Friendship\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
