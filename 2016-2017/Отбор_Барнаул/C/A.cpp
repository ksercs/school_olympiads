#include <iostream>
#include <fstream>

#define LL long long

using namespace std;

int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

int main() {

    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);

//	ifstream fin("a.in");
//	ofstream fout("a.out");
	int n, cur_gcd, p, sum;
//	fin >> n;
//	fin >> cur_gcd;
	cin >> n;
	cin >> cur_gcd;
	sum = cur_gcd;
	for (int i = 1; i < n; i++) {
		cin >> p;
//		fin >> p;
		cur_gcd = gcd(cur_gcd, p);
		sum += p;
	}
//	fout << cur_gcd << endl << sum / cur_gcd;
	cout << cur_gcd << endl << sum / cur_gcd;
	return 0;
}
