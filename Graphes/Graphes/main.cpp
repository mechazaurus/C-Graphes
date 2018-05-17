/*#include "CArc.h"
#include "CException.h"
#include "CFileReader.h"
#include "CGraph.h"
#include "CVertex.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {

	vector<CGraph> GRAGraphs;

	for (int iLoop = 1 ; iLoop < argc ; iLoop++) {
		
		string path = argv[iLoop];

		CFileReader FIRfileReader(path);

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
	/*
	for (int iLoop1 = 0 ; iLoop1 < argc - 1 ; iLoop1++) {
		// Delete tous les sommets de tous les graphes
	}*/
/*
	return 0;
}*/