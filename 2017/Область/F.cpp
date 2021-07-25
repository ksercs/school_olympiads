#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <climits>

#define PB push_back
#define SZ size()
#define VEC vector
#define MP make_pair
#define PII pair <int,int>
#define FF first
#define SS second
#define LL long long

using namespace std;

FILE* file;

const int MAXN = (int)1e5+15;

int n, UP;
LL ans;
LL R[MAXN], m[MAXN];
int gr[MAXN];

void in()
{
	/*ifstream cin("F.in");
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> gr[i];
	for (int i = 1; i <= n; i++)
		cin >> R[i];*/
	file = fopen("F.in", "r");
	ios_base:: sync_with_stdio(false);
	fscanf(file, "%d", &n);
	for (int i = 1; i <= n; i++)
		fscanf(file,  "%d", &gr[i]);
	for (int i = 1; i <= n; i++)
		fscanf(file, "%ld", &R[i]);
}

void solution()
{
	UP = 1000000/n;
	for (int t = 1; t <= UP; t++){
		if (t%2){
			for (int i = 1; i <= n; i++){
				m[gr[i]] += R[i];
				ans = max(ans, m[gr[i]]);
			}
			fill(R+1, R+n+1, 0);
		}
		else{
			for (int i = 1; i <= n; i++){
				R[gr[i]] += m[i];
				ans = max(ans, R[gr[i]]);
			}
			fill(m+1, m+n+1, 0);
		}
	}
}

void out()
{
    /*ofstream cout("F.out");
    cout << ans << "\n";*/
    file = fopen("F.out", "w");
    fprintf(file, "%ld\n", ans);
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
