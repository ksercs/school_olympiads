#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "F"
#define ms(a,x) memset(a, x, sizeof(a))
#define forit(it,s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); ++it)
#define MAXB 22
#define MAXN 100000

int n;
int a[MAXN];
int d[1 << MAXB];

int main()
{
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		++d[a[i]];
	}

   for (int i = 0; i < n; ++i)
   {
   	int r = 0;
   	int mmask = ((1 << MAXB) - 1) ^ a[i];
   	for (int mask = mmask; mask; mask = (mask - 1) & mmask)
   	{
   		r += d[mask];
   	}
   	printf("%d%c", r, " \n"[i + 1 == n]);
   }

	return 0;
}
