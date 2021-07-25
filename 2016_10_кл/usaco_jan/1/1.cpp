#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int a, ans;
long long sum;
vector <int> vec;

int mass[50000+15];

int main()
{
    ifstream cin("angry.in");
    ofstream cout("angry.out");
    while (!cin.eof())
    {
        cin >> a;
        vec.push_back(a);
    }
    vec.erase(vec.begin()+vec.size()-1);
    /*for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }*/
    for (int i = 0; i <= 50000; i++)
    {
        sum+=i;
        mass[i] = sum;
    }
    while(mass[ans]<vec.size())
    {
        ans++;
    }
    cout << ans << ".0\n";
    return 0;
}
