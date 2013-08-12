//============================================================================
// Name        : Main.cpp
// Author      : goldolphin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "lang/type/PrimativeType.h"

using namespace std;
using namespace mi;
using namespace mi::lang;

int main() {
	int a =  1;
	static const int b = a+1;
	cout << "Hello, 世界!" << endl;
	cout << b << endl;

	return 0;
}
