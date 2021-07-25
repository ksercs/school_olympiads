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

using namespace std;

const int MAXN = (int)1e5+15;

int n, fl, mass[MAXN];
double X, need;
VEC < double > v;
VEC < double >:: iterator it;
VEC <int> ans;
map <double, VEC <int> > mp;

void get_ans()
{
	it = lower_bound(v.begin(), v.end(), need);
	int ind = it - v.begin();
	if (ind == v.SZ) {ind--; it--;}
	//cout << ind << " " << v[ind] << "\n";
	if (need >= v[ind]){
		need -= v[ind];
		ans.PB(mp[v[ind]][0]);
		mass[mp[v[ind]][0]] = 1;
		mp[v[ind]].erase(mp[v[ind]].begin());
		v.erase(it);
		get_ans();
	}
}

void in()
{
    ifstream cin("C.in");
    cin >> n >> X;
    v.resize(n);
    for (int i = 0; i < n; i++){
    	cin >> v[i];
    	mp[v[i]].PB(i+1);
    }
}

void solution()
{
	sort(v.begin(), v.end());
	ans.PB(mp[v[n-1]][0]);
	mass[mp[v[n-1]][0]] = 1;
	mp[v[n-1]].erase(mp[v[n-1]].begin());
	need = X - v[n-1];
	v.pop_back();
	get_ans();
	double ch = 0.0;
	for (int i = 1; i <= n; i++)
		if (!mass[i]) ch += v[i];
	if (ch > X) fl = -1;
}

void out()
{
    ofstream cout("C.out");
    if (fl == -1) cout << fl << "\n";
    else{
    	cout << ans.SZ << "\n";
    	for (int i = 0; i < ans.SZ-1; i++)
			cout << ans[i] << " ";
		cout << ans[ans.SZ-1] << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
