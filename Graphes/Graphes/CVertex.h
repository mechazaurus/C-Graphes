#ifndef C_VERTEX
#define C_VERTEX 0

#include "CArc.h"
#include <vector>

using namespace std;

class CVertex {

private :

	// Attributes
	unsigned int uiVERNumber;
	vector<CArc *> vVERIncomingArcs;
	vector<CArc *> vVEROutcomingArcs;

	/***************************************
	*** Default constructor              ***
	*** Set the value of the vertex at 0 ***
	*** Can't be used by users           ***
	***************************************/
	CVertex();

public :

	/***********************
	*** Copy constructor ***
	***********************/
	CVertex(CVertex &VERParam);

	/*********************************
	*** Destructor - Nothing to do ***
	*********************************/
	~CVertex() {}

	/***************************************
	*** Get the vertex's number          ***
	*** R : The vertex's value           ***
	***************************************/
	unsigned int VERgetVertexNumber();
};

#endif