#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n;

vector <int> ans;

void in()
{
    ifstream cin ("schedule.in");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        ans.push_back(a^b);
    }
}

void solution()
{
}

void out()
{
     ofstream cout ("schedule.out");
     for (int i = 0 ; i < ans.size(); i++)
     {
         cout << ans[i] << endl;
     }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
