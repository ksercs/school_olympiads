#include <iostream>
#include <fstream>

using namespace std;

int N, M, C, ch, ans;

void in()
{
    ifstream cin("input.txt");
    cin >> N >> M >> C;
}

void solution()
{
    ch = N+M;
    while (ch >= C)
    {
        ch = ch - C + 1;
        ans++;
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
