#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int ans;
string line;

void in()
{
    ifstream cin("input.txt");
    getline(cin, line);
}

void solution()
{
    for (int i = 0; i < line.size(); i++)
    {
        if ((line[i] >= 'A' && line[i]<= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) ans++;
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
