#include <iostream>
#include <string>

using namespace std;

int n, fl;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name;
        int st, fn;
        cin >> name >> st >> fn;
        if (st >= 2400)
        {
            if (fn > st) fl = 1;
        }
    }
    if (fl) cout << "YES\n";
    else    cout << "NO\n";
    return 0;
}
