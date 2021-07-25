#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int ch_count, ans;
string ch;
set <string> st;

void in()
{
     ifstream cin ("E.in");
     cin >>ch_count;
     for (int i=0; i<ch_count; i++)
     {
         cin >>ch;
         st.insert(ch);
     }
}

void solution()
{
     ans = (st.size());
}

void out()
{
     ofstream cout ("E.out");
     /*cout <<ch_count <<"\n";
     for (int i=0; i<ch_count; i++)
     {
         cout <<mass[i] <<" ";
     }  */
     cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
}
