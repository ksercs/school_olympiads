#include <iostream>
//#include <fstream>

using namespace std;

long long n, nk, ans = 1, nzn;

long long mass[] = {0, 0, 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000, 9000000000, 90000000000, 1};

void in()
{
    cin >> n;
}


int kolvo(long long ch)
{
    int kol=0;
    while (ch > 0)
    {
        ch = ch/10;
        kol++;
    }
    return kol;
}

long long st(int n)
{
    long long ch = 1;
    for (int j = 1; j <= n; j++)
    {
     ch *= 10;
    }
    return ch;
}

void solution()
{
    //cout << nk << "\n";
    nk = kolvo(n);
    for (int i = 2; i < nk; i++)
    {
        ans += mass[i]*i;
        //cout << ans << endl;
    }
    if (n >= 10) ans += ( (n-st(nk-1)) /10 +1) * nk;
   // cout << ans << endl;
    //cout << nzn << endl;
    if (n%10 != 0 && n != 1) ans += nk;
    /*if (nk <= 2)
    {
        for (int i = 1; i<= n; i++)
            if (i % 10 == 0) ans+=2;
    }
    else
    {
        for (int i = 2; i < nk; i++)
        {
            ans += (9*i*st(i-2));
        }
        ans+=(((n - st(nk-1))/10)*nk);
        if (n == st(nk-1)) ans += nk;
    }
    if (n%10 != 0) ans+=nk;*/

}

void out()
{
    //ofstream cout("A.out");
    /*long long ch = 1;
    for (int i = 2; i <= 13; i++)
    {
        cout << 9*ch << ", ";
        ch *=10;
    }*/
    //cout << st(n) << "\n";
   /* cout << ((n - st(nk-1))/10)*nk << "\n";
    cout << ans << "\n";*/
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
