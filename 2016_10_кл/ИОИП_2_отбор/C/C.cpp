#include <iostream>
#include <fstream>

using namespace std;

long long st, fn;
int Lgr, Rgr;
long long L[20], R[20], ans[20];

long long ekv_L(long long s, int gr)
{
    if (gr == 1) return s;
    /*if (s <= 9) return s;
    s-=R[gr-1];
    int s2 = s;
    s/=gr;
    if (s2%gr!=0) s++;
    return ekv_L(R[gr-1], gr-1)+ekv_L(s, gr-1);*/
    return ans[gr-1]+(s-R[gr-1])/gr+((s-R[gr-1])%gr>0)+1;
}

long long ekv_R(long long f, int gr)
{
    if (gr == 1) return f;
    /*
    if (f <= 9) return f;
    f-=R[gr-1];
    f/=gr;
    return ekv_L(R[gr-1], gr-1)+ekv_R(f, gr-1);*/
    return ans[gr-1]+(f-R[gr-1])/gr;
}

void in()
{
    ifstream cin("encryption.in");
    cin >> st >> fn;
}

void solution()
{
    L[1] = 1;
    R[1] = 9;
    ans[1] = 9;
    long long pl = 9;
    for (int i = 2; i <= 18; i++)
    {
        pl*=10;
        L[i] = R[i-1]+1;
        R[i] = pl*i+R[i-1];
        ans[i] = pl+ans[i-1];
        //cout <<i <<": " << L[i] << " " <<R[i] << "\n";
    }
    for (int i = 1; i <= 18; i++)
    {
        if (st >= L[i] && st <= R[i]) {Lgr = i; break;}
    }
    for (int i = 1; i <= 18; i++)
    {
        if (fn >= L[i] && fn <= R[i]) {Rgr = i; break;}
    }
}

void out()
{
    ofstream cout("encryption.out");
    //cout << ekv_R(fn, Rgr) << " " << ekv_L(st, Lgr) <<  "\n";
    cout << ekv_R(fn, Rgr)-ekv_L(st, Lgr)+1 << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
