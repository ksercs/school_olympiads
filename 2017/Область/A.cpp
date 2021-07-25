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

int t, sum;
int mass[5];
VEC <int> ans;

void solution(int ind)
{
	sort(mass, mass+5);
	/*for (int i = 0; i < 5; i++) cout << mass[i] << " ";
	cout << "\n" << sum << "\n";*/
	if (sum % 5 != 0){
		ans[ind] = -1;
		sum = 0;
		return;
	}
	int m = sum/5;
	//cout << mass[1] << " " << mass[2] << " " << mass[3] << " " << m << "\n";
	if ((mass[1] == mass[2]) && (mass[2] == mass[3]) && (mass[1] == m)) {ans[ind] = 1;}// cout << "111\n";}
	else{
		//cout << "222\n";
		int dop = mass[4] - m;
		if (dop - (m-mass[0]) == m - mass[1]) ans[ind] = 2;
		dop = mass[4] - m + mass[3]-m;
		if (dop == m-mass[0]) ans[ind] = 2;
		int dop1 = mass[3]-m, dop2 = mass[4]-m;
		if (mass[0]+dop1 == m && mass[1]+dop2 == m || mass[1]+dop1==m && mass[0]+dop2 == m) ans[ind] = 2;
	}
	if (ans[ind] == 0) ans[ind] = -1;
	sum = 0;
	/*for (int i = 0; i < 5; i++) cout << mass[i] << " ";
	cout << "\n";*/
}

void in()
{
    ifstream cin("A.in");
    cin >> t;
    ans.resize(t);
    for (int i = 0; i < t; i++){
    	for (int j = 0; j < 5; j++){
    		cin >> mass[j];
    		sum += mass[j];
		}
    	solution(i);
    }
}

void out()
{
    ofstream cout("A.out");
    for (int i = 0; i < t; i++)
    	(ans[i] == -1) ? cout <<"NO\n" : cout << ans[i] <<"\n"; 
}

int main()
{
    in();
    out();
    return 0;
}
