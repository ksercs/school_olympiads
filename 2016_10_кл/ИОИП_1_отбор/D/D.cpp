#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 1e5+15;

int n, m;

vector <long long> num;
//vector <int> pos;
vector <long long> ans;

/*int s_cmp(string s1, string s2)
{
    if (s1.size() > s2.size()) return 1;
    if (s1.size() < s2.size()) return 0;
    if (s1.size() == s2.size())
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] > s2[i]) return 1;
            if (s1[i] < s2[i]) return 0;
        }
    }
    return 1;
}*/

long long get_ans(long long c)
{
   /* while(str[0] == '0')
    {
        str.erase(0,1);
    }
    //cout << str << "\n";
    long long a = 0;
    for (int i = 0; i < n; i++)
    {
      //  cout << num[i] << " " << str << " " << s_cmp(num[i], str) <<"\n";
        a+=s_cmp(num[i], str);
    }
    //cout << "\n";
    return a;*/
    int a = (int)(lower_bound(num.begin(), num.end(), c)-num.begin());
    return n-a;
}

long long dfs(string str, int pos, int ch)
{
    //cout << pos << " " <<ch << "\n"; system("PAUSE");
    if (pos == str.size()) {/*cout << "get_ans(ch): " <<get_ans(ch) <<"\n";*/return get_ans(ch);}
    if (str[pos] == '?')
    {
        long long answer = 0;
        for (int i = 0; i <= 9; i++)
        {
            answer+=dfs(str, pos+1, ch*10+i);
        }
        //cout << answer <<": " <<answer <<"\n";
        return answer;
    }
    return dfs(str, pos+1, ch*10+(str[pos]-'0'));
}

void in()
{
    ifstream cin ("queries.in");
    cin >> n >> m;
    num.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
       // cout << s << "\n\n";
        ans.push_back(dfs(s, 0, 0));
        /*for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == '?') pos.push_back(i);
        }
        if (pos.size() == 0) ans.push_back(get_ans(stoi(s)));
        else    {dfs(0, 0, s); ans.push_back(answer);answer = 0;}
        pos.clear();*/
    }
}

void solution()
{
}

void out()
{
     ofstream cout ("queries.out");
     for (int i = 0; i < ans.size(); i++)
     {
         cout << ans[i] << "\n";
     }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
