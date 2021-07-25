#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int a, ans, s;
pair <int, int> m, n;
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
    s = vec.size()/2-1;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size()/2-1; i++)
    {
        if (vec[i+1]-vec[i] >= m.first) m = make_pair(vec[i+1]-vec[i], i);
    }
    for (int i = vec.size()/2-1; i < vec.size()-1; i++)
    {
        if (vec[i+1]-vec[i] >= n.first) n = make_pair(vec[i+1]-vec[i], i);
    }
    if (m.first > n.first) cout << m.first+abs(s-m.second) << ".0\n";
    else cout << n.first+abs(s-n.second) << ".0\n";
    return 0;
}
