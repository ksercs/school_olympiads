#include <iostream>
#include <fstream>

using namespace std;

int a, b, ans1=3, ans2=4;

int mass[]={0, 3, 3, 2, 4, 3, 4, 4, 5, 5};

int main()
{
    ifstream cin("A.in");
    ofstream cout("A.out");
    cin >> a >> b;
    ans1+=mass[a];
    ans2+=mass[b];
    if (ans1 == ans2) cout <<"=\n";
    else
    {
        if (ans1 > ans2) cout <<">\n";
        else    cout <<"<";
    }
}
