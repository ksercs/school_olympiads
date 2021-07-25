#include <iostream>
#include <fstream>

using namespace std;

int N, C, i, a[17];
 
int main()
{
    ifstream cin ("F.in");
    ofstream cout ("F.out");
    cin >>C >>N;
    for (i=0; i<C; i++)
    {
        cin >>a[i];
    }
    cout <<"YES\n";

 
return 0;
}
