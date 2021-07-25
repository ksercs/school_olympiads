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

using namespace std;

LL ans, ind, ls, rs;
string L, R, S;

/*bool check(LL num)
{
    string ch="";
    while(num > 0){
        ch = char(num%10+'0')+ch;
        num /= 10;
    }
    //cout << ch << "\n";
    int d = ( (ch[1]-'0') - (ch[0]-'0') );
    for (int i = 1; i < ch.SZ; ++i)
        if ((ch[i]-'0') != ((ch[i-1]-'0')+d)%10 && (ch[i]-'0') != ((ch[i-1]-'0')+d+10)%10 ) return false;
    return true;
}*/

bool scheck(string ch)
{
    int d = ( (ch[1]-'0') - (ch[0]-'0') );
    for (int i = 1; i < ch.SZ; ++i)
        if ((ch[i]-'0') != ((ch[i-1]-'0')+d)%10 && (ch[i]-'0') != ((ch[i-1]-'0')+d+10)%10 ) return false;
    return true;
}

bool ch_gr3()
{
    if (R[0] != '1') return false;
    for (int i = 1; i < R.SZ; ++i)
        if (R[i] != '0') return false;
    return true;
}

void gr2(LL z)
{
    if (z == 1) ans = 1;
    if (z == 2) ans = 10;
    if (z > 2)  ans = 9+90*(z-2);
}

void pl()
{
    if (ind == -1) S = '1'+S;
    if (S[ind] < '9') S[ind]++;
    else{
        S[ind] = '0';
        ind--;
        pl();
    }
}

void gr1(string sL, string sR)
{
    /*LL Lch=0, Rch=0;
    for (int i = L.SZ-1; i >= 0; --i)
        Lch += int(L[i]-'0')*pow(10, (int)L.SZ-1-i);
    for (int i = R.SZ-1; i >= 0; --i)
        Rch += int(R[i]-'0')*pow(10, (int)R.SZ-1-i);*/
    //cout << Lch << " " << Rch << "\n";
   /*while (Lch <= Rch) {
         if (check(Lch)) ans++;
         //cout << Lch << " " << ans << "\n";
        Lch++;
    }*/
    while (sL != sR) {
         if (scheck(sL)) ans++;
         //cout << Lch << " " << ans << "\n";
         ind = sL.SZ-1;
         S = sL;
         pl();
         sL = S;
    }
    if (scheck(sL)) ans++;
}

void pr_gr1()
{
    if (rs-ls <= 1) gr1(L,R);
    else{
        LL a = 0;
        gr2(rs);
        a = ans;
        ans = 0;
        gr2(ls);
        a -= ans;
        ans = 0;
        string nL = L, nR = R;
        L.clear();
        L +='1';
        for (int i = 0; i < ls-1; ++i)
            L += '0';
        R.clear();
        R += '!';
        for (int i = 0; i < rs-1; ++i)
            R += '0';
        gr1(L, nL);
        a -= ans;
        ans = 0;
        gr1(R, nR);
        a += ans;
        ans = a;
    }
}

void in()
{
    ifstream cin("arithnumbers.in");
    cin >> L >> R;
}

void solution()
{
    ls = L.SZ;
    rs = R.SZ;
    if (L == "1" && ch_gr3()) gr2(rs);
    else                      pr_gr1();
}

void out()
{
    ofstream cout("arithnumbers.out");
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
