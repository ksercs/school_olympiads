#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

#define vec vector
#define pb push_back
#define rsz resize
#define SZ size()

using namespace std;

struct point
{
    double x, y;
};

struct vect
{
    double x, y;
};

struct segment
{
    point a, b;
};

double Dot(vect V1, vect V2)
{
    return V1.x * V2.x + V1.y * V2.y;
}

double get_Length(vect V)
{
    return sqrt( pow(V.x, 2) + pow(V.y, 2) );
}

vect norm(vect V)
{
    double len = get_Length(V);
    V.x /= len;
    V.y /= len;
    return V;
}

vect Reflect(vect P, segment S)
{
    vect pr;
    vect N;
    N.x = S.a.y - S.b.y;
    N.y = S.b.x - S.a.x;
    vect n = norm(N);
    double dot2 = 2*Dot(n, P);
    pr.x = P.x - dot2*n.x;
    pr.y = P.y - dot2*n.y;
    return pr;
}

vect make_vect( segment sg)
{
    vect v;
    v.x = sg.b.x - sg.a.x;
    v.y = sg.b.y - sg.a.y;
    return v;
}

double Cross(vect V1, vect V2)
{
    return V1.x * V2.y - V1.y * V2.x;
}

struct polygon
{
    vec <point> p;
};

int n, st;
vec < double > ans;
double Lcross;

segment SEG;
point pst;
vect stan, Lvect;
vec < vect > room, rf;
vec <segment> segm;

double get_S_Pol(polygon Pol)
{
    double answer;
    for (int i = 0; i < Pol.p.SZ-1; i++)
    {
        double ax = Pol.p[i].x;
        double ay = Pol.p[i].y;
        double bx = Pol.p[i+1].x;
        double by = Pol.p[i+1].y;
        answer += ax*by - ay*bx;
    }
    int index  = Pol.p.SZ;
        double ax = Pol.p[index].x;
        double ay = Pol.p[index].y;
        double bx = Pol.p[0].x;
        double by = Pol.p[0].y;
        answer += ax*by - ay*bx;
    return answer;
}

point make_p(vect v)
{
    point P;
    P.x = v.x;
    P.y = v.y;
    return P;
}

void in()
{
    ifstream cin ("mirror.in");
    cin >> n;
    room.rsz(n);
    rf.rsz(n);
    ans.rsz(n);
    segm.rsz(n);
    for (int i = 0; i < n; i++)
    {
        cin >> room[i].x >> room[i].y;
    }
    cin >> stan.x >> stan.y;
    segment SG;
    SG.a = make_p(room[n-1]);
    SG.b = make_p(room[0]);
    segm.pb(SG);
    room.pb(room[0]);
}

segment intrs(vect V, int L, int R)
{
    while (R - L > 1)
    {
        cout << L << " " << R << endl;
        int M = L + (R-L)/2;
        SEG.b = make_p(room[M]);
        double Cr = Cross(V, make_vect(SEG));
        if (Cr*Lcross <= 0) L = M;
        else               R = M;
    }
    segment SEGM;
    SEGM.a = make_p(room[L]);
    SEGM.b = make_p(room[L+1]);
    cout << L << ":  "<< room[L].x << " " << room[L].y << "    " << room[L+1].x << " " << room[L+1].y << endl << endl;
    return SEGM;
}

point get_intrs(segment S)
{
    vect Vc = make_vect(S);
    Lcross = Cross(Vc, Lvect);
    segment SG = intrs(Vc, st, (int)(room.SZ)-2);
    polygon BPol, LPol;
    BPol.p.pb(pst);
    BPol.p.pb(SG.a);
    BPol.p.pb(SG.b);
    double BS = get_S_Pol(BPol);
    LPol.p.pb(pst);
    LPol.p.pb(SG.a);
    LPol.p.pb(S.b);
    LPol.p.pb(SG.b);
    double LS = get_S_Pol(LPol);
    double k = BS/LS;
    vect SEG = make_vect(SG);
    SEG.x *= k;
    SEG.y *= k;
    point PP;
    PP.x = SEG.x;
    PP.y = SEG.y;
    return PP;
}
double solve(point p1, point p2)
{
    point ver1, ver2;
    segment SG;
    SG.a = pst;
    SG.b = p1;
    ver1 = get_intrs(SG);
    SG.b = p2;
    ver2 = get_intrs(SG);
    polygon POL;
    POL.p.pb(p1);
    POL.p.pb(p2);
    POL.p.pb(ver2);
    POL.p.pb(ver1);
    return get_S_Pol(POL);
}

segment obr(segment S)
{
    point tmp = S.a;
    S.a = S.b;
    S.b = tmp;
    return S;
}

void solution()
{
    for (int i = 0; i < n; i++)
    {
        segment SG;
        SG.a = make_p(room[i]);
        SG.b = make_p(room[i+1]);
        segm[i] = SG;
        rf[i] = Reflect(stan, SG);
    }
    for (int i = 0; i < n; i++)
    {
        st++;
        pst = make_p(rf[i]);
        SEG.a = pst;
        Lvect = make_vect(obr(segm[segm.SZ-1]));
        ans[i] = solve(make_p(room[i]), make_p(room[i+1]));
        room.pb(room[i]);
        segm.pb(segm[i]);
    }
}

void out()
{
     ofstream cout ("mirror.out");
     for (int i = 0; i < n; i++)
     {
         cout << fixed << setprecision(12) << ans[i] << endl;
     }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
