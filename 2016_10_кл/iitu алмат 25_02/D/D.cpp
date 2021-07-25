#include <iostream>
#include <fstream>

using namespace std;

int year, fl, sum, d, m;

int day[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 3, 4},
    month[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3},
    dim[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void get_ans(int ind)
{
    int m_day = dim[ind];
    if (m_day == 28)
    {
        if (year%4==0) m_day++;
    }
    for (int g = m_day; g >= 1; g--)
    {
        int s = month[ind]+day[g];
        if (s == sum) {fl = 1; m = ind; d = g; break;}
    }
}

int main()
{
    ifstream cin("D.in");
    ofstream cout("D.out");
    cin >> year;
    int ch = year;
    while(ch > 0)
    {
        sum+=ch%10;
        ch/=10;
    }
    for (int i = 12; i >= 1; i--)
    {
        get_ans(i);
        if (fl) break;
    }
    cout <<d <<"." <<m <<"." <<year <<"\n";
}
