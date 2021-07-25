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
    
    /* 
1 2 2
5 5
5 5
2 1 2
2 1 2
*/

	cout << 1 << " " << 2 << " " << 2 << endl;
	cout << 5 << " " << 5 << endl;
	cout << 5 << " " << 5 << endl;

	cout << 2 << " " << 1 << " " << 2 << endl;
	cout << 2 << " " << 1 << " " << 2 << endl;
 
    return 0;
}