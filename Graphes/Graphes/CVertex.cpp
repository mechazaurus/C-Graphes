#include "CVertex.h"

/***************************************
*** Default constructor              ***
*** Set the value of the vertex at 0 ***
*** Can't be used by users           ***
***************************************/
CVertex :: CVertex() {

	uiVERNumber = 0;
}

/***********************
*** Copy constructor ***
***********************/
CVertex :: CVertex(CVertex &VERParam) {

	uiVERNumber = VERParam.uiVERNumber;
	vVERIncomingArcs = VERParam.vVERIncomingArcs;
	vVEROutcomingArcs = VERParam.vVEROutcomingArcs;
}

unsigned int CVertex::VERgetVertexNumber() {

	return uiVERNumber;
}