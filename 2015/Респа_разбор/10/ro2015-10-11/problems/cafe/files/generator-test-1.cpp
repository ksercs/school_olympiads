#include "testlib.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <time.h>

using namespace std;


int main(int argc, char * argv[]) {     
    //assert(freopen("input.txt","r",stdin));
    //assert(freopen("output.txt","w",stdout));

    registerGen(argc, argv, 1);
    
/* 2 3 1
5 2 3
2
3 1 2 3
1 2
1 1
1 1
*/
    
    cout << 2 << " " << 3 << " " << 1 << endl;
    
    cout << 5 << " " << 1 << " " << 3 << endl;
    cout << 2 << endl;

    cout << 3 << " " << 1 << " " << 2 << " " << 3 << endl;
    cout << 1 << " " << 2 << endl;

    cout << 1 << " " << 1 << endl;
    cout << 1 << " " << 1 << endl;
 
    return 0;
}