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

	CFileReader fileReader("C:\\Users\\Irteza\\Desktop\\graphe.txt");

	try {
		fileReader.FIRImportFromFile();
	} catch (CException EXCError) {
		EXCError.EXCDisplay();
	}

	CGraph *graphe = new CGraph(fileReader);

	graphe->GRAdisplayGraph();

	cout << endl;
	cout << endl;
	cout << "Reversed graph :" << endl;
	graphe->GRAReverseGraph();
	graphe->GRAdisplayGraph();

	delete(graphe);

	getchar();

	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
}
