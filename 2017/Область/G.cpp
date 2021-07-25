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

FILE* file;

struct comp
{
	bool operator()(const int& a, const int& b) const
	{
		return a>b;
	};
};

const int MAXN = (int)1e5+5;

int n;
int dp[MAXN];//, u[MAXN];
map < PII, int> mp;
VEC <int> ans;
set < PII > st;
set < PII >:: iterator it;
multiset <int, comp> ms;

PII get_sg(int ind)
{
	/*PII pa;
	int ch = ind;
	while(!u[ch]) ch--;
	ch++;
	pa.FF = ch;
	ch = ind;
	while (!u[ch])ch++;
	ch--;
	pa.SS = ch;
	return pa;*/
	for (it = st.begin(); it != st.end(); it++){
		PII pa = (*it);
		if (ind >= pa.FF && ind <= pa.SS) {
			st.erase((*it));
			return pa;
		}
	}
}

void in()
{
	//ifstream cin("G.in");
	//cin >> n;
	file = fopen("G.in", "r");
	ios_base:: sync_with_stdio(false);
	fscanf(file, "%d", &n);
	ans.resize(n+1);
	for (int i = 1; i <= n; i++){
		int num;
		//cin >> num;
		fscanf(file, "%d", &num);
		dp[i] = (num^dp[i-1]);
	}
	PII p = MP(1, n);
	mp[p] = dp[n];
	ms.insert(dp[n]);
	//u[0] = 1;
	//u[n+1] = 1;
	st.insert(MP(1,n));
	for (int i = 1; i <= n; i++){
		int ind;
		//cin >> ind;
		fscanf(file, "%d", &ind);
		p = get_sg(ind);
		//u[ind] = 1;
		st.insert(MP(p.FF, ind-1));
		st.insert(MP(ind+1, p.SS));
		int num1 = (dp[ind-1]^dp[p.FF-1]), num2 = (dp[p.SS]^dp[ind]);
		PII np = MP(p.FF, ind-1);
		mp[np] = num1;
		np = MP(ind+1, p.SS);
		mp[np] = num2;
		ms.erase(ms.find(mp[p]));
		ms.insert(num1);
		ms.insert(num2);
		ans[i] = (*ms.begin());
	}
}

void out()
{
    //ofstream cout("G.out");
    /*for (int i = 1; i <= n; i++)
    	cout << dp[i] << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++){
    	for (int j = i+1; j <= n; j++){
    		cout << (dp[j]|dp[i]) << " ";
    	}
    	cout << (dp[i]^dp[i-1]) << " ";
    }
    cout << "\n";*/
    file = fopen("G.out", "w");
    for (int i = 1; i < n; i++)
    	fprintf(file, "%d ", ans[i]);
    	//cout << ans[i] << " ";
    fprintf(file, "%d ", ans[n]);
	//cout << ans[n] << "\n";
}

int main()
{
    in();
    out();
    return 0;
}
