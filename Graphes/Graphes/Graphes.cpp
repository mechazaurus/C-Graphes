#include "CArc.h"
#include "CException.h"
#include "CFileReader.h"
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

	CFileReader fileReader("C:\\Users\\Boop\\source\\repos\\C-Graphes\\Graphes\\Debug\\graphe.txt");

	try {
		fileReader.FIRImportFromFile();
	} catch (CException EXCError) {
		EXCError.EXCDisplay();
	}

	CGraph *graphe = new CGraph(fileReader);

	graphe->GRAdisplayGraph();

	for (unsigned int uiLoop = 0 ; uiLoop < graphe->GRAgetVerticesVectorSize() ; uiLoop++) {
		if (graphe->GRAGetVertexAtIndex(uiLoop)->VERgetVertexNumber() == 1) {
			graphe->GRAFullyDeleteVertex(graphe->GRAGetVertexAtIndex(uiLoop));
		}
	}

	cout << endl;
	cout << endl;

	graphe->GRAdisplayGraph();
	
	delete(graphe);

	getchar();

	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
}
