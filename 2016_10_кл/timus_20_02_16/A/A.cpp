#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map <string, string> mp[10000000];
map <string, vector <string> > answer;
map <string, vector <string> >:: iterator it;

bool ch = false, fl = false;

string cod, task;

void in()
{
    ifstream cin("a.in");
    while(!cin.eof())
    {
        if (fl) break;
        //cout <<"1\n";
        string team="", str="", s2="", ans="";
        int num=0;
        if (!ch) cin >> cod;
        else cod = task;
        getline(cin, team);
        team.erase(0,1);
        for (int i = 0; i < cod.size(); i++)
        {
            if (cod[i]=='.')
            {
                num++; s2 = str; str.clear();
                if (i != cod.size()-1){
                  if (ans.size()!=0) ans+='.';
                  ans+=mp[num][s2];
                }
                if (i == cod.size()-1) {mp[num][s2] = team; if (ans.size()!=0) ans+='.'; ans+=team;}
            }
            else  str+=cod[i];
        }
        ch = false;
        while (!ch)
        {
            if (cin.eof()) {fl = true; break;}
            //cout <<"2: " << task <<"\n";
            cin >> task;
            if (task[1] == '.' || task[2] =='.') ch = true;
            else     answer[task].push_back(ans);
        }
        if (fl)answer[task].pop_back();
    }
}

void solution()
{

}

void out()
{
    ofstream cout("a.out");
    for (it=answer.begin(); it!=answer.end(); it++)
    {
        cout << it->first << ": ";
        for (int i = 0; i < (it->second).size()-1; i++)
        {
            cout <<(it->second)[i] << ", ";
        }
        cout <<(it->second)[(it->second).size()-1] << "\n";
    }

}

int main()
{
    in();
    solution();
    out();
    return 0;
}
