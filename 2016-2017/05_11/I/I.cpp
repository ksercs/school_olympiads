#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

long long A, B, C, D, ans;
int fl;

long long gcd_R(long long a, long long b)
{
    return ( (a&&b) ? gcd_R(b, a%b) : (a|b)  );
}


void get_ans (long long a, long long b, long long c, long long d)
{
    ans++;
    if (a < b) swap(a,b);
    if (c < d) swap(c,d);
    if (a == b == c == d) {fl = 1; return;}
    if (a <= d || c <= b) return;
    get_ans(a-d, b, c-b, d);
}

void in()
{
    ifstream cin("trick.in");
    cin >> A >> B >> C >> D;
}

void solution()
{
    long long a = A, b = B, c = C, d = D;
    if ( (double)a/d == (double) c/b )
    {
        fl = 1;
        if (a < b) swap(a,b);
        if (c < d) swap(c,d);
        long long g = gcd_R(a, d);
        ans = a/gcd_R(a, d) + c/gcd_R(b, c);
    }
    /*else
    while(1)
    {
        ans++;
        if (a < b) swap(a,b);
        if (c < d) swap(c,d);
        if (a == b && b == c && c == d && a == d) {fl = 1; break;}
        if (a <= d || c <= b) break;
        a -= d;
        c -= b;
        //get_ans(a-d, b, c-b, d);
    }*/
    //get_ans(A,B,C,D);
}

void out()
{
    ofstream cout("trick.out");
    if (fl) cout << "YES\n" << ans << endl;
    else    cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
