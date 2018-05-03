#ifndef C_VERTEX
#define C_VERTEX 0

#include "CArc.h"
#include <iostream>
#include <vector>

#define C_VERTEX_ARC_ALREADY_EXISTS 1500
#define C_VERTEX_ARC_NOT_IN_VECTOR 1501
#define C_VERTEX_ITSELF 1502

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
	/**********************************************
	*** Constructor setting the vertex's number ***
	*** E : uiParam the value                   ***
	**********************************************/
	CVertex(unsigned int uiParam);

	/*********************************
	*** Destructor - Nothing to do ***
	*********************************/
	~CVertex() {}

	/***************************************
	*** Get the vertex's number          ***
	*** R : The vertex's number          ***
	***************************************/
	unsigned int VERgetVertexNumber();



	// Manipulations of incoming arcs

	/************************************************
	 *** Get the size of the incoming arcs vector ***
	 *** R : the size of the vector               ***
	 ***********************************************/
	unsigned int VERgetIncomingVectorSize();

	/***********************************************************************
	*** Get the arc's destination value from the vector at the position ***
	*** E : uiIndex the position                                        ***
	**********************************************************************/
	unsigned int VERgetIncomingArcDestination(unsigned int uiIndex);

	/**********************************************
	 *** Add an arc to the incoming arcs vector ***
	 *** E : ARCParam the arc to add            ***
	 *********************************************/
	void VERaddIncomingArc(CArc *ARCParam);

	/***************************************************
	 *** Delete an arc from the incoming arcs vector ***
	 *** E : The arc to delete                       ***
	 **************************************************/
	void VERdeleteIncomingArc(CArc *ARCParam);



	// Manipulations of outcoming arcs

	/************************************************
	*** Get the size of the outcoming arcs vector ***
	*** R : the size of the vector                ***
	************************************************/
	unsigned int VERgetOutcomingVectorSize();

	/*******************************************************************************
	*** Get the arc's destination value from the incoming vector at the position ***
	*** E : uiIndex the position                                                 ***
	*******************************************************************************/
	unsigned int VERgetOutcomingArcDestination(unsigned int uiIndex);

	/**********************************************
	*** Add an arc to the outcoming arcs vector ***
	*** E : ARCParam the arc to add             ***
	**********************************************/
	void VERaddOutcomingArc(CArc *ARCParam);

	/***************************************************
	*** Delete an arc from the outcoming arcs vector ***
	*** E : The arc to delete                        ***
	***************************************************/
	void VERdeleteOutcomingArc(CArc *ARCParam);



	// Other methods
	void VERdisplayVertex();
};

#endif