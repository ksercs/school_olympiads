#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

const int MAX_n = 10000;

int n, ferz, x, y, ans, ch1, ch2;
int matrix[MAX_n+2][MAX_n+2];

void in()
{
    ifstream cin ("A.in");
    cin >>n >>ferz;
    for (int i=0; i<ferz; i++)
    {
        cin >>x >>y;
        for (int i=0; i<n; i++)
        {
                matrix[x-1][i]=1;
                matrix[i][y-1]=1;
                matix[i][y+ch2]=1
                ch2+=1;
        }
        matix[i][y+ch2]=1
                ch2+=1;
    }
}

void solution()
{
      for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (matrix[i][j]!=1) {ans+=1;}
            }
        }
}

void out()
{
     ofstream cout ("A.out");
     cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
