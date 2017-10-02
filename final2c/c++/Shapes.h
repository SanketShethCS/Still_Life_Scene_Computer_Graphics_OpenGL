//
// Shapes.h
//
// Prototypes for shape-drawing functions.
//
// This file should not be modified by students.
//	Contributer- Sanket Sheth sas6792@g.rit.edu
//

#ifndef _SHAPES_H_
#define _SHAPES_H_

#include "Canvas.h"

// Macros for object and shading selection
#define OBJ_BELOW	0
#define OBJ_BEHIND	1
#define OBJ_GLASS	2
#define OBJ_GRAPES	3
#define OBJ_BRIE	4
#define OBJ_BOTTLE	5
#define OBJ_MUG		6
#define OBJ_SLAB	7
#define OBJ_QUAD	8


///
// Make either a quad or teapot
//
// @param choice - 0 for quad. 1 for teapot
// @param C      - the Canvas we'll use
///
void makeShape( int choice, Canvas &C );

#endif
