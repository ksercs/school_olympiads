/**
 * Validator
 */

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

using namespace std;

const int MAXN = 500;
const int MAX_REL = 2000;

int n, m, k;
int totalRel;

int main()
{
    registerValidation();
    
    int n = inf.readInt(1, MAXN, "n");
    inf.readSpace();

    int m = inf.readInt(1, MAXN, "m");
    inf.readSpace();

    int k = inf.readInt(1, MAXN, "k");
    inf.readEoln();

    for (int i = 0; i < m; i++) {
        int x = inf.readInt(1, MAXN, format("c[%d]", i + 1));
        
        if (i + 1 < m)
            inf.readSpace();
    }
    inf.readEoln();


    for (int i = 0; i < k; i++) {
        int x = inf.readInt(1, MAXN, format("p[%d]", i + 1));
        
        if (i + 1 < k)
            inf.readSpace();
    }
    inf.readEoln();

    for (int i = 0; i < n; i++) {
        int num = inf.readInt(0, MAX_REL, format("c_num[%d]", i + 1));
        totalRel += num;

        ensuref(totalRel <= MAX_REL, "Too many relations");

        set <int> st;

        for (int j = 0; j < num; j++) {
            inf.readSpace();
            int x = inf.readInt(1, m, format("Coffee #%d of person %d", j + 1, i + 1));
            st.insert(x);
        }
        inf.readEoln();

        ensuref((int) st.size() == num, "Not all coffee types for person %d are distinct", i + 1);
    }

    for (int i = 0; i < n; i++) {
        int num = inf.readInt(0, MAX_REL, format("p_num[%d]", i + 1));
        totalRel += num;

        ensuref(totalRel <= MAX_REL, "Too many relations");

        set <int> st;

        for (int j = 0; j < num; j++) {
            inf.readSpace();
            int x = inf.readInt(1, k, format("Pie #%d of person %d", j + 1, i + 1));
            st.insert(x);
        }
        inf.readEoln();

        ensuref((int) st.size() == num, "Not all pie types for person %d are distinct", i + 1);
    }

    inf.readEof();
    return 0;
}