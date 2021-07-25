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

const int MAXN = (int)1e5+15;

int n, x, fl, sp;
int num[MAXN];
set < PII > sg;
set < PII >:: iterator it;
map < PII, int > mp;

void in()
{
	//ifstream cin("H.in");
	file = fopen("H.in", "r");
	ios_base:: sync_with_stdio(false);
	//cin >> n >> x;
	fscanf(file, "%d%d", &n, &x);
	for (int i = 1; i <= n; i++)
		fscanf(file, "%d", &num[i]);
		//cin >> num[i];
}

/*void PLAN_B(int ch)
{
	while (ch > x && sg.SZ > 0)
	{
		PII p = (*sg.rbegin());
		sg.erase((*sg.rbegin()));
		ch = (ch^mp[p]);
		if (ch <= x) break;
	}
}*/

int PLAN_C(int c)
{
	PII p = (*sg.rbegin());
	if ((c^mp[p]) <= x){
		sg.erase((*sg.rbegin()));
		sp = p.FF;
		return (c^mp[p]);
	}
	return -1;
}

void solution()
{
	int ind = 1;
	while (1){
		int ch = num[ind];
		if (ind == n+1) break;
		if (ch <= x){
			//cout << "OK: " << ind  << "\n";
			sg.insert(MP(ind,ind));
			ind++;
			mp[MP(ind,ind)] = ch;
			//fl = 1;
			continue;
		}
		else if (sg.SZ != 0){ 
			int f = PLAN_C(ch);
			if (f != -1){
			sg.insert(MP(sp,ind));
			mp[MP(sp,ind)] = f;
			//cout << "C1: " << sp << " " << ind << "\n";
			//fl = 1;
			ind++;
			continue;
		}
		}
		int i;
		for (i = ind+1; i <= n; i++){
			//cout << i << " " << ch << "\n";
			if ((ch^num[i]) <= x){
				ch = (ch^num[i]);
				sg.insert(MP(ind,i));
				mp[MP(ind,i)] = ch;
				//cout << "A: " << ind << " " << i << "\n"; system("PAUSE");
				fl = 1;
				break;
			}
			else if (sg.SZ != 0) {
				int f = PLAN_C(ch);
				if (f != -1){
					sg.insert(MP(ind,i));
					mp[MP(sp,i)] = f;
					//cout << "C2: " << sp << " " << i << "\n";
					fl = 1;
					break;
				}
			} 
			if (!fl) ch = (ch^num[i]);
		} 
		ind = i+1;
		if (!fl){
			//cout << "\n ---- PLAN_B -----\n";
			//PLAN_B(ch);
			sg.clear();
			break;
		}
		fl = 0;
	}
}

void out()
{
    //ofstream cout("H.out");
	file = fopen("H.out", "w");
	if (sg.SZ == 0) fprintf(file, "-1\n");
	else			fprintf(file, "%d\n", sg.SZ);
	/*for (it = sg.begin(); it != sg.end(); it++)
		cout << (*it).FF << " " << (*it).SS << "\n";*/
}

int main()
{
    in();
	solution();
    out();
    return 0;
}
