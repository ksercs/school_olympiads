#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

#define LL long long
#define PB push_back
#define SZ size()

using namespace std;

int T, L, K, ans;
int u[2*1000000];
LL ch;

map <LL, int> mp;
vector <LL> V, B;

int BS(int L, int R, LL X)
{
    //cout << L << " " << R << " " << X << endl;
    while(R-L > 1)
    {
        int M = (R+L)/2;
        if (B[M] == X) {L = M; break;}
        if (B[M] < X ) L = M;
        if (B[M] > X ) R = M-1;
    }
    if (B[R] <= X) return R;
    return L;
}

void get_ans(int Left, int Right, LL num)
{
       int ind = BS(Left, Right, num);
       //cout << ind << endl;
       if (ind != 0)
       {
           if (mp[B[ind]] != 0)
           {
               ch -= B[ind];
               mp[B[ind]]--;
           }
           else //get_ans(Left, ind-1, num);
           for (int i = ind-1; i >= 1; i -- )
           {
               if (mp[B[i]] > 0)
               {
                    ch -= B[i];
                    mp[B[i]]--;
                    break;
               }
           }
       }
       else return;
}

void in()
{
    ifstream cin("input.txt");
    cin >> T >> L;
    V.resize(T+1);
    for (int i = 1; i <= T; i++)
    {
        cin >> V[i];
    }
    cin >> K;
    //B.resize(K+1);
    B.PB(0);
    for (int i = 1; i <= K; i++)
    {
        LL a;
        cin >> a;
        if (u[a] == 0)
        {
            u[a] = 1;
            B.PB(a);
        }
        //cin >> B[i];
        mp[a]++;
    }
}

void solution()
{
   sort(B.begin(), B.end());
   for (int i = 1; i <= T; i++)
   {
       ch += V[i];
       get_ans(0, (int)(B.SZ-1), ch);
       if (ch > L) {ans = -1; break;}
   }
}

void out()
{
    ofstream cout("output.txt");
    if (ans == -1) cout << "No solution\n";
    else           cout << ch << endl;
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
