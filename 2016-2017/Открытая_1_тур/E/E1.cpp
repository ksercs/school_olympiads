#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <string.h>

#define SZ size()
#define VEC vector
#define PB push_back
#define MP make_pair
#define SS second
#define FF first
#define PII pair <int,int>
#define LL long long

using namespace std;

int d[1000][1000];
int msize;
string s1, s2, answer, ss1, ss2;

string LCS(string str1, string str2)
{
    string ans;
    ans.clear();
    if (str2.SZ > str1.SZ) swap(str1, str2);
    str1 = ' '+str1;
    str2 = ' '+str2;
    //cout << str1 << " "  << str2 << "\n";
    int n = (int)str1.SZ-1, m = (int)str2.SZ-1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            //cout << i << " " << j << ": " << str1[i] << " " <<str2[j] << "\n";
            str1[i]==str2[j] ? d[i][j]=d[i-1][j-1]+1 : d[i][j]= max(d[i-1][j], d[i][j-1]);
        }
    }
    int i = n, j = m;
    while (i > 0 && j > 0 && d[i][j] != 0){
        //cout << i << " " << j << "\n";
        while (d[i][j-1] == d[i][j] && j > 0) j--;
        while (d[i-1][j] == d[i][j] && i > 0) i--;
        ans += str1[i];
        //cout << str1[i] << " ";
        i--; j--;
    }
    //cout << "\n";
  /*  for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j ++)
            cout << d[i][j] << " ";
        cout << "\n";
    }*/
    //cout << ans << "\n";
    if (ans.SZ > 0) reverse(ans.begin(), ans.end());
    //cout << ans << "\n";
    return ans;
}

string get_max_PSP(string answer)
{
    string ans1;
    ans1.clear();
    int OP = 0, C = 0;
    for (int i = 0; i < answer.SZ; i++){
        if (answer[i] == '(') {OP++; ans1 += '(';}
        if (answer[i] == ')'){
            if (OP > 0){
                OP--;
                ans1 += ')';
            }
        }
    }
    //cout << ans1 << "\n";
    if (OP != 0) while (ans1.SZ > 0 && ans1[ans1.SZ-1] == '(') {ans1.erase(ans1.SZ-1,1); OP--;}
    if (OP != 0){
        OP = 0;
        C = 0;
        int k = ans1.SZ-1;
        while (k >= 0){
            if (ans1[k] == ')') C++;
            if (ans1[k] == '('){
                if (C > 0) C--;
                else       {ans1.erase(k, 1);}
            }
            k--;
        }
    }
    return ans1;
    //cout << ans1 << "\n";
}

string make_PSP(string s)
{
    int i = 0;
    //cout << s.SZ << " " << s << "\n"; system("PAUSE");
    while (true)
    {
        //cout << s << "\n";
       // cout << i << ": " << s[i] << " " << s[i+1] << "\n";
        if (s[i] == '(' && s[i+1] == ')') {s.erase(i, 2); i--;}
        else    i++;
        if (s.SZ == msize) break;
    }
    //cout << s << "\n";
    return s;
}

void in()
{
    ifstream cin("input.txt");
    cin >>s1 >> s2;
}

void solution()
{
    if (s1 == " " || s2 == " ") return;
    while (s1.SZ > 0 && s1[0] == ')') s1.erase(0,1);
    while (s1.SZ > 0 && s1[s1.SZ-1] == '(') s1.erase(s1.SZ-1,1);
    while (s2.SZ > 0 && s2[0] == ')') s2.erase(0,1);
    while (s2.SZ > 0 && s2[s2.SZ-1] == '(') s2.erase(s2.SZ-1,1);
    if (s1 == " " || s2 == " ") return;
    ss1 = s2;
    ss2 = s2;
    //answer = LCS(s1, s2);
    //while (answer.SZ > 0 && answer[0] == ')') answer.erase(0,1);
    //while (answer.SZ > 0 && answer[answer.SZ-1] == '(') answer.erase(answer.SZ-1,1);
    //if (answer.SZ > 0) get_max_PSP();
    s1=get_max_PSP(s1);
    s2=get_max_PSP(s2);
    msize = min(s1.SZ, s2.SZ);
    if (s1.SZ > s2.SZ) s1=make_PSP(s1);
    else               s2=make_PSP(s2);
    cout << s1 << " " << s2 << "\n";
}

void out()
{
    ofstream cout("output.txt");
    if (LCS(s1, ss2) == s1) cout << s1 << "\n";
    else                    cout << s2 << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
