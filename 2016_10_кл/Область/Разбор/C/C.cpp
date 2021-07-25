#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, ind, ans;
string str;

vector <pair <string, int> > cm;
vector <string> v1;
vector <int> v2, answer;

int l_bin(int L, int R, int x, int z)
{
    while(R-L > 1)
    {
        int m = L+(R-L)/2;
        if (v1[m][z] >= str[x+z]) R = m;
        else L = m;
    }
    if (v1[L][z] == str[x+z]) return L;
    return R;
}
int r_bin(int L, int R, int x, int z)
{
    while(R-L > 1)
    {
        int m = L+(R-L)/2;
        if (v1[m].size() < z || v1[m][z] <= str[x+z]) L = m;
        else R = m;
    }
    if (v1[R][z] == str[x+z]) return R;
    return L;
}

void bin_s(int L, int R, int x, int z)
{
    //cout << "LLLL_RRR:  " << L << " " << R << "\n"; system("PAUSE");
    while(R-L > 1)
    {
        L = l_bin(L, R, x, z);
        R = r_bin(L, R, x, z);
       // cout << "Left_Right:  " << L << " " << R << "\n";system("PAUSE");
        if (v1[L] == str.substr(ind, v1[L].size())) ans = L;
        z++;
    }
}

void in()
{
    ifstream cin ("C.in");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int num;
      string c;
      cin >> c >> num;
      cm.push_back(make_pair(c, num));
    }
    cin >> str;
}

void solution()
{
    sort(cm.begin(), cm.end());
    for (int i = 0; i < cm.size(); i++)
    {
        v1.push_back(cm[i].first);
        v2.push_back(cm[i].second);
    }
    while (ind < str.size()-1)
    {
        //cout << ind << "\n"; system("PAUSE");
        bin_s(0, v1.size()-1, ind,0);
        answer.push_back(ans);
        //cout << v2[ans] << "\n";
        ind+=v1[ans].size();
    }
}

void out()
{
     ofstream cout ("C.out");
     for (int i = 0; i < answer.size(); i++)
     {
         cout << v2[answer[i]] << "\n";
     }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
