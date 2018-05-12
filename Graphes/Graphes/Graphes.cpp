#include "CArc.h"
#include "CException.h"
#include "CGraph.h"
#include "CVertex.h"
#include <cstdio>
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CVertex *VERone = new CVertex(1);
	CVertex *VERtwo = new CVertex(2);
	CGraph *GRAgraph = new CGraph();

	try {
		VERone->VERaddIncomingArc(new CArc(2));
		VERone->VERaddOutcomingArc(new CArc(2));

		VERtwo->VERaddIncomingArc(new CArc(1));
		VERtwo->VERaddOutcomingArc(new CArc(1));
	} catch (CException EXCError) {
		EXCError.EXCDisplay();
	}

	try {
		GRAgraph->GRAaddVertex(VERone);
		GRAgraph->GRAaddVertex(VERtwo);
	} catch (CException EXCError) {
		EXCError.EXCDisplay();
	}

	GRAgraph->GRAdisplayGraph();

	delete(GRAgraph);

	getchar();

	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
}

