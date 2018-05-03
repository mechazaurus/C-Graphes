#ifndef C_GRAPH
#define C_GRAPH 8

#include "CVertex.h"
#include "CFileReader.h"
#include <vector>

using namespace std;

class CGraph {

private :

	// Attributes
	vector<CVertex*> vGRAVertices;

public :

	// Constructors
	CGraph();
	CGraph(CGraph &GRAParam);
	CGraph(CFileReader FIRParam);
	~CGraph();

	// Methods
	void GRAaddVertex(); // Check if the vertex is not already in the graph
	void GRAremoveVertex(unsigned int uiParam);
};

#endif