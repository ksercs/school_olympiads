#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAX_COUNT = 100000+5;

int n, m, wer, ost, ind;

long long a[MAX_COUNT];

int bin_R(int x, int l, int r)
{
    int mid;
    while (r-l > 0)
    {
        mid = l + (r - l) / 2;
        if (a[mid] < x)   {l = mid;}
        else{
            if (a[mid] > x) {r = mid;}
            else                  {
                                    return mid+1;
                                  }
        }
    }
    if (a[l]==x) {return l+1;}
    if (a[r]==x) {return r+1;}
    if (l == 0) return 0;
    return l+1;
}

void in()
{
    ifstream cin ("ship.in");
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void solution()
{
    wer = m/n;
    ost = m%n;
    ind = bin_R(2, 0, n-1);
}

void out()
{
     ofstream cout ("ship.out");
    /* for (int i = 0; i < n-1; i++)
     {
         if (i >=ind-ost && i <ind) {cout << wer+1 << " ";}
         else                        {cout << wer << " ";}
     }
     if (n-1 >=ind-ost && n-1 <ind) {cout << wer+1 << "\n";}
     else                        {cout << wer << "\n";}*/
     cout << ind << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
