#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int del[1000000], M[10000000];
int n, ans, cont;

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> M[i];
}

void solution()
{
   for (int i = 0; i < n; i++)
   {
       ans = min(ans, M[i]);
   }
   int j = 0;
   for (int i = 2; i*i <= n; i++)
   {
       while (ans%i == 0)
       {
           del[j] = i;
           j++;
       }
   }
   for (int i = 0; i < j; i++)
   {
       for (int k = 0; k < n; k++)
       {
           if (M[k]%ans == 0) cont++;
           else break;
       }
       if (cont == n-1) break;
       else ans=ans/del[i];
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
