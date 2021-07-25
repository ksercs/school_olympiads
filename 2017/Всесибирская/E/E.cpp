#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long
#define LD long double
#define PDD pair <LD, LD>

using namespace std;

const int MAXN = 55;
const LD EPS = 1E-6;

int n, answer=1;
PDD ans;
map < PDD, set < pair < int,int > > > mp;
map < PDD, set < pair < int,int > > >:: iterator it;
set < PDD > st;
set < PDD >:: iterator it1;

struct pt {
	LD x, y;

	bool operator< (const pt & p) const {
		return x < p.x-EPS || abs(x-p.x) < EPS && y < p.y - EPS;
	}
};

pt p[MAXN];

struct line {
	LD a, b, c;

	line() {}
	line (pt p, pt q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = - a * p.x - b * p.y;
		norm();
	}

	void norm() {
		LD z = sqrt (a*a + b*b);
		if (abs(z) > EPS)
			a /= z,  b /= z,  c /= z;
	}

	LD dist (pt p) const {
		return a * p.x + b * p.y + c;
	}
};

#define det(a,b,c,d)  (a*d-b*c)

inline bool betw (LD l, LD r, LD x) {
	return min(l,r) <= x + EPS && x <= max(l,r) + EPS;
}

inline bool intersect_1d (LD a, LD b, LD c, LD d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max (a, c) < min (b, d) + EPS;
}

bool intersect (pt a, pt b, pt c, pt d, pt & left, pt & right) {
	if (! intersect_1d (a.x, b.x, c.x, d.x) || ! intersect_1d (a.y, b.y, c.y, d.y))
		return false;
	line m (a, b);
	line n (c, d);
	LD zn = det (m.a, m.b, n.a, n.b);
	if (abs (zn) < EPS) {
		if (abs (m.dist (c)) > EPS || abs (n.dist (a)) > EPS)
			return false;
		if (b < a)  swap (a, b);
		if (d < c)  swap (c, d);
		left = max (a, c);
		right = min (b, d);
		return true;
	}
	else {
		left.x = right.x = - det (m.c, m.b, n.c, n.b) / zn;
		left.y = right.y = - det (m.a, m.c, n.a, n.c) / zn;
		return betw (a.x, b.x, left.x)
			&& betw (a.y, b.y, left.y)
			&& betw (c.x, d.x, left.x)
			&& betw (c.y, d.y, left.y);
	}
}

void in()
{
    ifstream cin("input.txt");
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> p[i].x >> p[i].y;
        st.insert(MP(p[i].x, p[i].y));
    }
}

void solution()
{
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++){
            if ( (abs(i-j)==1) || (abs(i-j)==n-1) ) continue;
            for (int k = i+1; k < n; k++)
                for (int c = k+1; c <= n; c++){
                    //cout << p[i].x << " " <<  p[i].y << " " << p[j].x << " " <<  p[j].y << " " << p[k].x << " " <<  p[k].y << " " << p[c].x << " " << p[c].y << "\n";
                    if ( (abs(k-c)==1) || abs(k-c)==n-1 || j == c || k == j) continue;
                    pt left, right;
                    if (!intersect (p[i], p[j], p[k], p[c], left, right)) continue;
                    LD L, R;
                    L = left.x+0.0000000;
                    R = left.y+0.0000000;
                    PDD pa;
                    pa = MP(L, R);
                    if (mp.SZ != 0){
                      it = mp.lower_bound(pa);
                      int ch=0;
                      if (it == mp.end()) {ch = 1; it--;}
                      PDD par = it->FF;
                      if ( L > par.FF-EPS && L < par.FF+EPS && R > par.SS-EPS && R < par.SS+EPS) {pa = par;}// cout << pa.FF << " " << pa.SS << "\n";}
                      if (it != mp.begin() && !ch){
                            it--;
                            par = it->FF;
                            if ( L > par.FF-EPS && L < par.FF+EPS && R > par.SS-EPS && R < par.SS+EPS) {pa = par;}
                      }
                    }
                    mp[pa].insert(MP(i,j));
                    mp[pa].insert(MP(k,c));
                    if (mp[pa].SZ > answer){
                        answer = mp[pa].SZ;
                        ans = pa;
                    }
                }
        }
}

void out()
{
    ofstream cout("output.txt");
    cout << answer << "\n";
    cout.precision(12);
    cout << fixed  << ans.FF << " " << ans.SS << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
