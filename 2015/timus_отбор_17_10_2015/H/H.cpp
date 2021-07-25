#include<iostream>
#include<fstream>

using namespace std;

const int MAX_SIZE = 100000 + 5;

int n, m, chx, chy, ans, answer;

int x[MAX_SIZE], y[MAX_SIZE];

void fun(char s, int ind)
{
    if (chy == n || chx == m || answer != 0) {answer = ans; return;}
    int maxx = 0, index;
    if (s == 'y')
    {
        for (int i = ind; i < m; i++)
        {
            if (y[i] > maxx) {maxx = y[i]; index = i;}
        }
        chx++;
        ans =min(ans, y[index]);
        fun('x', chx);
    }
    else
    {
        for (int i = ind; i < n; i++)
        {
            if (x[i] > maxx) {maxx = x[i]; index = i;}
        }
        chy++;
        ans = min(ans, x[index]);
        fun('y', chy);
    }
}

void in()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }
}

void solution()
{
   if (x[0] >= y[0]) {ans = x[0]; fun('y', chy);}
   if (y[0] >= x[0]) {ans = y[0]; fun('x', chx);}
}

void out()
{
    cout << max(answer, max(min(y[0], x[m-1]), min(x[0], y[n-1]))) << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
