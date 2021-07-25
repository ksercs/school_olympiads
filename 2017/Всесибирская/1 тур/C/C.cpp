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

using namespace std;

const LD EPS = 1E-6;

struct pt {
	LD x, y;

	bool operator< (const pt & p) const {
		return x < p.x-EPS || abs(x-p.x) < EPS && y < p.y - EPS;
	}
};

int t;
VEC < VEC < pt > > d;
VEC <int> ans;

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
    cin >> t;
    ans.resize(t);
    d.resize(t);
    for (int i = 0; i < t; ++i){
        int n;
        cin >> n;
        //cout << n << "\n\n";
        d[i].resize(n);
        if (n == 1){
            //cout << n << "\n";
            pt koor[4];
            for (int j = 0; j < 4; ++j)
                cin >> koor[j].x >> koor[j].y;
            ans[i] = -1;
            //cout << "NED\n";
            continue;
        }
        //cout << n <<": \n";
        for (int k = 0; k < n; ++k){
            //cout << k << "\n";
            pt koor[4];
            for (int j = 0; j < 4; ++j){
                cin >> koor[j].x >> koor[j].y;
                koor[j].x +=(int)1e4;
                koor[j].y +=(int)1e4;
                //cout << koor[j].x << " " <<koor[j].y << "\n";
            }
            //cout << " : ";
            pt L, R;
           // cout << "mSEFHU\n";
            intersect(koor[0], koor[2], koor[1], koor[3], L, R);
           // cout << "InTER\n";
            d[i][k] = L;
            cout << L.x << " " << L.y << "\n\n";
        }
    }
}

void solution()
{
    for (int i = 0; i < t; ++i){
        if (ans[i] == -1) continue;
        int fl = 1;
        for (int j = 0; j < d[i].SZ-1; ++j){
            pt P1 = d[i][j], P2 = d[i][j+1];
            if (!(P1.x >= P2.x-EPS && P1.x <= P2.x+EPS)) fl = 0;
        }
        if (fl) {ans[i] = -1; break;}
        fl = 1;
        if (d[i].SZ > 2)
            for (int j = 0; j < d[i].SZ-2; ++j){
                line f(d[i][j], d[i][j+1]);
                line s(d[i][j+1], d[i][j+2]);
                if (f.a != s.a || f.b != s.b || f.c != s.c) {fl = 0; break;}
            }
       ans[i] = fl;
    }
}

void out()
{
    ofstream cout("output.txt");
    for (int i = 0; i < t; ++i){
        if (ans[i] == -1) cout <<"Infinity\n";
        else              cout << ans[i] << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
