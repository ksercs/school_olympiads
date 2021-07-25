#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

const int MAXN = 105;

int t, n, m, k, maxcol;
int gr[MAXN][MAXN], u[MAXN][MAXN];

int get_x(int x, int y)
{
    set <int> st;
    for (int i = y-1; i >= 1; --i) st.insert(gr[x][i]);
    int col = 1;
    while (st.count(col)) ++ col;
    return col;
}

int get_y(int x, int y)
{
    set <int> st;
    for (int i = x-1; i >= 1; --i) st.insert(gr[i][y]);
    int col = 1;
    while (st.count(col)) ++ col;
    return col;
}

void in()
{

    ifstream cin("input.txt");
    cin >> t;
    for (int g = 0; g < t; ++g){
        cin >> n >> m >> k;
        int fl = 1;
        for (int i = 0; i <= n+1; ++i){
            u[i][0] = 1;
            u[i][m+1] = 1;
        }
        for (int i = 0; i <= m+1; ++i){
            u[0][i] = 1;
            u[n+1][i] = 1;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j){
                cin >> gr[i][j];
                u[i][j] = (!gr[i][j]);
            }
        /*for (int i = 0; i <= n+1; ++i){
            for (int j = 0; j <= m+1; ++j)
                cout << u[i][j] << " ";
            cout <<  "\n";
        }*/
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j){
                gr[i][j] = max(get_x(i, j), get_y(i, j))*gr[i][j];
                maxcol = max(maxcol, gr[i][j]);
            }
        if (maxcol > k) fl = 0;
        if (fl){
            cout << "YES\n";
            for (int i = 1; i <= n; ++i){
                for (int j = 1; j < m; ++j)
                    cout << gr[i][j] << " ";
                cout << gr[i][m] << "\n";
            }
        }
        else     cout << "NO\n";
        maxcol = 1;
        //cout << "\n\n";
    }//
}

int main()
{
    in();
    return 0;
}
