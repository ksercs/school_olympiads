#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 10;

string n, num;
int ans, lvl, bal, ch;
//int used[MAX_SIZE];

vector <vector <int> > gr;

int s_cmp(string s1, string s2)
{
    if (s1.size() > s2.size()) return 1;
    if (s1.size() == s2.size())
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] > s2[i]) return 1;
            if (s1[i] < s2[i]) return 0;
        }
    }
    return 0;
}

void make_graph()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int g = i; g <= 9; g++)
        {
            gr[i].push_back(g);
        }
    }
}

int DFS (int v)
{
    num += (v+'0');
    if (s_cmp(num, n)) return 0;
    if (v+'0' > n[bal] && bal == ch+1) {ch=0; return 0;}
    ch++;
    bal++;
    cout << num << "\n"; //system("PAUSE");
    int answer = 1;
    for (int i = 0; i < gr[v].size(); i++)
    {
       answer+= DFS(gr[v][i]); num.erase(num.size()-1,1);
    }
    bal--;
    return answer;
}


/*int DFS(long long ch, int m_z)
{
    int answer = 1;
    if(ch > n)return 0;
    cout << ch << "\n";
    for(int g = 0; g < gr[m_z].size(); g++)
    {
        int next_m_z = gr[m_z][g];
        long long n_ch = ch * 10;
        answer += DFS(n_ch + next_m_z, next_m_z);
    }
    return answer;
}*/

void in()
{
    ifstream cin ("D.in");
    cin >> n;
}

void solution()
{
    lvl = n.size();
    gr.resize(10);
    make_graph();
    /*for (int i = 1; i <= 9; i++)
    {
        cout <<i << ": ";
        for (int g = 0; g < gr[i].size(); g++)
        {
            cout << gr[i][g] << " ";
        }
        cout << "\n";
    }*/
    for(int i = 1; i <= 9; i++)
    {
        //ans += DFS(1LL*i, i);
        ans += DFS(i);
        num = "";
    }
    system("PAUSE");
    /*for (int i = 1; i <= 9; i++)
    {
        num= i;
        if (num > n) break;
        cout << num << "\n";
        ans++; num*=10;
        for (int g = i; g <= 9; g++)
        {
            num+=g;
            if (num > n) break;
            cout << num << "\n";
            ans++; num*=10;
            for (int j = g; j <= 9; j++)
            {
                num+=j;
                if (num > n) break;
                cout << num << "\n";
                ans++; num*=10;
                for (int h = j; h <=9; h++)
                {
                    num+=h;
                    if (num > n) break;
                    cout << num << "\n";
                    ans++; num*=10;
                    for (int f = h; f <=9; f++)
                    {
                        if (num+f > n) break;
                        cout << num << "\n";
                        ans++;
                    }
                    num/=10; num-=h;
                }
                num/=10; num-=j;
            }
            num/=10; num-=g;
        }
    }*/
}

void out()
{
     ofstream cout ("D.out");
     cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
