#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int mass[1000000 + 5];

void solution()
{
    for (int i = 2; i <= 100000; i++)
    {
        if (mass[i] == 0)
        {
            for (int g = i+i; g <= 100000; g+=i)
            {
                mass[g] = 1;
            }
        }
    }
}

void out()
{
     ofstream cout ("erat.out");
     int ch;
     for (int i = 2; i <= 100000; i++)
     {
         if (mass[i] == 0) {cout << i << ", "; ch++;}
     }
     cout << "\n" << ch << "\n";
}

int main()
{
    solution();
    out();
return 0;
}
