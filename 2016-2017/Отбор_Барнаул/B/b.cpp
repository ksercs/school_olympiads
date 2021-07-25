#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std ;

#define MAXSIZE 1000002 

int vertexes [ MAXSIZE ];


int main() {

    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);

        int size,  edges;
        cin  >>  size;
        cin  >>  edges;

        for (int i = 1; i <= size; i++) 
            vertexes[i] = 0;



        for (int i = 0; i < edges; i++) {
           int a, b;
           cin >>a;            
           cin >>b;            

            vertexes[a]++;
            vertexes[b]++;
        }
                                               
        int res = 0;
        for (int i = 1; i <= size; i++) {
            res += vertexes[i] % 2;
        }

        cout << (res / 2) << endl;

        return 0;
}
