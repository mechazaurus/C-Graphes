#include "CArc.h"
#include "CException.h"
#include "CVertex.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main() {

	CArc *ARCone = new CArc(3);
	CArc *ARCtwo = new CArc(4);
	CVertex VERone(1);

	try {
		VERone.VERaddIncomingArc(ARCone);
		VERone.VERaddIncomingArc(ARCtwo);
		VERone.VERaddOutcomingArc(ARCtwo);
	} catch (CException EXCError) {
		EXCError.EXCDisplay();
	}

	VERone.VERdisplayVertex();
	cout << endl;

	try {
		VERone.VERdeleteIncomingArc(ARCtwo);
	} catch (CException EXCError) {
		EXCError.EXCDisplay();
	}

	VERone.VERdisplayVertex();

	delete(ARCone);
	delete(ARCtwo);

	getchar();
}

