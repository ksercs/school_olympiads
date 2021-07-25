#include <iostream>
#include <fstream>
#include <vector>

#define SZ size()
#define PB push_back

using namespace std;

const int MAXNM = 1000 + 15;

int E[MAXNM], P[MAXNM];

int n, m;

vector <int> ans;

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        E[a] = 1;
    }
    for (int j = 0; j < m; j++)
    {
        int b;
        cin >> b;
        P[b] = 1;
    }
}

void solution()
{
    for (int i = 0; i <= 1000; i++)
    {
        if (E[i] == 1 && P[i] == 0) ans.PB(i);
        if (E[i] == 0 && P[i] == 1) ans.PB((-1)*i);
    }
}

void out()
{
    ofstream cout("output.txt");
    if (ans.SZ == 0) cout << "EQUAL\n";
    else
    {
        for (int i = 0; i < ans.SZ; i++)
        {
            ans[i] >= 0 ? cout <<"+" << ans[i] << endl : cout << ans[i] << endl;
        }
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
