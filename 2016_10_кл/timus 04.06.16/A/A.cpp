#include <iostream>
#include <vector>

using namespace std;

#define pb push_back

int min_ans, max_ans, pl;

vector <int> mass;

void in()
{
  for (int i = 1; i <= 10; i++)
  {
      int a;
      cin >> a;
      mass.pb(a);
  }
}

void solution()
{
  for (int i = 0; i < 7; i++)
  {
      int ch = mass[i], next_ch = mass[i+1];
      min_ans += ch;
      max_ans += ch;
      if (ch == 10)
      {
          if (next_ch == 10)  max_ans += next_ch + mass[i+2];
          else                  max_ans += next_ch;
      }
  }
    min_ans += mass[7];
    max_ans += mass[7];
  if (mass[7] == 10)
  {
      max_ans += mass[8];
      pl = 1;
  }
  if (mass[8] != 10)
  {
      min_ans += mass[8]; max_ans += mass[8];
      int ch = mass[9];
      if (ch <= 10)
      {
          min_ans += ch;
          max_ans += ch;
      }
      if (ch <= 20 && ch > 10)
      {
          min_ans += ch;
          max_ans += ch;
      }
      if (ch > 20)
      {
          min_ans += ch;
          max_ans += ch;
      }
  }
  else
  {
      min_ans += 10; max_ans += 10;
      int ch = mass[9];
      if (ch <= 10)
      {
          min_ans += ch;
          max_ans += 2*ch + ch*pl;
      }
      if (ch <= 20 && ch > 10)
      {
          min_ans += ch;
          max_ans += 2*ch + 10*pl;
      }
      if (ch > 20)
      {
          min_ans += ch + 10;
          max_ans += ch + 10*pl + 20;
      }
  }
}

void out()
{
  cout << min_ans << " " << max_ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
