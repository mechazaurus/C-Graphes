#include "CArc.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main() {

	CArc ARCone(1);

	CArc ARCtwo(ARCone);

	cout << ARCone.ARCgetVertexNumber() << endl;
	cout << ARCtwo.ARCgetVertexNumber() << endl;

	getchar();
}

