#ifndef C_ARC
#define C_ARC 0

class CArc {

private :

	// Attributes
	unsigned int uiARCVertexNumber;

	/************************************
	*** Default constructor           ***
	*** Set the value of the arc at 0 ***
	*** Can't be used by users        ***
	************************************/
	CArc ();

public :

	/***********************
	*** Copy constructor ***
	***********************/
	CArc (CArc &ARCParam);
	/******************************************************
	*** Constructor setting the arc's destination value ***
	*** E : uiParam the value                           ***
	******************************************************/
	CArc (unsigned int uiParam);

	/*********************************
	*** Destructor - Nothing to do ***
	*********************************/
	~CArc() {}

	/***************************************
	*** Get the arc's destination        ***
	*** R : The value of the destination ***
	***************************************/
	unsigned int ARCgetVertexNumber();
};

#endif