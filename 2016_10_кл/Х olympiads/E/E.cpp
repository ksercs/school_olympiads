#include <iostream>

using namespace std;

long long s, l1, r1, l2, r2, t1, t2;

pair <int, pair <long long, long long> > intersection(pair <long long, long long> pi1, pair <long long, long long> pi2)
{
    if (pi1.first > pi1.second) {swap(pi1.first, pi1.second);}
    if (pi2.first > pi2.second) {swap(pi2.first, pi2.second);}
    if (pi1.first > pi2.first)  {swap(pi1.first, pi2.first); swap(pi1.second, pi2.second);}
    if (pi1.second < pi2.first) {return make_pair(0, make_pair(0, 0) );}
    else                        {return make_pair(1, make_pair(pi2.first, min(pi1.second, pi2.second) ) );}
}

int main()
{
    cin >> s >> l1 >> r1 >> l2 >> r2;
    t1 = s-r1;
    t2 = s-l1;
    pair <int, pair <long long, long long> > ans = intersection(make_pair(t1,t2), make_pair(l2,r2));
    if (!ans.first) {cout << "0\n";}
    else {cout <<ans.second.second - ans.second.first + 1 << "\n";}
    return 0;
}
