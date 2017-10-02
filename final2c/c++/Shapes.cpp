//
// Shapes.cpp
//
// Routines for shape-drawing functions.
//
// This file should not be modified by students.
// Contributer- Sanket Sheth sas6792@g.rit.edu
// Citations-https://www.raywenderlich.com/48293/how-to-export-blender-models-to-opengl-es-part-1 //obj file loading
//	    -http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/         //obj file loading





#include <cmath>
#include <iostream>
#include <fstream>  //for file manipulation
#include <string>
#include <glm/glm.hpp> //for using glm vectors
#include <cstring>
#include <string.h>  //for using string comparison 
using namespace std;

#include "Canvas.h"
#include "Shapes.h"

//file paths for all the object files to be extracted
static const char *filepathBELOW = "/home/stu5/s9/sas6792/Desktop/final2c/c++/below.obj";
static const char *filepathBEHIND = "/home/stu5/s9/sas6792/Desktop/final2c/c++/back.obj";
static const char *filepathGLASS = "/home/stu5/s9/sas6792/Desktop/final2c/c++/glass.obj";
static const char *filepathGRAPES = "/home/stu5/s9/sas6792/Desktop/final2c/c++/grapes.obj";
static const char *filepathBRIE = "/home/stu5/s9/sas6792/Desktop/final2c/c++/brie2.obj";
static const char *filepathBOTTLE = "/home/stu5/s9/sas6792/Desktop/final2c/c++/bottle.obj";
static const char *filepathSLAB = "/home/stu5/s9/sas6792/Desktop/final2c/c++/slab.obj";
static const char *filepathMUG = "/home/stu5/s9/sas6792/Desktop/final2c/c++/mug.obj";




void loadOBJ(Canvas &C,const char *path,vector<glm::vec3> &vertices,vector<glm::vec3> &normals,vector<int> &vertexIndices,vector<int> &normalIndices)
{

//File is extracted and parsed and saved as individual vectors

 FILE * file = fopen(path, "r"); //open object files

 while( 1 ){

    char lineHeader[128];
    
    int res = fscanf(file, "%s", lineHeader);
    if (res == EOF)
        break; 

    
    if ( strcmp( lineHeader, "v" ) == 0 )  //if vertices
	{
    glm::vec3 vertex;
    fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
    vertices.push_back(vertex);
    }else if ( strcmp( lineHeader, "vn" ) == 0 ) //if normal vertices
	{ 
    glm::vec3 normal;
    fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
    normals.push_back(normal);
    }else if ( strcmp( lineHeader, "f" ) == 0 ) //if faces
	{
    std::string vertex1, vertex2, vertex3;
    int vertexIndex[3], normalIndex[3];
    int matches = fscanf(file, "%d//%d %d//%d %d//%d\n", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]);
    
    vertexIndices.push_back(vertexIndex[0]-1); //vertex indices
    vertexIndices.push_back(vertexIndex[1]-1); //vertex indices
    vertexIndices.push_back(vertexIndex[2]-1); //vertex indices
    normalIndices.push_back(normalIndex[0]-1); //normal indices
    normalIndices.push_back(normalIndex[1]-1); //normal indices
    normalIndices.push_back(normalIndex[2]-1); //normal indices
	}
}
     
     
}


void execute(Canvas &C,vector<glm::vec3> vertices,vector<glm::vec3> normals,vector<int> vertexIndices,vector<int> normalIndices)
{
	//thisfunction creates the traingulation and vertices for the object are defined and drawn
    int len = vertexIndices.size()/3;
    for( int i = 0; i < len; i += 1 ) {

        // Calculate the base indices of the three vertices
        int point1 = vertexIndices[3 * i+0];  // slots 0, 1, 2
        int point2 = vertexIndices[3 * i+1]; // slots 3, 4, 5
        int point3 = vertexIndices[3 * i+2]; // slots 6, 7, 8

        Vertex p1 = { vertices[point1].x,
                      vertices[point1].y,
                      vertices[point1].z };

        Vertex p2 = { vertices[point2].x,
                      vertices[point2].y,
                      vertices[point2].z };

        Vertex p3 = { vertices[point3].x,
                      vertices[point3].y,
                      vertices[point3].z };

        // Calculate the base indices of the three normals
        int normal1 = normalIndices[3 * i+0];     // slots 0, 1, 2
        int normal2 = normalIndices[3 * i+1]; // slots 3, 4, 5
        int normal3 = normalIndices[3 * i+2]; // slots 6, 7, 8

        Normal n1 = { normals[normal1].x,
                      normals[normal1].y,
                      normals[normal1].z };

        Normal n2 = { normals[normal2].x,
                      normals[normal1].y,
                      normals[normal1].z };

        Normal n3 = { normals[normal3].x,
                      normals[normal3].y,
                      normals[normal3].z };

        // Add triangle and vertex normals
        C.addTriangleWithNorms( p1, n1, p2, n2, p3, n3 );

    }
}

 void executet( Canvas &C,vector<glm::vec3> vertices,vector<glm::vec3> normals,vector<int> vertexIndices,vector<int> normalIndices )
{
	//this function extracts the uv vertices for texture mapping
    int i;
	int len = vertexIndices.size()/3;

    for( int i = 0; i < len; i += 1 ) {

        // Calculate the base indices of the three vertices
        int point1 = vertexIndices[3 * i+0];  // slots 0, 1, 2
        int point2 = vertexIndices[3 * i+1]; // slots 3, 4, 5
        int point3 = vertexIndices[3 * i+2]; // slots 6, 7, 8

        Vertex p1 = { vertices[point1].x,
                      vertices[point1].y,
                      vertices[point1].z };

        Vertex p2 = { vertices[point2].x,
                      vertices[point2].y,
                      vertices[point2].z };

        Vertex p3 = { vertices[point3].x,
                      vertices[point3].y,
                      vertices[point3].z };

        // UVcoord is really Vertex, so we need a 'z' component
        UVcoord uv1 = { vertices[point1].x, vertices[point1].z, 0.0f }; //as 2d mapping the usual vertices are used for uv extraction
        UVcoord uv2 = { vertices[point2].x, vertices[point2].z, 0.0f }; //as 2d mapping the usual vertices are used for uv extraction
        UVcoord uv3 = { vertices[point3].x, vertices[point3].z, 0.0f }; //as 2d mapping the usual vertices are used for uv extraction

        // Add triangle and texture coordinates
        C.addTriangleWithUV( p1, uv1, p2, uv2, p3, uv3 );
    }
}



static void makeBelow( Canvas &C )
{
	//below vectors and parsing of files along with triabgle creation is carried out
    vector< glm::vec3 > vertices;
    vector< glm::vec3 > normals;
    vector< int > vertexIndices;
    vector< int > normalIndices;
    loadOBJ(C,filepathBELOW,vertices,normals,vertexIndices,normalIndices);
    executet(C,vertices,normals,vertexIndices,normalIndices); //a seperate texture execution function is called
}


static void makeBehind( Canvas &C )
{
	//behind vectors and parsing of files along with triabgle creation is carried out
    vector< glm::vec3 > vertices;
    vector< glm::vec3 > normals;
    vector< int > vertexIndices;
    vector< int > normalIndices;
    loadOBJ(C,filepathBEHIND,vertices,normals,vertexIndices,normalIndices);
    execute(C,vertices,normals,vertexIndices,normalIndices);
}


static void makeBottle( Canvas &C )
{
	 //bottle vectors and parsing of files along with triabgle creation is carried out
    vector< glm::vec3 > vertices;
    vector< glm::vec3 > normals;
    vector< int > vertexIndices;
    vector< int > normalIndices;
    loadOBJ(C,filepathBOTTLE,vertices,normals,vertexIndices,normalIndices);
    execute(C,vertices,normals,vertexIndices,normalIndices);
}


static void makeSlab( Canvas &C )
{
 	//slab vectors and parsing of files along with triabgle creation is carried out
    vector< glm::vec3 > vertices;
    vector< glm::vec3 > normals;
    vector< int > vertexIndices;
    vector< int > normalIndices;
    loadOBJ(C,filepathSLAB,vertices,normals,vertexIndices,normalIndices);
    execute(C,vertices,normals,vertexIndices,normalIndices);
}


static void makeGlass( Canvas &C )
{
   //glass vectors and parsing of files along with triabgle creation is carried out
    vector< glm::vec3 > vertices;
    vector< glm::vec3 > normals;
    vector< int > vertexIndices;
    vector< int > normalIndices;
    loadOBJ(C,filepathGLASS,vertices,normals,vertexIndices,normalIndices);
    execute(C,vertices,normals,vertexIndices,normalIndices);
}


static void makeGrapes( Canvas &C )
{
 	//grapes vectors and parsing of files along with triabgle creation is carried out
    vector< glm::vec3 > vertices;
    vector< glm::vec3 > normals;
    vector< int > vertexIndices;
    vector< int > normalIndices;
    loadOBJ(C,filepathGRAPES,vertices,normals,vertexIndices,normalIndices);
    execute(C,vertices,normals,vertexIndices,normalIndices);
}


static void makeBrie( Canvas &C )
{
	//brie vectors and parsing of files along with triabgle creation is carried out
    vector< glm::vec3 > vertices;
    vector< glm::vec3 > normals;
    vector< int > vertexIndices;
    vector< int > normalIndices;
    loadOBJ(C,filepathBRIE,vertices,normals,vertexIndices,normalIndices);
    execute(C,vertices,normals,vertexIndices,normalIndices);
}


static void makeMug( Canvas &C )
{
	//mug vectors and parsing of files along with triabgle creation is carried out
    vector< glm::vec3 > vertices;
    vector< glm::vec3 > normals;
    vector< int > vertexIndices;
    vector< int > normalIndices;
    loadOBJ(C,filepathMUG,vertices,normals,vertexIndices,normalIndices);
    execute(C,vertices,normals,vertexIndices,normalIndices);
}


//
// The quad is parallel to the XY plane with the front face
// pointing down the +Z axis
//

//
// Each group of three values specifies a quad vertex
//

///
// Make either a quad or teapot
//
// @param choice - 0 for quad. 1 for teapot
// @param C      - the Canvas we'll use
///
void makeShape( int choice, Canvas &C )
{
	//choice function decides which object is to be drawn
	if(choice==OBJ_BELOW){
        makeBelow( C );
	}else if(choice==OBJ_BEHIND){
	makeBehind( C );
	}else if(choice==OBJ_GLASS){
	makeGlass( C );
	}else if(choice==OBJ_GRAPES){
	makeGrapes( C );
	}else if(choice==OBJ_MUG){
	makeMug( C );
	}else if(choice==OBJ_SLAB){
	makeSlab( C );
	}else if(choice==OBJ_BOTTLE){
	makeBottle( C );
	}else if(choice==OBJ_BRIE){
	makeBrie( C );
	}
	
}
