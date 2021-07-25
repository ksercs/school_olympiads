#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, ans;

void in()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ans += a/2;
    }
}

void out()
{
  if (ans%2 == 0 ) {cout << "Stannis\n";}
  else  {cout << "Daenerys\n";}
}

int main()
{
    in();
    out();
return 0;
}
