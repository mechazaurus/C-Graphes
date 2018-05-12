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
		throw CException(C_GRAPH_VERTEX_NOT_IN_VECTOR, "Le sommet n'est pas présent dans le graphe.");
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