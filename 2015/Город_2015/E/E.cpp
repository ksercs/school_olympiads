#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <string>
#include <set>
#include <map>
#include <stack>

using namespace std;

string ch;
string ans[]={"ADD", "MUL"};

stack <string> st;

void f()
{
  while (ch[ch.size()-1] != '0')
  {
      st.push(ans[0]);
      ch[ch.size()-1]--;
  }
  st.push(ans[1]);
  ch.erase(ch.size()-1, 1);
  if (ch.size() > 0) {f();}
}

void in()
{
  ifstream cin("E.in");
  cin >> ch;
}

void solution()
{
  f();
  st.pop();
}

void out()
{
  ofstream cout("E.out");
  while (!st.empty())
  {
      cout << st.top() << "\n";
      st.pop();
  }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
