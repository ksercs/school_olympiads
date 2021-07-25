#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

string str,s1,s2;

int df, ln, fl=1;

int mass[1000];

set <char> st;
set <char>:: iterator it;

void in()
{
    ifstream cin("locker.in");
    cin >> str;
}

void solution()
{
   ln = str.size();
   s1 = str.substr(0, ln/2);
   s2 = str.substr(ln/2+ln%2, ln/2);
  // cout << s1 << " " << s2 << "\n";
  //st.insert(str[ln/2+(ln%2)]);
   for (int i = 0;  i < s1.size(); i++)
   {
       if (s1[i] != s2[s2.size()-i-1]) {df++; st.insert(s1[i]); st.insert(s2[s2.size()-i-1]); mass[s1[i]-'0']++; mass[s2[s2.size()-i-1]-'0']++;}
   }
   if (ln%2) mass[str[ln/2]-'0'] = -1;
  /*  for (it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " "; system("PAUSE");
    }*/
    for (it = st.begin(); it != st.end(); it++)
    {
        if (mass[*it-'0']%2 != 0) fl = 0;
        if (mass[*it-'0'] == -1) {fl = 1; break;}
    }
}

void out()
{
    ofstream cout("locker.out");
   // cout << df << " " <<st.size() << " " << ms.size() << "\n";
    if (df <= 2 && st.size() <= 2 && fl ) cout <<"YES\n";
    else cout << "NO\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
