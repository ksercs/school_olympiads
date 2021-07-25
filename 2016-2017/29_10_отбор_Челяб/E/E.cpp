#include <iostream>
#include <map>
#include <string>

#define STR string
#define SZ size()

using namespace std;

int n, ans;
map <STR, int> name;

void in()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        STR s;
        cin >> s;
        if (name[s] > i-1-name[s]) ans++;
        name[s]++;
    }
}

void out()
{
    cout << ans << endl;
}

int main()
{
    in();
    out();
    return 0;
}
