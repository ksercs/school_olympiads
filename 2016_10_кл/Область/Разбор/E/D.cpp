#include <iostream>

using namespace std;

int p;

void DFS(int ch)
{
    for (int i = p; i > 0; i--)
    {
          if (ch == 0) break;
          cout << ch << " ";
          ch--; DFS(ch);
    }
    cout << "\n";
}

void in()
{
    cin >> p;
}

void solution()
{
   DFS(p);
}

void out()
{
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
