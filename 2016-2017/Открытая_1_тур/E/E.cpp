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

const int BRACKET_COUNT = 1;

vector <char> cm;
char op[5] = {'(', '[', '{'};
int cl[5] = {')', ']', '}'};
int d[1000][1000];

string s1, s2, answer, ans, ans1;

bool check(string s)
{
    cm.clear();
    int fl=0, ind=0;
    for (int i = 0; i < s.size(); i++)
    {
            ind = -1;
            for (int j = 0; j < BRACKET_COUNT; j++)
              if (s[i] == cl[j])
                ind = j;
            if (ind == -1)
              cm.push_back(s[i]);
            else
              if (!cm.empty() && cm.back() == op[ind])
                cm.pop_back();
              else{
                fl = 1; break;}
    }
    return ((!fl && cm.SZ==0));
}

string LCS(string str1, string str2)
{
   // ans.clear();
   // memset(d, 0, sizeof(d));
    if (str2.SZ > str1.SZ) swap(str1, str2);
    str1 = ' '+str1;
    str2 = ' '+str2;
    //cout << str1 << " "  << str2 << "\n";
    int n = (int)str1.SZ-1, m = (int)str2.SZ-1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            str1[i]==str2[j] ? d[i][j]=d[i-1][j-1]+1 : d[i][j]= max(d[i-1][j], d[i][j-1]);
        }
    }
    int i = n, j = m;
    while (i > 0 && j > 0){
        //cout << i << " " << j << "\n";
        while (d[i][j-1] == d[i][j] && j > 0) j--;
        while (d[i-1][j] == d[i][j] && i > 0) i--;
        ans += str1[i];
        i--; j--;
    }
    //cout << ans << "\n";
    if (ans.SZ > 0) reverse(ans.begin(), ans.end());
}

void get_max_PSP()
{
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
    //cout << ans1 << "\n";
}

void in()
{
    ifstream cin("input.txt");
    cin >>s1 >> s2;
}

void solution()
{
    if (s1 == " " || s2 == " ") {ans1 = " "; return;}
    LCS(s1, s2);
    answer = ans;
    while (answer.SZ > 0 && answer[0] == ')') answer.erase(0,1);
    while (answer.SZ > 0 && answer[answer.SZ-1] == '(') answer.erase(answer.SZ-1,1);
    //cout << answer << " " << check(answer) << "\n";
    /*while(!check(answer) && answer.SZ > 2){
        answer.erase(0,1);
        answer.erase(answer.SZ-1, 1);
        LCS(s1, answer);
        answer = ans;
        while (answer.SZ > 0 && answer[0] == ')') answer.erase(0,1);
        while (answer.SZ > 0 && answer[answer.SZ-1] == '(') answer.erase(answer.SZ-1,1);
    }
    if (answer.SZ == 2 && !check(answer)) answer=" ";*/
    if (answer.SZ > 0) get_max_PSP();
    else               ans1 = " ";
}

void out()
{
    ofstream cout("output.txt");
    cout << ans1 << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
