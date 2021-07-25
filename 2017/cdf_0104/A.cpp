#include <iostream>
using namespace std;

int main()
{
bool a1, a2, a3 ,a4, k1, k2, k3, k4, k5, f1, f2;
cin >> a1 >> a2 >> a3 >> a4;
k1=a1 ^ a2;
k2=a3 ^ a4;
k3=a4 ^ a1;
f1=a2 && a3;
f2=k1 && k2;
k4=f1 ^ k3;
k5=k4 ^ f2;
cout<< k5<< endl;
return 0;
}
