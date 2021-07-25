#include <iostream>
#include <string>

#define STR string
#define SZ size()

using namespace std;

const int num = (int)('A')-1;

int ans = 1, len;
STR s;

void in()
{
    cin >> s;
}

void solution()
{
    len = s.SZ;
    for (int i = 0; i < len; i++)
    {
        int smb = (int)s[i]-num;
        if ( ans == smb ) ans++;
        else if (ans == smb+1) ans--;
    }
}

void out()
{
    cout << ans << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
