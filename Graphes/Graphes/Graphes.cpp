#include "CArc.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main() {

	CArc *ARCone = new CArc(1);

	cout << ARCone->ARCgetVertexNumber() << endl;

	delete(ARCone);

	getchar();
}

