#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int n;

multiset <long long> ms;
multiset <long long>:: iterator it1, it2;

void in()
{
    ifstream cin ("maxnumber.in");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        ms.insert(a);
    }
}

void solution()
{
    while(ms.size() != 1)
    {
        it2 = ms.begin();
        it1 = it2++;
        if (*(it1) != *(it2)) ms.erase(ms.begin());
        else
        {
           long long ch = 2*(*ms.begin());
           ms.erase(ms.begin());
           ms.erase(ms.begin());
           ms.insert(ch);
        }
    }
}

void out()
{
     ofstream cout ("maxnumber.out");
     cout << *(ms.begin()) << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
