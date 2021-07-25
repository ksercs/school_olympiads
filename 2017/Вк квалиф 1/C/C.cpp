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

const int MAXN = 1000+15;

int n, m, k, stx, sty, fl;
string ans, ans1, ans2;
char u[MAXN][MAXN];
int dx[] = {1, 0, 0, -1},
    dy[] = {0, -1, 1, 0};
char s[] = {'D', 'L', 'R', 'U'};
char z[300];
set <string> st, answer;

void DFS(int x, int y)
{
    //cout << ans << "\n"; system("PAUSE");
    /*for (int i = 0; i <= n+1; ++i){
        for (int j = 0; j <= m+1; ++j)
            cout << u[i][j] << " ";
        cout << "\n";
    }
    cout << "\n"; system("PAUSE");*/
    u[x][y] = '*';
    for (int i = 0; i < 4; ++i){
        int tox = x+dx[i],
            toy = y+dy[i];
        if (u[tox][toy] != '*'){
                ans += s[i];
                if (!(k%ans.SZ) && !((k/ans.SZ)%2)){
                        fl = 1;
                        if (ans.SZ > ans1.SZ) st.insert(ans); //ans1 = ans;
                        //cout << "ANS = " << ans1 << "\n";
                }
                if (fl != 2 && ans.SZ < k/2)
                    DFS(tox, toy);
                if (fl) {
                        fl = 2;
                        return;
                }
                ans.erase(ans.SZ-1, 1);
        }
    }
    u[x][y] = '.';
}

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

void solution()
{
    #pragma comment(linker, "/STACK:1000000000")
    if (k%2) return;
    z['D'-'0'] = 'U';
    z['U'-'0'] = 'D';
    z['R'-'0'] = 'L';
    z['L'-'0'] = 'R';
    //setrecursion(int(1e6+5));
    DFS(stx, sty);
    if (/*!ans1.SZ*/ st.empty()) return;
    set <string>:: iterator it;
    for (it = st.begin(); it != st.end(); it++){
        ans1 = (*it);
        ans2 = ans1;
        reverse(ans2.begin(), ans2.end());
        for (int i = 0; i < ans2.SZ; ++i){
            ans2[i] = z[ans2[i]-'0'];
        }
        //cout << ans1 << " " << ans2 << "\n";
        ans = "";
        int cnt = k/(2*ans1.SZ);
        for (int i = 0; i < cnt; ++i)
            ans += ans1+ans2;
        answer.insert(ans);
    }
}

void out()
{
    ofstream cout("output.txt");
    if (!answer.SZ) cout << "IMPOSSIBLE\n";
    else            cout << (*answer.begin()) << "\n";
}


int main()
{
    in();
    solution();
    out();
    return 0;
}
