#include <iostream>
#include <algorithm>

using namespace std;

const int ch1 = 1234567, ch2 = 123456, ch3 = 1234;

int n, fl, ab_c, ab;

/*void check(int a, int b, int c)
{
    ab = a*10+b;
    ab_c = a*1000+b*100+c;
    if (1234*ab_c+56*ab+7*a == n) fl = 1;
}*/

int main()
{
    cin >> n;
    int del1 = n/ch1;
    for (int i = del1; i >= 0; i--)
    {
        int nc = n - i*ch1;
        if (nc == 0 || fl) {fl = 1; break;}
        int del2 = nc/ch2;
        for (int j = del2; j >= 0; j--)
        {
            int nnc = nc - j*ch2;
            if (nnc == 0 || fl) {fl = 1; break;}
            int del3 = nnc/ch3;
            for (int k = del3; k > 0; k--)
            {
                int nnnc = nnc - k*ch3;
                if (nnnc == 0 || fl) {fl = 1; break;}
            }
        }
    }
    /*for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                check(i, j, k);
            }
        }
    }*/
    if (fl) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
