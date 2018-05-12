#ifndef C_GRAPH
#define C_GRAPH 8

#include "CVertex.h"
#include "CFileReader.h"
#include <vector>

#define C_GRAPH_VERTEX_ALREADY_EXISTS 1600
#define C_GRAPH_VERTEX_NOT_IN_VECTOR 1601

using namespace std;

class CGraph {

private :

	// Attributes
	vector<CVertex*> vGRAVertices;

public :

	/**************************
	*** Default constructor ***
	*** Does nothing        ***
	**************************/
	CGraph() {}

	/***********************
	*** Copy constructor ***
	***********************/
	CGraph(CGraph &GRAParam);

	/**********************
	 *** BIG PART TO DO ***
	 *********************/
	CGraph(CFileReader FIRParam);

	/****************************************************
	*** Destructor - Free the vertices (and the arcs) ***
	****************************************************/
	~CGraph();



	// Manipulations of vertices vector

	/******************************************
	*** Get the size of the vertices vector ***
	*** R : the size of the vector          ***
	******************************************/
	unsigned int GRAgetVerticesVectorSize();

	/****************************************
	*** Add a vertex to the vertices list ***
	*** E : VERParam the vertex to add    ***
	****************************************/
	void GRAaddVertex(CVertex *VERParam);

	/*******************************************
	*** Delete a vertex from vertices vector ***
	*** E : The arc to delete                ***
	*******************************************/
	void GRAdeleteVertex(CVertex *VERParam);



	// Other methods

	/************************
	*** Display the graph ***
	************************/
	void GRAdisplayGraph();
};

#endif