#include "CException.h"
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
/**********************************************
*** Constructor setting the vertex's number ***
*** E : uiParam the value                   ***
**********************************************/
CVertex :: CVertex(unsigned int uiParam) {
	uiVERNumber = uiParam;
}

/*********************************
*** Destructor - Free the arcs ***
*********************************/
CVertex :: ~CVertex() {
	
	for (unsigned int uiLoop = 0 ; uiLoop < vVERIncomingArcs.size() ; uiLoop++) {
		delete(vVERIncomingArcs[uiLoop]);
	}

	for (unsigned int uiLoop = 0; uiLoop < vVEROutcomingArcs.size(); uiLoop++) {
		delete(vVEROutcomingArcs[uiLoop]);
	}
}

/*******************************
 *** Get the vertex's number ***
 *** R: the vertex's number  ***
 ******************************/
unsigned int CVertex :: VERgetVertexNumber() {
	return uiVERNumber;
}



// Manipulations of incoming arcs

/***********************************************
*** Get the size of the incoming arcs vector ***
*** R : the size of the vector               ***
***********************************************/
unsigned int CVertex :: VERgetIncomingVectorSize() {
	return vVERIncomingArcs.size();
}

/********************************************************************************
 *** Get the arc's destination value from the incoming vector at the position ***
 *** E : uiIndex the position                                                 ***
 *******************************************************************************/
unsigned int CVertex :: VERgetIncomingArcDestination(unsigned int uiIndex) {
	return vVERIncomingArcs[uiIndex]->ARCgetVertexNumber();
}

/*******************************************
*** Add an arc to the incoming arcs list ***
*** E : ARCParam the arc to add          ***
*******************************************/
void CVertex :: VERaddIncomingArc(CArc *ARCParam) {

	if (ARCParam->ARCgetVertexNumber() == uiVERNumber) {
		throw CException(C_VERTEX_ITSELF, "Un sommet ne peut pas pointer vers lui-meme");
	}

	unsigned int iIncomingVectorSize = vVERIncomingArcs.size();

	for (unsigned int uiLoop = 0 ; uiLoop < iIncomingVectorSize ; uiLoop++) {

		if (vVERIncomingArcs[uiLoop]->ARCgetVertexNumber() == ARCParam->ARCgetVertexNumber()) {
			throw CException(C_VERTEX_ARC_ALREADY_EXISTS, "L'arc existe deja dans la liste des arcs entrants");
		}
	}

	vVERIncomingArcs.push_back(ARCParam);
}

/***************************************************
*** Delete an arc from the incoming arcs vector ***
*** E : The arc to delete                       ***
**************************************************/
void CVertex :: VERdeleteIncomingArc(CArc *ARCParam) {

	unsigned int uiEndIndex = vVERIncomingArcs.size();
	vector<CArc *> vTemp;

	for (unsigned int uiLoop = 0; uiLoop < uiEndIndex; uiLoop++) {

		if (vVERIncomingArcs[uiLoop]->ARCgetVertexNumber() != ARCParam->ARCgetVertexNumber()) {
			vTemp.push_back(vVERIncomingArcs[uiLoop]);
		}
	}

	if (vTemp.size() == vVERIncomingArcs.size()) {
		throw CException(C_VERTEX_ARC_NOT_IN_VECTOR, "L'arc n'est pas present dans la liste des arcs entrants");
	}
	else {
		vVERIncomingArcs.swap(vTemp);
	}

	free(ARCParam);
}




// Manipulations of outcoming arcs

/************************************************
*** Get the size of the outcoming arcs vector ***
*** R : the size of the vector                ***
************************************************/
unsigned int CVertex :: VERgetOutcomingVectorSize() {
	return vVEROutcomingArcs.size();
}

/*******************************************************************************
*** Get the arc's destination value from the incoming vector at the position ***
*** E : uiIndex the position                                                 ***
*******************************************************************************/
unsigned int CVertex::VERgetOutcomingArcDestination(unsigned int uiIndex) {
	return vVEROutcomingArcs[uiIndex]->ARCgetVertexNumber();
}

/********************************************
*** Add an arc to the outcoming arcs list ***
*** E : ARCParam the arc to add           ***
********************************************/
void CVertex::VERaddOutcomingArc(CArc *ARCParam) {

	if (ARCParam->ARCgetVertexNumber() == uiVERNumber) {
		throw CException(C_VERTEX_ITSELF, "Un sommet ne peut pas pointer vers lui-meme");
	}

	unsigned int iIncomingVectorSize = vVEROutcomingArcs.size();

	for (unsigned int uiLoop = 0 ; uiLoop < iIncomingVectorSize ; uiLoop++) {
		if (vVEROutcomingArcs[uiLoop]->ARCgetVertexNumber() == ARCParam->ARCgetVertexNumber()) {
			throw CException(C_VERTEX_ARC_ALREADY_EXISTS, "L'arc existe deja dans la liste des arcs sortants");
		}
	}

	vVEROutcomingArcs.push_back(ARCParam);
}

/***************************************************
*** Delete an arc from the outcoming arcs vector ***
*** E : The arc to delete                        ***
***************************************************/
void CVertex::VERdeleteOutcomingArc(CArc *ARCParam) {

	unsigned int uiEndIndex = vVEROutcomingArcs.size();
	vector<CArc *> vTemp;

	for (unsigned int uiLoop = 0; uiLoop < uiEndIndex; uiLoop++) {

		if (vVEROutcomingArcs[uiLoop]->ARCgetVertexNumber() != ARCParam->ARCgetVertexNumber()) {
			vTemp.push_back(vVEROutcomingArcs[uiLoop]);
		}
	}

	if (vTemp.size() == vVEROutcomingArcs.size()) {
		throw CException(C_VERTEX_ARC_NOT_IN_VECTOR, "L'arc n'est pas present dans la liste des arcs sortants");
	} else {
		vVEROutcomingArcs.swap(vTemp);
	}

	free(ARCParam);
}



// Other methods

/*******************************************************
*** Display the vertex's incoming and outcoming arcs ***
*******************************************************/
void CVertex :: VERdisplayVertex() {

	cout << "Sommet numero " << uiVERNumber << endl;
	cout << "Arc(s) entrant(s) : " << endl;

	if (vVERIncomingArcs.size() == 0) {
		cout << "aucun" << endl;
	} else {

		for (unsigned int uiLoop = 0 ; uiLoop < vVERIncomingArcs.size() ; uiLoop++) {
			cout << vVERIncomingArcs[uiLoop]->ARCgetVertexNumber() << "->" << uiVERNumber << endl;
		}

		cout << endl;
	}

	cout << "Arc(s) sortant(s) : " << endl;

	if (vVERIncomingArcs.size() == 0) {
		cout << "aucun" << endl;
	} else {
		
		for (unsigned int uiLoop = 0 ; uiLoop < vVEROutcomingArcs.size() ; uiLoop++) {
			cout << uiVERNumber << "->" << vVEROutcomingArcs[uiLoop]->ARCgetVertexNumber() << endl;
		}

		cout << endl;
	}
}
