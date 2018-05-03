#include "CArc.h"
#include "CException.h"
#include "CVertex.h"
#include <cstdio>
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CArc *ARCone = new CArc(3);
	CArc *ARCtwo = new CArc(4);
	CArc *ARCthree = new CArc(5);
	CVertex *VERone = new CVertex(1);

	try {
		VERone->VERaddIncomingArc(ARCone);
		VERone->VERaddIncomingArc(ARCtwo);
		VERone->VERaddOutcomingArc(ARCthree);
	} catch (CException EXCError) {
		EXCError.EXCDisplay();
	}

	VERone->VERdisplayVertex();
	cout << endl;

	try {
		VERone->VERdeleteIncomingArc(ARCtwo);
	} catch (CException EXCError) {
		EXCError.EXCDisplay();
	}

	VERone->VERdisplayVertex();

	delete(VERone);

	getchar();

	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
}

