#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int inf = (int)1e9;

int n, minVal, maxVal;
vector <int> num;

multiset < int > Smini;
multiset < int > Smaxi;

int get_min(multiset < int > &S, int x)
{
	int ans = 0;
	while(!S.empty())
	{
		multiset < int > :: iterator it = --S.end();
		int valMax = *it;
		//cout << "valMax= " <<valMax <<"\n";
		S.erase(it);
		int need = x - valMax;
		//cout <<"need= " <<need <<"\n";
		it = S.upper_bound(need);
		if ( it == S.begin() )
		{
			S.erase(--S.end());
			ans++;
		}
		else
		{
          //cout << *it << " ";
		  it--;
		 // cout <<*it << "\n";
		  S.erase(it);
		}
	}
	return ans;
}

int get_max(multiset < int > &S, int x)
{
    int ans = 0;
	while (!S.empty())
	{
		multiset < int > :: iterator it = S.begin();
		int valMin = *it;
		S.erase(it);
		int need = x - valMin;
		it = S.upper_bound(need);
		if ( it == S.end() )
		{
			S.erase(S.begin());
		}
		else
		{
            S.erase(it);
            ans++;
		}
	}
	return ans;
}

void in()
{
    ifstream cin("E.in");
    cin >> n;
    for(int i = 0; i < 2*n; i++)
    {
        int a;
        cin >> a;
        num.push_back(a);
    }
}

void solution()
{
	minVal = inf, maxVal = -inf;
	for (int i = 1; i < 2*n; i++)
	{
		Smini.insert(num[i]);
		Smaxi.insert(num[i]);
		minVal = min(minVal, num[i]);
		maxVal = max(maxVal, num[i]);
	}
	Smini.erase(Smini.find(minVal));
	Smaxi.erase(Smaxi.find(maxVal));

	/*multiset < int > :: iterator it;
	for (it = Smaxi.begin(); it != Smaxi.end(); it++)
	{
	    cout <<*it << " ";
	}
	cout << "\n";
    for (it = Smini.begin(); it != Smini.end(); it++)
	{
	    cout <<*it << " ";
	}
	cout << "\n";*/
}

void out()
{
    ofstream cout("E.out");
    if (n==1) cout <<"1 1\n";
    else      cout << get_min(Smaxi, num[0] + maxVal)+1 <<" " << get_max(Smini, num[0] + minVal)+1 <<"\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
