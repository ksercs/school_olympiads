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

int n;
string str, s;

set <char> st;
set <char>:: iterator it;
set <string> ans;

void check()
{
	//cout << s << "\n"; system("PAUSE");
	string S = "";
	set <char> ss;
	for (int i = 0; i < s.SZ; i++)
		if (s[i] == '1') {
			S += str[i];
			ss.insert(str[i]);
		}
	if (st.SZ == ss.SZ) ans.insert(S);
}

void DFS()
{
	//cout << s << "\n"; system("PAUSE");
	if (s.SZ == str.SZ) {check(); return;}
	s+='0';
	DFS();
	s.erase(s.SZ-1, 1);
	s+='1';
	DFS();
	s.erase(s.SZ-1, 1);
}

void in()
{
	ifstream cin("E.in");
	ios_base:: sync_with_stdio(false);
	cin >> n;
	cin >> str;
}

void solution()
{
	for (int i = 0; i < str.SZ; i++) st.insert(str[i]);
	DFS();
}

void out()
{
    ofstream cout("E.out");
    cout << (*ans.begin()) << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
