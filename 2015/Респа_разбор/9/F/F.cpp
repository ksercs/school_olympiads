#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, ans;
int hig[100000+5], cost[100000+5], m[];
long long sum[100000+5];

void s_r()
{
    for(int i=1; i<=n; i++)
    {
        sum[i]=sum[i-1]+cost[i];
    }
}

void v()
{
    for(int i=1; i<=n; i++)
    {
       cout <<sum[i] <<" ";
    }
}

void in()
{
ifstream cin("F.in");
cin >>n;
 for(int i=1; i<=n; i++)
 {
    cin >>hig[i];
 }
 for(int i=1; i<=n; i++)
 {
    cin >>cost[i];
 }
}

void solution()
{
 s_r();
 v();
}

void out()
{
ofstream cout("F.out");

}

int main()
{
 in();
 solution();
 out();
return 0;
}
