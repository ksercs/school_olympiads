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

const int MAXN = (int)1e5+15;
int n, ln, lvl, l_count;
LL ans;
VEC < PII > v;

struct vertex
{
    int val;
    int Left;
    int Right;
};

vertex tree[1<<20];

int pred(int x)
{
  return x/2;
}

int potom(int x, int lr)
{
  return (2*x + lr);
}

int lvl_count(int x)
{
    int level=1, ch=1;
    while(ch<x)
    {
     ch*=2;
     level++;
    }
    return level;
}

void ln_count(int b)
{
  lvl = lvl_count(b);
  ln = (1<<(lvl))-1;
}

int Search(int v, int sL, int sR)
{
    //cout << v << " " <<sL << " " <<sR << "\n";
    if( (tree[v].Left != sL) || (tree[v].Right != sR) )
    {
        int l_pot = potom(v,0);
        int M = tree[l_pot].Right;
        if(sR <= M) return Search(l_pot, sL, sR);
        else if(M < sL)return Search(l_pot + 1, sL, sR);
        else return Search(l_pot, sL, M) + Search(l_pot + 1, M + 1, sR);
    }
    else{
        //cout << tree[v].val << "\n\n";
        return tree[v].val;
    }
}

void upd (int ind)
{
    int ch = l_count+ind;
    tree[ch].val = 1;
    while (ch != 1){
        tree[ch/2].val++;
        ch /= 2;
    }
}

void iniz_t()
{
  for (int i = l_count-1; i >=1; --i)
  {
      int l_p = potom(i,0), r_p = potom(i,1);
      tree[i].Left = tree[l_p].Left;
      tree[i].Right = tree[r_p].Right;
  }
}

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i){
        cin >> v[i].FF;
        v[i].SS = i;
    }
}

void solution()
{
    ln_count(n);
    l_count = (ln+1)>>1;
    //cout << l_count << "\n";
    for (int i = l_count; i < 2*l_count; ++i)
        tree[i].Left =  tree[i].Right = i-l_count;
    iniz_t();
    //for (int i = 1; i <= l_count+n-1; ++i)
        //cout << i << ": \n" << tree[i].Left << " " << tree[i].Right << "\n";
    sort(v.begin(), v.end());
    ans += v[0].SS+1;
    upd(v[0].SS);
    //for (int i = 0; i < n; ++i)
        //cout << v[i].FF << " " << v[i].SS << "\n";
    for (int i = 1; i < n; ++i){
        //cout << v[i-1].SS << " " << v[i].SS << " " << Search(1, v[i-1].SS, v[i].SS) << "\n";
        if (v[i].SS > v[i-1].SS)
            ans += v[i].SS - v[i-1].SS + 1 - Search(1, v[i-1].SS, v[i].SS);
        else
            ans += n-v[i-1].SS + v[i].SS + 1 - Search(1, v[i-1].SS, n-1) - Search(1, 0, v[i].SS);
        upd(v[i].SS);
    }
}

void out()
{
    ofstream cout("output.txt");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
