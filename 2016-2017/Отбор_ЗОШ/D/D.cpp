#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>

#define SZ size()

using namespace std;

const int MAXN = 50+5;
const double EPS = 0.00001;

int n, m, d, ans1, ans2;
double s;

int dp[MAXN][MAXN];

set <char> st;

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m >> d;
    string str;
    cin >> str;
    for (int i = 0; i < str.SZ; i++)
    {
        st.insert(str[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char a;
            cin >> a;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if (st.count(a)) dp[i][j]++;
        }
    }
   /* for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int g = d-1; g <= n-i; g++)
            {
                for (int c = d-1; c <= m-j; c++)
                {
                    int cnt, bg;
                    int toi = (i+g), toj = (j+c);
                    cnt = toi*toj - (i-1)*toj - toi*(j-1) + (i-1)*(j-1);
                    bg = dp[toi][toj] - dp[i-1][toj] - dp[toi][j-1] + dp[i-1][j-1];
                    /*if (i == 5 && j == 5){
                    cout << i << " " << j << " " <<toi << " " << toj << " " << bg << " " << cnt << endl; system("PAUSE");
                    cout << dp[toi][toj] << " " << dp[i-1][toj] << " " << dp[toi][j-1] << " " << dp[i-1][j-1] << endl; system("PAUSE");}*/
                    double rz = 1.0*bg/cnt;
                    if (rz > s || (rz == s && cnt > ans2) )
                    {
                        s = rz;
                        ans1 = bg;
                        ans2 = cnt;
                        //cout <<"ANS: " << s << " " << bg << " " << cnt << endl; system("PAUSE");
                    }
                }
            }
        }
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans1 << "/" << ans2 << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
