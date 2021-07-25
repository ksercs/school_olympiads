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

const int INF = (int)1e6;

int n, m, k, ans;
map <int, VEC <int> > u;
VEC <int> v;

struct comp
{
    bool operator()(const PII& a, const PII& b) const{
        if (a.FF == b.FF) return a.SS > b.SS;
        return a.FF > b.FF;
    };
};

set < PII , comp> st;
set < PII , comp>:: iterator it;

void in()
{
    ifstream cin("B.in");
    cin >> n >> m >> k;
    v.resize(k);
    for (int i = 0; i < k; i++){
        cin >> v[i];
        u[v[i]].PB(i);
        //u[v[i]]++;
        //st.insert(v[i]);
    }
    /*for (it = st.begin(); it != st.end(); it++)
    		cout << (*it) << " " << u[(*it)] << "\n";*/
    /*for (int i = 0; i < k; i++)
    	cout << v[i] << " ";*/
}

void solution()
{
	for (int i = 0; i < k; i++){
		u[v[i]].PB(INF);
	}
    for (int i = 0; i < k; i++){
    	//cout << i << ": \n";
    	it = st.find( MP(u[v[i]][0], v[i]) );
        if (st.SZ > 0 && it != st.end()) {
        	st.erase(it);
        	u[v[i]].erase(u[v[i]].begin());
        	/*if (u[v[i]] > 0)*/ st.insert(MP(u[v[i]][0], v[i]));
			continue;	
        }
        ans++;
        if (st.SZ < m) {u[v[i]].erase(u[v[i]].begin()); st.insert(MP(u[v[i]][0], v[i]));}
	    else{
	        //cout << "BEFORE : ";
	        //for (it = st.begin(); it != st.end(); it++)
	    	//cout << (*it) << " " << u[(*it)] << "\n";
	        st.erase(st.begin());
	        u[v[i]].erase(u[v[i]].begin());
	        st.insert(MP(u[v[i]][0], v[i]));
	        //cout << "AFTER : ";
			//for (it = st.begin(); it != st.end(); it++)
	    	//cout << (*it) << " " << u[(*it)] << "\n";
	    }
        /*cout << i << ": \n";
        for (it = st.begin(); it != st.end(); it++)
    		cout << (*it).FF << " " << (*it).SS << " " << u[(*it).FF] << "\n";*/
    }
}

void out()
{
    ofstream cout("B.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
