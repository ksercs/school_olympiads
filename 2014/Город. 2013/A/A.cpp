#include <iostream>
#include <fstream>

using namespace std;

int N, i, sum5=0, f;

int main()
{
    ifstream cin ("A.in");
    ofstream cout ("A.out");
    cin >>N; 
    for ( i=5; i<=N; i=i+5)
    {//cout <<"LOL\n";
          f=i;
        while ( (f%5==0) && (f!=0) ) {sum5=sum5+1; f=f/5; /*cout <<"RRRRR\n";*/}
    }
cout <<sum5 <<"\n";
return 0;
}
