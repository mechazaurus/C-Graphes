#ifndef C_VERTEX
#define C_VERTEX 8

#include "CArc.h"
#include <vector>

using namespace std;

class CVertex {

private :

	// Attributes
	unsigned int uiVERNumber;
	vector<CArc *> vVERIncomingArcs;
	vector<CArc *> vVEROutcomingArcs;

public :

	// Constructors
	CVertex();
	CVertex(CVertex &VERParam);
	~CVertex();

	// Methods
};

#endif