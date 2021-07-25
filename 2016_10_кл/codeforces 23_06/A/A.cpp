#include <iostream>
#include <cstring>

using namespace std;

long long cnt, n, ans;

void in()
{
    cin >> n >> cnt;
    for (int i = 1; i <= n; i++)
    {
        char tp;
        int ch;
        cin >> tp >> ch;
        if (tp == '+') cnt += ch;
        else
        {
            if (cnt - ch >= 0) cnt -= ch;
            else ans++;
        }
    }
}

void out()
{
   cout << cnt << " " << ans << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
