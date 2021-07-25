#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

const int  MAX_SIZE = 100000  + 5;

int n, ind, st = 0, k;
long long answer;

vector <long long> ans;

vector <pair <int ,int> > m[MAX_SIZE];
pair <int ,int> mass[MAX_SIZE];

void dfs(int index)
{

    k++;
    int ch = 0;
    for (int i = 0; i < m[ch].size(); i++)
    {
        answer += abs(m[ch][i].second-st);
        answer++;
        dfs(ch++);
    }

}

void in()
{
    cin >> n;
    for (int g=0; g<n; g++)
    {
        cin >> mass[g].first;
        mass[g].second = g;
    }
    sort(mass, mass+n);
    m[ind].push_back(mass[0]);
    for (int i = 1; i < n; i++)
    {
        if (m[ind][0] != mass[i]) {ind++;}
        m[ind].push_back(mass[i]);
    }
}

void solution()
{
  dfs(0);
}

void out()
{
    /*for (int i = 0; i <= ind; i++)
    {
        for (int g = 0; g < m[i].size(); g++)
        {
            cout << m[i][g].first << " " <<m[i][g].second << "\n";
        }
    }*/
    //cout << answer <<"\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
