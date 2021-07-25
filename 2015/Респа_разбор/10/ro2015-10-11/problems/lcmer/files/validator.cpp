#include "testlib.h"
#include <iostream>
#include <set>
#include <cassert>

using namespace std;

int main()
{
	registerValidation();

	int n = inf.readInt(1, 100, "n");
	inf.readSpace();
	int L = inf.readInt(1, 1000000000, "L");
	inf.readSpace();
	int R = inf.readInt(L, 1000000000, "R");
	inf.readSpace();
	int A = inf.readInt(1, 1000000000, "A");
	inf.readEoln();
	inf.readEof();
	return 0;
}