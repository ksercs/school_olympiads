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

FILE* file;

const int MAXN = int(2*1e5+5);

struct cmp
{
  bool operator()(const  pair <int, PII >& a, const pair <int, PII >& b) const
  {
      if (a.FF == b.FF)
        return a.SS.FF > b.SS.FF;
      return a.FF < b.FF;
  };
};

int n;
int mass[MAXN], u[MAXN];
set < pair <int, PII >, cmp> st;
set < pair <int, PII >, cmp> :: iterator it;
VEC <int> ans1, ans2;
set <int> indx;

void in()
{
    //ifstream cin("input.txt");
    file = fopen("input.txt", "r");
    //cin >> n;
    fscanf(file, "%d", &n);
    for (int i = 0; i < 2*n; ++i)
        fscanf(file, "%d", &mass[i]);
        //cin >> mass[i];
}

void solution()
{
    sort(mass, mass+2*n);
    for (int i = 0; i < 2*n-1; ++i){
        int zn = mass[i+1] - mass[i];
        st.insert(MP(zn, MP(i, i+1)));
        indx.insert(i);
    }
    indx.insert(2*n-1);
    while (!st.empty()){
        int ind1 = (*st.begin()).SS.FF, ind2 = (*st.begin()).SS.SS;
        indx.erase(ind1);
        indx.erase(ind2);
        //for (it = st.begin(); it != st.end(); it++)
        //    cout << "(" << (*it).SS.FF << " " << (*it).SS.SS << ") ";
        //cout << "\n";
        u[ind1] = 1;
        u[ind2] = 1;
        ans1.PB(mass[ind2]);
        ans2.PB(mass[ind1]);
        st.erase(st.begin());
        int nind1 = ind1-1, nind2 = ind2+1;
        int index1, index2;
        set <int>:: iterator iter;
        iter = indx.lower_bound(ind1);
        int fl1 = 0, fl2 = 0;
        if (iter != indx.begin()){
            fl1 = 1;
            iter--;
            index1 = (*iter);
            int z2 = mass[ind1] - mass[index1];
            st.erase(MP(z2, MP(index1, ind1)));
        }
        iter = indx.lower_bound(ind2);
        if (iter != indx.end()){
            fl2 = 1;
            index2 = (*iter);
            int z1 = mass[index2] - mass[ind2];
            st.erase(MP(z1, MP(ind2, index2)));
        }
        //cout << "INDEX:" << index1 << " " << index2 << "\n";
        if ( fl1 && fl2 /*&& !u[nind1] && !u[nind2]*/)
            st.insert(MP(mass[index2]-mass[index1], MP(index1, index2)));
    }
}

void out()
{
    //ofstream cout("output.txt");
    file = fopen("output.txt", "w");
    for (int i = 0; i < n-1; ++i)
        fprintf(file, "%d ", ans1[i]);
        //cout << ans1[i] << " ";
    //cout << ans1[n-1] << "\n";
    fprintf(file, "%d\n", ans1[n-1]);
    for (int i = 0; i < n-1; ++i)
        fprintf(file, "%d ", ans2[i]);
        //cout << ans2[i] << " ";
    fprintf(file, "%d\n", ans2[n-1]);
    //cout << ans2[n-1] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
