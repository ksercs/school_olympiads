#include <fstream>
#include <vector>

using namespace std;

int main() 
{
	ifstream cin("queue.in");
	ofstream cout("queue.out");
    int n, m, T;
	cin >> n >> m >> T;

    vector <int> a(n);
	pair <long long, int> ans = make_pair(0, 0);
    for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
		ans.first += (long long) a[i];
    }
    for (int i = 0; i < m; i++) 
	{
		int t;
		cin >> t;
		if ((n & 1) && t <= T)
		{
			++ans.second;
		}
    }

    if (n & 1) 
	{
		ans.first -= (long long) a[0];
    } 
	cout << ans.first << ' ' << ans.second;
    return 0;
}