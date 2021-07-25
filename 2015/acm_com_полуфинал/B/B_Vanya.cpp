#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

string str;
vector < int > mn;
int answer;

void in()
{
    ifstream cin("secret.in");
    cin >> str;
}


string Bi_prov(string s, int p)
{
    if(p == 0)return s;
    if( p % 2 == 0)
    {
        string pros = Bi_prov(s, p / 2);
        return ( pros + pros );
    }
    else
    {
        string pros = Bi_prov(s, p / 2 );
        return ( Bi_prov(s, p / 2) + Bi_prov(s, 0) );
    }
}


void solution()
{

    int n = str.size();
    for( int c = 2; c * c <= n ; c++)
    {
        if(n % c == 0)
        {
            mn.push_back(c);
        }
    }
    if(n != 1)mn.push_back(n);
    for( int c = mn.size() - 1; c >= 0; c-- )
    {
        string sb = str.substr(0, mn[c]);
        string nw = "";
        nw = Bi_prov(sb, str.size() / mn[c]);
        if(nw == str)answer++;
    }

}

void out()
{
    ofstream cout("secret.out");
    cout << answer << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
