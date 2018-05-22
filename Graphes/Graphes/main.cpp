#include "CArc.h"
#include "CException.h"
#include "CFileReader.h"
#include "CGraph.h"
#include "CVertex.h"
#include <cstdio>
#include <iostream>

using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main(int argc, char * argv[]) {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	vector<CGraph> GRAGraphs;
	
	for (int iLoop = 1 ; iLoop < argc ; iLoop++) {

		CFileReader FIRfileReader(argv[iLoop]);

		try {
			FIRfileReader.FIRImportFromFile();
		} catch (CException EXCError) {
			EXCError.EXCDisplay();
		}

		GRAGraphs.push_back(CGraph(FIRfileReader));
	}

	for (int iLoop = 0 ; iLoop < argc - 1 ; iLoop++) {
		GRAGraphs[iLoop].GRAdisplayGraph();
	}

	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);

	return 0;
}