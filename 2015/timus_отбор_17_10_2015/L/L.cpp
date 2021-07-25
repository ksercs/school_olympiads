#include<iostream>
//#include<fstream>
#include<string>
#include<map>

using namespace std;

const int max_n=100,
          min_n=1,
          max_name=30,
          min_name=1,
          max_problems=13;
const char pr[max_problems+1]={'A','B','C','D','E','F','G','H','I','J','K','L','M'};//ABCDEFGHIJKLM
const string chertochka="+------------------------------+--------+-------------+",
             ogl="|Contest name                  |Date    |ABCDEFGHIJKLM|";

int n,
    p[max_n+3],
    s[max_n+3];
string names[max_n+3],
       date[max_n+3];
map <char,string> problems[max_n];
map <string,char> ans_pr;

void in()
{
    //ifstream cin("input.txt");
    cin >>n;
    string trash;
    getline(cin, trash);
    for(int c=0; c<n; c++)
    {
        getline(cin, names[c]);
        getline(cin, date[c]);
        cin >>p[c] >>s[c];getline(cin, trash);
        for(int v=0; v<s[c]; v++)
        {
            char z;
            cin >>z;
            string nw;
            getline(cin, nw);
            if(problems[c][z]!=" Accepted"){problems[c][z]=nw;}
        }

    }
}

void out()
{
    /*
    for(int c=0; c<n; c++)
    {
        cout <<names[c] <<"\n" <<date[c] <<"\n" <<p[c] <<" " <<s[c] <<"\n";
        for(int v=0;v<14;v++)
        cout <<pr[v] <<problems[c][pr[v]] <<"\n";
    }
    */
    cout <<chertochka <<"\n" <<ogl <<"\n";
    for(int c=0;c<n;c++)
    {
        cout <<chertochka <<"\n";
        cout <<'|' <<names[c];
        int g=max_name-names[c].size();
        for(int i=0; i<g; i++){cout <<' ';}
        cout <<'|' <<date[c]  <<'|';
        for(int i=0; i<p[c]; i++)
        {
            cout <<ans_pr[problems[c][pr[i]]];
        }
        g=max_problems-p[c];
        for(int i=0; i<g; i++){cout <<' ';}
        cout <<"|\n";
    }
    cout <<chertochka <<"\n";
}

int main()
{
    ans_pr[""]='.';
    ans_pr[" Accepted"]='o';
    ans_pr[" Wrong Answer"]='x';
    ans_pr[" Runtime Error"]='x';
    ans_pr[" Time Limit Exceeded"]='x';
    ans_pr[" Memory Limit Exceeded"]='x';
    ans_pr[" Compilation Error"]='x';
    in();
    out();
    return 0;
}
