#include "CArc.h"

/*************************************
 *** Default constructor           ***
 *** Set the value of the arc at 0 ***
 *** Can't be used by users        ***
 ************************************/
CArc :: CArc() {
	uiARCVertexNumber = 0;
}

/************************
 *** Copy constructor ***
 ***********************/
CArc :: CArc(CArc &ARCParam) {
	uiARCVertexNumber = ARCParam.ARCgetVertexNumber();
}

/*******************************************************
 *** Constructor setting the arc's destination value ***
 *** E : uiParam the value                           ***
 ******************************************************/
CArc :: CArc(unsigned int uiParam) {
	uiARCVertexNumber = uiParam;
}

/****************************************
 *** Get the arc destination          ***
 *** R : The value of the destiantion ***
 ***************************************/
unsigned int CArc :: ARCgetVertexNumber() {
	return uiARCVertexNumber;
}