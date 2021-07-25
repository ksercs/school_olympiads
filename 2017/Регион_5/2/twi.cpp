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

const string S = "http://";

int len, n, rez;
string str, sq;
map <string, string> ss;
VEC <string> v;
VEC <string> ans;

bool check(string s)
{
    //cout <<sq << "\n"  << s << " " << s.SZ <<"\n";
    if (s.SZ <= 7 || s.substr(0,7) != S) return false;
    for (int i = 0; i < s.SZ; ++i)
        if (! (s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z' || s[i] == '/' || s[i] =='.' || s[i] == ':' /*|| s[i] == ','*/) ) return false;
    return true;
}

void in()
{
    ifstream cin("twi.in");
    cin >> n;
    //cin >> sq;
    //cout << sq << "\n";
    //getline(cin, sq);
    getline(cin, sq);
    getline(cin, sq);
    len = sq.SZ;
    //cout  << "'" << sq << "'\n";
    //cout << sq << "\n";
    int ind = 0, last = 0;
    string st = "";
    /*while (sq[ind]==' '){
        last++;
        ind++;
    }
    if (last != 0) ans.PB(sq.substr(0, last));*/
    string sss = "";
    char smb;
    while (cin >> smb)
        sss += smb;
    while (sq[ind]!=' ' && ind < len){
        st += sq[ind];
        ind++;
        last++;
    }
    if (check(st)) v.PB(st);
    ans.PB(st);
    //cout << "FIRST = " << st << "\n";
    while (ind < len){
        st = "";
        if (sq[ind] != ' ' && sq[ind-1] == ' '){
                ans.PB(sq.substr(last, ind-last));
                //cout << "PROB = '" << sq.substr(last, ind-last).SZ << "'\n" ;
                while (sq[ind]!=' ' && ind != len){
                    st += sq[ind];
                    ind++;
                    last = ind;
                }
        }
        //cout << "ST = '" << st << "'\n";
        if (check(st)) {/*cout << "CH = " << st << "\n";*/ v.PB(st);}
        //len += str.SZ+1;
        ans.PB(st);
        ind++;
    }
    if (sq[sq.SZ-1] == ' ') ans.PB(sq.substr(last, ind-last));
    //len--;
    if (sss.SZ != 0) ans.PB(sss);
}

void solution()
{
    /*for (int i = 0; i < v.SZ; ++i)
        cout << v[i] << " ";
    cout << "\n\n\n";
    for (int i = 0; i < ans.SZ; ++i)
        cout << ans[i];
    cout << "\n";*/
    rez = len;
    //cout << len << "\n";
    for (int i = 0; i < v.SZ; ++i){
        //cout << rez << "\n";
        if (rez <= n) break;
        string s = v[i];
        //cout << s << "\n";
        if (s.SZ > rez-n+3){
            string old_s = s;
            int need = rez-n+3;
            s.erase(s.SZ-need, need);
            s += "...";
            rez -= need;
            rez += 3;
            ss[old_s] = s;
           // cout << s << "\n";
        }
        else{
            rez -= s.SZ;
            rez += 3;
            ss[s] = "...";
        }
    }
}

void out()
{
    ofstream cout("twi.out");
    //cout << len << "\n";
    for (int i = 0; i < ans.SZ-1; ++i)
         ss[ans[i]].SZ != 0 ? cout << ss[ans[i]] : cout << ans[i];
    int i = ans.SZ-1;
    ss[ans[i]].SZ != 0 ? cout << ss[ans[i]] << "\n" : cout << ans[i] << "\n";
    //cout << "\gfnbgfn";
    cout << max(rez-n,0) << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
