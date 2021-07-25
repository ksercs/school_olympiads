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

int n, fl;
VEC <int> ans;
int ind[MAXN];
set < PII > st, tmp;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    ans.resize(n);
    for (int t = 0; t < n; t++){
        int k;
        cin >> k;
        int mass[k+1];
        for (int j = 1; j <= k; j++){
            cin >> mass[j];
            //int ch;
            //cin >> ch;
            ind[mass[j]] = j;
        }
        for (int i = 1; i <= k; i++){
            //for (int c = 1; c <= k; c++)
              //  cout << mass[c] << " ";
                //cout << c << " " << ind[c] << "\n";
            //cout << "\n";
            if (ind[i] > i){
                 int j = ind[i]-1;
                 while (ind[i] != i){
                    if (st.count(MP(ind[i],j)) || st.count(MP(j,ind[i])) || tmp.count(MP(ind[i],j)) || tmp.count(MP(j,ind[i]))) {fl = 1; break;}
                    swap(mass[ind[i]], mass[j]);
                    tmp.insert(MP(ind[i],j));
                    tmp.insert(MP(j,ind[i]));
                    ind[mass[ind[i]]] = ind[i];
                    ind[i] = j;
                    //swap(mass[ind[i]], mass[j]);
                    j--;
                 }
            }
            if (ind[i] < i){
                 int j = ind[i]+1;
                 while (ind[i] != i){
                    if (st.count(MP(ind[i],j)) || st.count(MP(j,ind[i])) || tmp.count(MP(ind[i],j)) || tmp.count(MP(j,ind[i])) ) {fl = 1; break;}
                    swap(mass[ind[i]], mass[j]);
                    tmp.insert(MP(ind[i],j));
                    tmp.insert(MP(j,ind[i]));
                    ind[mass[ind[i]]] = ind[i];
                    ind[i] = j;
                    j++;
                 }
            }
            if (fl)  break;
            else
                while (tmp.SZ > 0){
                    st.insert((*tmp.begin()));
                    tmp.erase((*tmp.begin()));
                }
        }
        tmp.clear();
        st.clear();
        ans[t] = fl;
        fl = 0;
    }
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 0; i < n; i++)
        (ans[i] == 0) ? cout << "YES\n" : cout << "NO\n";
}

int main()
{
    in();
    out();
    return 0;
}
