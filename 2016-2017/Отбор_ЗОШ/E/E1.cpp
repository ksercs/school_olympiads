#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

#define SZ size()

using namespace std;

int B;
char mass[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

char answer='0';

map <char, int> ans;

void convert(int number, int base)
{
    set <char> st;
    set <char>:: iterator it;
    if (number == 0) st.insert('0');
    else{
    while(number != 0)
    {
        int remainder = number % base;
        number /= base;
        if(remainder <= 9) st.insert(remainder + '0');
        else st.insert((remainder - 10) + 'A');
    }
    }
    for (it = st.begin(); it != st.end(); it++ )
    {
        ans[(*it)]++;
    }
}


void in()
{
    ifstream cin("e.in");
    cin >> B;
    int a;
    while (cin >> a)
    {
        //cout << a << endl;
        //for (int i = 0; i < 16; i++)
        //{
            convert(a,B);
        //}
    }
}

void solution()
{
   int ch = 0;
   for (int i = 0; i < 16; i++)
   {
       //cout << mass[i] << " " << ans[mass[i]] << endl;
       if ( ans[mass[i]] > ch ) {ch = ans[mass[i]]; answer = mass[i];}
   }
}

void out()
{
    ofstream cout("e.out");
    cout << answer << endl;
   /*for (int i = 0; i <= 32767; i++)
    {
        cout << "{";
        for (int j = 2; j <= 16; j++)
        {
            cout << "{";
            vector <char> v = convert(i, j);
            if (v.SZ == 16){
            for (int i = 0; i < v.SZ-1; i++)
            {
                cout <<"'" << v[i] << "',";
            }
            cout << "'" << v[v.SZ-1] << "'}";
            }
            else
            {
               for (int i = 0; i < v.SZ; i++)
                {
                    cout <<"'" << v[i] << "',";
                }
                for (int i = v.SZ; i < 15; i++)
                {
                    cout << "'',";
                }
                cout << "''}";
            }
            if (j != 16) cout << ",";
        }
        cout << "},";
    }*/
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
