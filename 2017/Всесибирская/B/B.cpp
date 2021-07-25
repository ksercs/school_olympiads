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

const int MAXN = (int)1e5+5;

FILE* file;

int n, m, answer=1, a, cnt;
VEC < VEC <int> > gr;
VEC <int> ans;
map < PII , int> mp;
VEC < set <int> > u;
int mm[MAXN];

void in()
{
    //ifstream cin("input.txt");
    file = fopen("input.txt", "r");
    ios_base:: sync_with_stdio(false);
   // cin >> n >> m;
    fscanf(file, "%d%d", &n, &m);
    gr.resize(n+1);
    u.resize(n+1);
    ans.resize(m+1);
    for (int i = 1; i <= m; i++){
        int a, b;
       // cin >> a >> b;
        fscanf(file, "%d%d", &a, &b);
        if (a > b) swap(a,b);
        mp[MP(a,b)] = i;
        //mp[MP(b,a)] = i;
        gr[a].PB(b);
        //gr[b].PB(a);
    }
}

void solution()
{
    //cout << "SEJFUIEHGJF\n";
    for (int i = 1; i <= n; i++)
        mm[i] = 1;
    //cout << "SELGSEG\n";
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < gr[i].SZ; j++){
            //system("PAUSE");
            //cout << i << " " << gr[i][j] << "\n";
            //if (ans[mp[MP(i, gr[i][j])]] != 0) continue;
            if (u[i].SZ == 0 && u[gr[i][j]].SZ == 0) {
                ans[mp[MP(i, gr[i][j])]] = 1;
                u[i].insert(1);
                mm[i] = 2;
                u[gr[i][j]].insert(1);
                mm[gr[i][j]] = 2;
                //answer = max(1, answer);
            }
            else{/*
                if (u[i].SZ != 0 && u[gr[i][j]].SZ != 0) {
                    a = max((*u[i].rbegin()), (*u[gr[i][j]].rbegin()))+1;
                     if (u[i].SZ < a-1 && u[gr[i][j]].SZ < a-1)
                        for (int k = 1; k < a/2+1; k++){
                            if (!u[i].count(k)) if (!u[gr[i][j]].count(k)) {a = k; break;}
                            if (!u[i].count(a-k)) if (!u[gr[i][j]].count(a-k)) {a = a-k; break;}
                        }
                    else{
                      if (u[i].SZ < a-1 )
                        for (int k = 1; k < a/2+1; k++){
                            if (!u[i].count(k)) {a = k; break;}
                            if (!u[i].count(a-k)) {a = a-k; break;}
                        }
                      if (u[gr[i][j]].SZ < a-1 )
                        for (int k = 1; k < a/2+1; k++){
                            if (!u[gr[i][j]].count(k)) {a = k; break;}
                            if (!u[gr[i][j]].count(a-k)) {a = a-k; break;}
                        }
                    }
                }
                else{
                    if (u[i].SZ != 0){
                        a = (*u[i].rbegin())+1;
                        if (u[i].SZ < a-1 )
                            for (int k = 1; k < a/2+1; k++){
                                if (!u[i].count(k)) {a = k; break;}
                                if (!u[i].count(a-k)) {a = a-k; break;}
                            }
                    }
                    if (u[gr[i][j]].SZ != 0){
                        a = (*u[gr[i][j]].rbegin())+1;
                        if (u[gr[i][j]].SZ < a-1 )
                            for (int k = 1; k < a/2+1; k++){
                                if (!u[gr[i][j]].count(k)) {a = k; break;}
                                if (!u[gr[i][j]].count(a-k)) {a = a-k; break;}
                            }
                    }
                }*/
                //cout << i << " " << gr[i][j] << "\n";
                a = min(mm[i], mm[gr[i][j]]);
                if (u[i].count(a) || u[gr[i][j]].count(a)) a = max(mm[i], mm[gr[i][j]]);
                if (u[i].count(a) || u[gr[i][j]].count(a)){
                    //a = min(mm[i], mm[gr[i][j]]);
                    while (u[i].count(a) || u[gr[i][j]].count(a)) a++;
                }
                u[i].insert(a);
                u[gr[i][j]].insert(a);
                ans[mp[MP(i, gr[i][j])]] = a;
                answer = max(a, answer);
                int b = a;
                if (a == mm[i])
                    while ( u[i].count(a))
                        a++;
                mm[i] = a;
                if (b == mm[gr[i][j]])
                    while (u[gr[i][j]].count(b))
                        b++;
                mm[gr[i][j]] = b;

            }
            //cnt++;
           // if (cnt == m) break;
        }
        //8if (cnt == m) break;
    }
}

void out()
{
    //fstream cout("output.txt");
    file = fopen("output.txt", "w");
    /*cout << answer << "\n";
    for (int i = 1; i < m; i++)
        cout << ans[i] << " ";
    cout << ans[m] << "\n";*/
    fprintf(file, "%d\n", answer);
    for (int i = 1; i < m; i++)
        fprintf(file, "%d ", ans[i]);
    fprintf(file, "%d\n", ans[m]);

}

int main()
{
    in();
    solution();
    out();
    return 0;
}
