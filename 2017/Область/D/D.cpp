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

#define PII pair <int, int>
#define SS second
#define FF first

using namespace std;

const int MAXN = (int)2*1e6, MOD = (int)1e9+7;

int tr[MAXN], w[MAXN],  mass[MAXN];
int n, ans=1, last;
set <int> st;
set <int>:: iterator it;

int pot(int ind, int t)
{
	return 2*ind+t;
}

int pr(int ind)
{
	return ind/2;
}

void obnov(int ind)
{
	for (int i = 0; i < 2; i++){
		int p = pot(ind, i);
		last = max(last, p);
		if (tr[p] == 0) tr[p]++;
		else{
			tr[p]*=2;
			tr[p]++;
			tr[p] %= MOD;
			obnov(p);
		}
	}	
}

int get_ans(int ind)
{
	if (tr[ind]==0) return 0;
	else{
		int ch = 1;
		for (int j = 1; j <= w[ind]; j++){
			ch *= 2; ch++;
		}
		int L =pot(ind,0), R = pot(ind,1); 
		if (w[L] == w[R] || tr[L] == tr[R] && tr[L] == 0) {
			int a1 = get_ans(pot(ind, 0));
			int a2 = get_ans(pot(ind, 1));
			if (a1 != -1 && a1 != -1)return a1+a2;
		}
	}
	return -1;
}

void in()
{
    ifstream cin("D.in");
	cin >> n;
	tr[1] = 1;
	for (int i = 0; i < n; i++){
		int ind;
		cin >> ind;
		tr[ind] *= 2;
		tr[ind] ++;
		tr[ind] %= MOD;
		obnov(ind);
		st.insert(ind);
		mass[ind]++;
		w[ind]++;
	}
	//for (int i = 1; i <= 100; i++) cout << tr[i] << " ";
	//cout << last << "\n";
}

void solution()
{
	int fl = 1;
	for (it = st.begin(); it != st.end(); it++)
		if ((*it) > 3) fl = 0;
	if (fl){
		ans = 1;
		if (mass[2]==mass[3]) 
			for (int i = 1; i <= mass[1]+mass[2]; i++){
				ans *= 2; ans++;
			}
		else{
			for (int i = 1; i <= mass[1]+max(mass[2],mass[3])-1; i++){
				ans *= 2; ans++;
			}
		}
	}
	else {
		for (int i = 1; i <= last; i++){
		if (w[i] == 0) continue;
		int ch = 1;
		for (int j = 1; j <= w[i]; j++){
			ch *= 2; ch++;
		}
		//cout << i << ": " << ch << "\n";
		int L =pot(i,0), R = pot(i,1); 
		if (w[L] == w[R] || tr[L] == tr[R] && tr[L] == 0) {
			int a1 = get_ans(pot(i, 0));
			int a2 = get_ans(pot(i, 1));
			if (a1 != -1 && a1 != -1)ch += a1+a2;
			else	ch = -1;
			if (ch != -1) ans = max(ans, ch);
			//cout << i << ": " << ch << "\n";
		}
	}
	}
}

void out()
{
    ofstream cout("D.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
