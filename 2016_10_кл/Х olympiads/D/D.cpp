#include <iostream>
#include <set>

using namespace std;

int n, m;

set <int> st;

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
      for(int g = 0; g < m; g++)
      {
          int a;
          cin >> a;
          st.insert(a);
      }
  }
  cout << n*m-st.size()+1 << "\n";
  return 0;
}
