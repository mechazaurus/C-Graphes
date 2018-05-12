#include "CArc.h"
#include "CException.h"
#include "CGraph.h"
#include "CVertex.h"

/***********************
*** Copy constructor ***
***********************/
CGraph :: CGraph(CGraph &GRAParam) {
	vGRAVertices = GRAParam.vGRAVertices;
}

/*********************
*** BIG PART TO DO ***
*********************/
CGraph :: CGraph(CFileReader FIRParam) {

	for (unsigned int uiLoop = 0 ; uiLoop < FIRParam.FIRgetVerticesNumber() ; uiLoop++) {
		vGRAVertices.push_back(new CVertex(FIRParam.FIRgetVertexValueAt(uiLoop)));
	}

	for (unsigned int uiLoop1 = 0 ; uiLoop1 < FIRParam.FIRgetArcsNumber() * 2 ; uiLoop1+=2) {

		for (unsigned int uiLoop2 = 0; uiLoop2 < FIRParam.FIRgetVerticesNumber(); uiLoop2++) {
			if (FIRParam.FIRgetArcValueAt(uiLoop1) == vGRAVertices[uiLoop2]->VERgetVertexNumber()) {
				vGRAVertices[uiLoop2]->VERaddOutcomingArc(new CArc(FIRParam.FIRgetArcValueAt(uiLoop1 + 1)));
			}
		}

		for (unsigned int uiLoop3 = 0; uiLoop3 < FIRParam.FIRgetVerticesNumber(); uiLoop3++) {
			if (FIRParam.FIRgetArcValueAt(uiLoop1 + 1) == vGRAVertices[uiLoop3]->VERgetVertexNumber()) {
				vGRAVertices[uiLoop3]->VERaddIncomingArc(new CArc(FIRParam.FIRgetArcValueAt(uiLoop1)));
			}
		}
	}
}

/****************************************************
*** Destructor - Free the vertices (and the arcs) ***
****************************************************/
CGraph :: ~CGraph() {

	unsigned int uiVectorSize = vGRAVertices.size();

	for (unsigned int uiLoop = 0 ; uiLoop < uiVectorSize ; uiLoop++) {
		delete(vGRAVertices[uiLoop]);
	}
}



// Manipulations of vertices vector

/******************************************
*** Get the size of the vertices vector ***
*** R : the size of the vector          ***
******************************************/
unsigned int CGraph :: GRAgetVerticesVectorSize() {
	return vGRAVertices.size();
}

/****************************************
*** Add a vertex to the vertices list ***
*** E : VERParam the vertex to add    ***
****************************************/
void CGraph :: GRAaddVertex(CVertex *VERParam) {

	unsigned int uiVectorSize = vGRAVertices.size();

	for (unsigned int uiLoop = 0 ; uiLoop < uiVectorSize ; uiLoop++) {
		if (VERParam->VERgetVertexNumber() == vGRAVertices[uiLoop]->VERgetVertexNumber()) {
			throw CException(C_GRAPH_VERTEX_ALREADY_EXISTS, "Le sommet existe deja dans le graphe.");
		}
	}

	vGRAVertices.push_back(VERParam);
}

/*******************************************
*** Delete a vertex from vertices vector ***
*** E : The arc to delete                ***
*******************************************/
void CGraph :: GRAdeleteVertex(CVertex *VERParam) {

	unsigned int uiVectorSize = vGRAVertices.size();

	for (unsigned int uiLoop = 0 ; uiLoop < uiVectorSize ; uiLoop++) {
		if (VERParam->VERgetVertexNumber() == vGRAVertices[uiLoop]->VERgetVertexNumber()) {
			vGRAVertices.erase(vGRAVertices.begin() + uiLoop);
			delete(VERParam);
		}
	}

	if (uiVectorSize == vGRAVertices.size()) {
		throw CException(C_GRAPH_VERTEX_NOT_IN_VECTOR, "Le sommet n'est pas present dans le graphe.");
	}
}



// Other methods

/************************
*** Display the graph ***
************************/
void CGraph :: GRAdisplayGraph() {

	cout << "Composition du graphe :" << endl;
	cout << endl;

	unsigned int uiVectorSize = vGRAVertices.size();

	for (unsigned int uiLoop = 0 ; uiLoop < uiVectorSize ; uiLoop++) {
		vGRAVertices[uiLoop]->VERdisplayVertex();
	}
}