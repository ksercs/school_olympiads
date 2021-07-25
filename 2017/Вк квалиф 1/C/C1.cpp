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
#include <stack>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

#pragma comment(linker, "/STACK:10000000")

using namespace std;

const int MAXN = 1000+15;

int n, m, k, stx, sty;
string ans;
char u[MAXN][MAXN];
int dx[] = {1, 0, 0, -1},
    dy[] = {0, -1, 1, 0};
char s[] = {'D', 'L', 'R', 'U'};
queue < PII > q;
int S[MAXN][MAXN];
stack < PII > st;

void in()
{
    ifstream cin("input.txt");
    cin >> n >> m >> k;
    for (int i = 0; i <= n+1; ++i){
        u[i][0] = '*';
        u[i][m+1] = '*';
    }
    for (int i = 0; i <= m+1; ++i){
        u[0][i] = '*';
        u[n+1][i] = '*';
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            cin >> u[i][j];
            if (u[i][j] == 'X'){
                stx = i;
                sty = j;
                u[i][j] = '.';
            }
        }
    /*for (int i = 0; i <= n+1; ++i){
        for (int j = 0; j <= m+1; ++j)
            cout << u[i][j] << " ";
        cout << "\n";
    }*/
}

void BFS()
{
    while (!q.empty()){
        int x = q.front().FF,
            y = q.front().SS;
        for (int i = 0; i < 4; ++i){
            int tox = x + dx[i],
                toy = y + dy[i];
            if (u[tox][toy] != '*' && S[tox][toy] == 0 && !(tox == stx && toy == sty)){
                q.push(MP(tox, toy));
                S[tox][toy] = S[x][y]+1;
            }
        }
        q.pop();
    }
}

void DFS()
{
    //cout << ans << "\n"; //system("PAUSE");
    while ((ans.SZ != k) && !st.empty()){
        PII p = st.top();
        st.pop();
        int x = p.FF,
            y = p.SS;
        for (int i = 0; i < 4; ++i){
            int tox = x + dx[i],
                toy = y + dy[i];
            if (u[tox][toy] != '*' && S[tox][toy] <= k-ans.SZ){
                ans += s[i];
                st.push(MP(tox, toy));
                break;
            }
        }
    }
}

void solution()
{
    if (k%2) return;
    q.push(MP(stx, sty));
    BFS();
    /*for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            cout << S[i][j] << " ";
        cout << "\n";
    }*/
    st.push(MP(stx, sty));
    DFS();
}

void out()
{

    ofstream cout("output.txt");
    if (!ans.SZ)  cout << "IMPOSSIBLE\n";
    else          cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
