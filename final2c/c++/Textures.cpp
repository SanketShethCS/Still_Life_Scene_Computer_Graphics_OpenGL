//
//  Textures
//
//  Created by Warren R. Carithers 2016/11/22.
//  Based on code created by Joe Geigel on 1/23/13.
//  Copyright 2016 Rochester Institute of Technology.  All rights reserved.
//
//  Contributor:  Sanket Sheth(sas6792@g.rit.edu)
//
//  Simple class for setting up texture mapping parameters.
//
//  This code can be compiled as either C or C++.
//

#ifdef __cplusplus
#include <iostream>
#else
#include <stdio.h>
#endif

#include "Textures.h"

// this is here in case you are using SOIL;
// if you're not, it can be deleted.
#include <SOIL.h> //using SOIL

#ifdef __cplusplus
using namespace std;
#endif

// Add any global definitions and/or variables you need here.


float ka1=0.5; //ambient light co-efficient
float kd1=0.7; //diffused light co-efficient
float ks1=1.0; //specular light co-efficient
float specularexp1=10.0; //Specular exponent
float lightsourcecolor1[]={1.0,1.0,1.0,1.0};
float lightsourceposition1[]={55.5, 55.0, -55.0, 1.0};
float ambilightcolor1[]={0.9,0.9,0.9,1.0};
///
// This function loads texture data for the GPU.
//
// You will need to write this function, and maintain all of the values
// needed to be sent to the various shaders.
///
void loadTexture( void )
{
    // Add your code here.
	//loading texture image for front and back using SOIL (code from class slides)
	GLuint tex_2ds = SOIL_load_OGL_texture (
 "//home/stu5/s9/sas6792/Desktop/final2c/c++/Red.jpg",  //loading the front cloth image
 SOIL_LOAD_AUTO,
 SOIL_CREATE_NEW_ID,
 SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y |
 SOIL_FLAG_TEXTURE_REPEATS
);
/* check for an error during the load process */
 if ( tex_2ds == 0 ) {
 //printf( "SOIL loading error: '%s'\n", 
 //SOIL_last_result() );
}

GLuint tex_2df = SOIL_load_OGL_texture (
 "//home/stu5/s9/sas6792/Desktop/final2c/c++/Red.jpg", //loading the back cloth image
 SOIL_LOAD_AUTO,
 SOIL_CREATE_NEW_ID,
 SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y |
 SOIL_FLAG_TEXTURE_REPEATS
);
/* check for an error during the load process */
 if ( tex_2df == 0 ) {
 //cout << "SOIL loading error: '%s'\n" << SOIL_last_result() ;
}


glActiveTexture(GL_TEXTURE0 + 0); //activating texture0
glBindTexture(GL_TEXTURE_2D, tex_2ds); //binding texture to sampler


glActiveTexture(GL_TEXTURE0 + 1); //activating texture1
glBindTexture(GL_TEXTURE_2D, tex_2df); //binding texture to sampler

}

///
// This function sets up the parameters for texture use.
//
// You will need to write this function, and maintain all of the values
// needed to be sent to the various shaders.
//
// @param program - The ID of an OpenGL (GLSL) shader program to which
//    parameter values are to be sent
///
void setUpTexture( GLuint program )
{
 //Sending all parameters to various sahders
    GLint textureid0=glGetUniformLocation(program,"tex_2ds"); //sending to fragment shader textureid for front
    GLint textureid1=glGetUniformLocation(program,"tex_2df"); //sending to fragment shader textureid for back
    
    glUniform1i(textureid0,0);
    glUniform1i(textureid1,1);

    GLint al=glGetUniformLocation(program, "ka1"); //sending to fragment shader
    glUniform1f(al,ka1);
	
    GLint dl=glGetUniformLocation(program, "kd1"); //sending to fragment shader
    glUniform1f(dl,kd1);

    GLint sl=glGetUniformLocation(program, "ks1"); //sending to fragment shader
    glUniform1f(sl,ks1);

    GLint sep=glGetUniformLocation(program, "specularexp1"); //sending to fragment shader
    glUniform1f(sep,specularexp1);

    GLint lsc=glGetUniformLocation(program, "lightsourcecolor1"); //sending to fragment shader
    glUniform4fv(lsc,1,lightsourcecolor1);

    GLint lsp=glGetUniformLocation(program, "lightsourceposition1"); //sending to vertex shader
    glUniform4fv(lsp,1,lightsourceposition1);
	
    GLint alc=glGetUniformLocation(program, "ambilightcolor1"); //sending to fragment shader
    glUniform4fv(alc,1,ambilightcolor1);
	
    	
	
}
