//
//  Lighting
//
//  Created by Warren R. Carithers 2016/11/22.
//  Based on code created by Joe Geigel on 1/23/13.
//  Copyright 2016 Rochester Institute of Technology.  All rights reserved.
//
//  Contributor:  Sanket Sheth (sas6792@g.rit.edu)
//
//  Simple class for setting up Phong illumination/shading.
//
//  This code can be compiled as either C or C++.
//

#include "Lighting.h"

// Add any global definitions and/or variables you need here.

//Below b
float ambicolorb[]={0.4f, 0.01175f, 0.01175f, 0.55f}; //ambient light material color
float diffcolorb[]={0.7f, 0.04136f, 0.04136f, 0.55f}; //diffused light material color
float speccolorb[]={0.3f, 0.3f, 0.3f, 0.3f}; ////specular light material color
float kab=0.5; //ambient light co-efficient
float kdb=0.7; //diffused light co-efficient
float ksb=1.0; //specular light co-efficient
float specularexpb=10.0; //Specular exponent
float lightsourcecolorb[]={1.0,1.0,1.0,1.0};
float lightsourcepositionb[]={85.5, 55.0, -55.0, 1.0};
float ambilightcolorb[]={0.0,0.0,0.0,1.0};

//Behind bd
float ambicolorbd[]={0.3f,0.15f,0.05f,1.0f}; //ambient light material color
float diffcolorbd[]={0.3f,0.15f,0.05f,1.0f}; //diffused light material color
float speccolorbd[]={1.0f,1.0f,1.0f,1.0f}; ////specular light material color
float kabd=0.5; //ambient light co-efficient
float kdbd=0.7; //diffused light co-efficient
float ksbd=1.0; //specular light co-efficient
float specularexpbd=15.0; //Specular exponent
float lightsourcecolorbd[]={0.8,0.8,0.8,1.0};
float lightsourcepositionbd[]={-2.5, 1.0, 0.0, 1.0};
float ambilightcolorbd[]={0.2,0.2,0.2,1.0};



//Glass g
float ambicolorg[]={1.0,1.0,1.0,1.0}; //ambient light material color
float diffcolorg[]={1.0,1.0,1.0,1.0}; //diffused light material color
float speccolorg[]={1.0,1.0,1.0,1.0}; ////specular light material color
float kag=0.5; //ambient light co-efficient
float kdg=0.7; //diffused light co-efficient
float ksg=1.0; //specular light co-efficient
float specularexpg=10.0; //Specular exponent
float lightsourcecolorg[]={1.0,1.0,1.0,1.0};
float lightsourcepositiong[]={-2.5, 1.0, 2.0, 1.0};
float ambilightcolorg[]={0.7,0.7,0.7,1.0};


//Grapes gs
float ambicolorgs[]={0.7f,0.8f,0.25f,1.0f}; //ambient light material color
float diffcolorgs[]={0.7f,0.8f,0.25f,1.0f}; //diffused light material color
float speccolorgs[]={0.9f,0.9f,0.04f,1.0f}; ////specular light material color
float kags=0.5; //ambient light co-efficient
float kdgs=0.7; //diffused light co-efficient
float ksgs=1.0; //specular light co-efficient
float specularexpgs=10.0; //Specular exponent
float lightsourcecolorgs[]={1.0,1.0,1.0,1.0};
float lightsourcepositiongs[]={-2.5, -4.5, 20.0, 1.0};
float ambilightcolorgs[]={0.9,0.9,0.9,1.0};



//Slab s
float ambicolors[]={0.6f, 0.35f, 0.18f, 1.0f }; //ambient light material color
float diffcolors[]={0.9f, 0.5f, 0.25f, 1.0f}; //diffused light material color
float speccolors[]={0.5, 0.5, 0.5, 1.0f}; ////specular light material color
float kas=0.5; //ambient light co-efficient
float kds=0.7; //diffused light co-efficient
float kss=1.0; //specular light co-efficient
float specularexps=10.0; //Specular exponent
float lightsourcecolors[]={1.0,1.0,1.0,1.0};
float lightsourcepositions[]={75.5, -55.0, -55.0, 1.0};
float ambilightcolors[]={0.8,0.8,0.8,1.0};





//mug m
float ambicolorm[]={0.7f, 0.9f, 0.8f, 1.0f}; //ambient light material color
float diffcolorm[]={0.7f, 0.9f, 0.8f, 1.0f}; //diffused light material color
float speccolorm[]={0.316228f, 0.316228f, 0.316228f, 1.0f}; ////specular light material color
float kam=0.5; //ambient light co-efficient
float kdm=0.7; //diffused light co-efficient
float ksm=1.0; //specular light co-efficient
float specularexpm=10.0; //Specular exponent
float lightsourcecolorm[]={1.0,1.0,1.0,1.0};
float lightsourcepositionm[]={-15.5, -10.0, 10.0, 1.0};
float ambilightcolorm[]={0.6,0.6,0.6,1.0};


//bottle bt
float ambicolorbt[]={0.15,0.05,0.1,1.0}; //ambient light material color
float diffcolorbt[]={0.15,0.05,0.1,1.0}; //diffused light material color
float speccolorbt[]={1.0,1.0,1.0,1.0}; ////specular light material color
float kabt=0.5; //ambient light co-efficient
float kdbt=0.7; //diffused light co-efficient
float ksbt=1.0; //specular light co-efficient
float specularexpbt=10.0; //Specular exponent
float lightsourcecolorbt[]={1.0,1.0,1.0,1.0};
float lightsourcepositionbt[]={-40.5, 0.0,-2.0, 1.0};
float ambilightcolorbt[]={0.8,0.8,0.8,1.0};




//Brie br
float ambicolorbr[]={ 0.99f, 0.7f, 0.3f, 1.0f}; //ambient light material color
float diffcolorbr[]={0.99f, 0.7f, 0.3f, 1.0f}; //diffused light material color
float speccolorbr[]={0.1, 0.1, 0.1, 1.0f}; ////specular light material color
float kabr=0.9; //ambient light co-efficient
float kdbr=0.8; //diffused light co-efficient
float ksbr=1.0; //specular light co-efficient
float specularexpbr=10.0; //Specular exponent
float lightsourcecolorbr[]={0.35,0.35,0.35,1.0};
float lightsourcepositionbr[]={-10.5, 1.0, 1.0, 1.0};
float ambilightcolorbr[]={0.9,0.9,0.8,1.0};




///
// This function sets up the lighting, material, and shading parameters
// for the Phong shader.
//
// You will need to write this function, and maintain all of the values
// needed to be sent to the vertex shader.
//
// @param program - The ID of an OpenGL (GLSL) shader program to which
//    parameter values are to be sent
///
void setUpbelow( GLuint program )
{
 //Set up the below surface
    // Add your code here
	//Sending all parameters to different shaders
	GLint ac=glGetUniformLocation(program, "ambicolor"); //sent to fragment shader
	glUniform4fv(ac,1,ambicolorb); 

	GLint dc=glGetUniformLocation(program, "diffcolor");//sent to fragment shader
	glUniform4fv(dc,1,diffcolorb);
	
	GLint sc=glGetUniformLocation(program, "speccolor");//sent to fragment shader
	glUniform4fv(sc,1,speccolorb);
	
	GLint al=glGetUniformLocation(program, "ka");//sent to fragment shader
	glUniform1f(al,kab);
	
	GLint dl=glGetUniformLocation(program, "kd");//sent to fragment shader
	glUniform1f(dl,kdb);

	GLint sl=glGetUniformLocation(program, "ks");//sent to fragment shader
	glUniform1f(sl,ksb);

	GLint sep=glGetUniformLocation(program, "specularexp");//sent to fragment shader
	glUniform1f(sep,specularexpb);

	GLint lsc=glGetUniformLocation(program, "lightsourcecolor");//sent to fragment shader
	glUniform4fv(lsc,1,lightsourcecolorb);

	GLint lsp=glGetUniformLocation(program, "lightsourceposition"); //sent to vertex shader
	glUniform4fv(lsp,1,lightsourcepositionb);
	
	GLint alc=glGetUniformLocation(program, "ambilightcolor");//sent to fragment shader
	glUniform4fv(alc,1,ambilightcolorb);
	
}

void setUpbehind( GLuint program )
{
    //Set up the behind surface
    // Add your code here
	//Sending all parameters to different shaders
	GLint ac=glGetUniformLocation(program, "ambicolor"); //sent to fragment shader
	glUniform4fv(ac,1,ambicolorbd); 

	GLint dc=glGetUniformLocation(program, "diffcolor");//sent to fragment shader
	glUniform4fv(dc,1,diffcolorbd);
	
	GLint sc=glGetUniformLocation(program, "speccolor");//sent to fragment shader
	glUniform4fv(sc,1,speccolorbd);
	
	GLint al=glGetUniformLocation(program, "ka");//sent to fragment shader
	glUniform1f(al,kabd);
	
	GLint dl=glGetUniformLocation(program, "kd");//sent to fragment shader
	glUniform1f(dl,kdbd);

	GLint sl=glGetUniformLocation(program, "ks");//sent to fragment shader
	glUniform1f(sl,ksbd);

	GLint sep=glGetUniformLocation(program, "specularexp");//sent to fragment shader
	glUniform1f(sep,specularexpbd);

	GLint lsc=glGetUniformLocation(program, "lightsourcecolor");//sent to fragment shader
	glUniform4fv(lsc,1,lightsourcecolorbd);

	GLint lsp=glGetUniformLocation(program, "lightsourceposition"); //sent to vertex shader
	glUniform4fv(lsp,1,lightsourcepositionbd);
	
	GLint alc=glGetUniformLocation(program, "ambilightcolor");//sent to fragment shader
	glUniform4fv(alc,1,ambilightcolorbd);
	
}

void setUpglass( GLuint program )
{
    //Set up the glass object
    // Add your code here
	//Sending all parameters to different shaders
	GLint ac=glGetUniformLocation(program, "ambicolor"); //sent to fragment shader
	glUniform4fv(ac,1,ambicolorg); 

	GLint dc=glGetUniformLocation(program, "diffcolor");//sent to fragment shader
	glUniform4fv(dc,1,diffcolorg);
	
	GLint sc=glGetUniformLocation(program, "speccolor");//sent to fragment shader
	glUniform4fv(sc,1,speccolorg);
	
	GLint al=glGetUniformLocation(program, "ka");//sent to fragment shader
	glUniform1f(al,kag);
	
	GLint dl=glGetUniformLocation(program, "kd");//sent to fragment shader
	glUniform1f(dl,kdg);

	GLint sl=glGetUniformLocation(program, "ks");//sent to fragment shader
	glUniform1f(sl,ksg);

	GLint sep=glGetUniformLocation(program, "specularexp");//sent to fragment shader
	glUniform1f(sep,specularexpg);

	GLint lsc=glGetUniformLocation(program, "lightsourcecolor");//sent to fragment shader
	glUniform4fv(lsc,1,lightsourcecolorg);

	GLint lsp=glGetUniformLocation(program, "lightsourceposition"); //sent to vertex shader
	glUniform4fv(lsp,1,lightsourcepositiong);
	
	GLint alc=glGetUniformLocation(program, "ambilightcolor");//sent to fragment shader
	glUniform4fv(alc,1,ambilightcolorg);
	
}


void setUpgrapes( GLuint program )
{
    //Set up the grapes object
    // Add your code here
	//Sending all parameters to different shaders
	GLint ac=glGetUniformLocation(program, "ambicolor"); //sent to fragment shader
	glUniform4fv(ac,1,ambicolorgs); 

	GLint dc=glGetUniformLocation(program, "diffcolor");//sent to fragment shader
	glUniform4fv(dc,1,diffcolorgs);
	
	GLint sc=glGetUniformLocation(program, "speccolor");//sent to fragment shader
	glUniform4fv(sc,1,speccolorgs);
	
	GLint al=glGetUniformLocation(program, "ka");//sent to fragment shader
	glUniform1f(al,kags);
	
	GLint dl=glGetUniformLocation(program, "kd");//sent to fragment shader
	glUniform1f(dl,kdgs);

	GLint sl=glGetUniformLocation(program, "ks");//sent to fragment shader
	glUniform1f(sl,ksgs);

	GLint sep=glGetUniformLocation(program, "specularexp");//sent to fragment shader
	glUniform1f(sep,specularexpgs);

	GLint lsc=glGetUniformLocation(program, "lightsourcecolor");//sent to fragment shader
	glUniform4fv(lsc,1,lightsourcecolorgs);

	GLint lsp=glGetUniformLocation(program, "lightsourceposition"); //sent to vertex shader
	glUniform4fv(lsp,1,lightsourcepositiongs);
	
	GLint alc=glGetUniformLocation(program, "ambilightcolor");//sent to fragment shader
	glUniform4fv(alc,1,ambilightcolorgs);
	
}


void setUpslab( GLuint program )
{
    //Set up the slab object
    // Add your code here
	//Sending all parameters to different shaders
	GLint ac=glGetUniformLocation(program, "ambicolor"); //sent to fragment shader
	glUniform4fv(ac,1,ambicolors); 

	GLint dc=glGetUniformLocation(program, "diffcolor");//sent to fragment shader
	glUniform4fv(dc,1,diffcolors);
	
	GLint sc=glGetUniformLocation(program, "speccolor");//sent to fragment shader
	glUniform4fv(sc,1,speccolors);
	
	GLint al=glGetUniformLocation(program, "ka");//sent to fragment shader
	glUniform1f(al,kas);
	
	GLint dl=glGetUniformLocation(program, "kd");//sent to fragment shader
	glUniform1f(dl,kds);

	GLint sl=glGetUniformLocation(program, "ks");//sent to fragment shader
	glUniform1f(sl,kss);

	GLint sep=glGetUniformLocation(program, "specularexp");//sent to fragment shader
	glUniform1f(sep,specularexps);

	GLint lsc=glGetUniformLocation(program, "lightsourcecolor");//sent to fragment shader
	glUniform4fv(lsc,1,lightsourcecolors);

	GLint lsp=glGetUniformLocation(program, "lightsourceposition"); //sent to vertex shader
	glUniform4fv(lsp,1,lightsourcepositions);
	
	GLint alc=glGetUniformLocation(program, "ambilightcolor");//sent to fragment shader
	glUniform4fv(alc,1,ambilightcolors);
	
}

void setUpmug( GLuint program )
{
	//Set up the mug object
    // Add your code here
	//Sending all parameters to different shaders
	GLint ac=glGetUniformLocation(program, "ambicolor"); //sent to fragment shader
	glUniform4fv(ac,1,ambicolorm); 

	GLint dc=glGetUniformLocation(program, "diffcolor");//sent to fragment shader
	glUniform4fv(dc,1,diffcolorm);
	
	GLint sc=glGetUniformLocation(program, "speccolor");//sent to fragment shader
	glUniform4fv(sc,1,speccolorm);
	
	GLint al=glGetUniformLocation(program, "ka");//sent to fragment shader
	glUniform1f(al,kam);
	
	GLint dl=glGetUniformLocation(program, "kd");//sent to fragment shader
	glUniform1f(dl,kdm);

	GLint sl=glGetUniformLocation(program, "ks");//sent to fragment shader
	glUniform1f(sl,ksm);

	GLint sep=glGetUniformLocation(program, "specularexp");//sent to fragment shader
	glUniform1f(sep,specularexpm);

	GLint lsc=glGetUniformLocation(program, "lightsourcecolor");//sent to fragment shader
	glUniform4fv(lsc,1,lightsourcecolorm);

	GLint lsp=glGetUniformLocation(program, "lightsourceposition"); //sent to vertex shader
	glUniform4fv(lsp,1,lightsourcepositionm);
	
	GLint alc=glGetUniformLocation(program, "ambilightcolor");//sent to fragment shader
	glUniform4fv(alc,1,ambilightcolorm);
	
}

void setUpbottle( GLuint program )
{
    //Set up the bottle object
    // Add your code here
	//Sending all parameters to different shaders
	GLint ac=glGetUniformLocation(program, "ambicolor"); //sent to fragment shader
	glUniform4fv(ac,1,ambicolorbt); 

	GLint dc=glGetUniformLocation(program, "diffcolor");//sent to fragment shader
	glUniform4fv(dc,1,diffcolorbt);
	
	GLint sc=glGetUniformLocation(program, "speccolor");//sent to fragment shader
	glUniform4fv(sc,1,speccolorbt);
	
	GLint al=glGetUniformLocation(program, "ka");//sent to fragment shader
	glUniform1f(al,kabt);
	
	GLint dl=glGetUniformLocation(program, "kd");//sent to fragment shader
	glUniform1f(dl,kdbt);

	GLint sl=glGetUniformLocation(program, "ks");//sent to fragment shader
	glUniform1f(sl,ksbt);

	GLint sep=glGetUniformLocation(program, "specularexp");//sent to fragment shader
	glUniform1f(sep,specularexpbt);

	GLint lsc=glGetUniformLocation(program, "lightsourcecolor");//sent to fragment shader
	glUniform4fv(lsc,1,lightsourcecolorbt);

	GLint lsp=glGetUniformLocation(program, "lightsourceposition"); //sent to vertex shader
	glUniform4fv(lsp,1,lightsourcepositionbt);
	
	GLint alc=glGetUniformLocation(program, "ambilightcolor");//sent to fragment shader
	glUniform4fv(alc,1,ambilightcolorbt);
	
}

void setUpbrie( GLuint program )
{
    //Set up the brie object
    // Add your code here
	//Sending all parameters to different shaders
	GLint ac=glGetUniformLocation(program, "ambicolor"); //sent to fragment shader
	glUniform4fv(ac,1,ambicolorbr); 

	GLint dc=glGetUniformLocation(program, "diffcolor");//sent to fragment shader
	glUniform4fv(dc,1,diffcolorbr);
	
	GLint sc=glGetUniformLocation(program, "speccolor");//sent to fragment shader
	glUniform4fv(sc,1,speccolorbr);
	
	GLint al=glGetUniformLocation(program, "ka");//sent to fragment shader
	glUniform1f(al,kabr);
	
	GLint dl=glGetUniformLocation(program, "kd");//sent to fragment shader
	glUniform1f(dl,kdbr);

	GLint sl=glGetUniformLocation(program, "ks");//sent to fragment shader
	glUniform1f(sl,ksbr);

	GLint sep=glGetUniformLocation(program, "specularexp");//sent to fragment shader
	glUniform1f(sep,specularexpbr);

	GLint lsc=glGetUniformLocation(program, "lightsourcecolor");//sent to fragment shader
	glUniform4fv(lsc,1,lightsourcecolorbr);

	GLint lsp=glGetUniformLocation(program, "lightsourceposition"); //sent to vertex shader
	glUniform4fv(lsp,1,lightsourcepositionbr);
	
	GLint alc=glGetUniformLocation(program, "ambilightcolor");//sent to fragment shader
	glUniform4fv(alc,1,ambilightcolorbr);
	
}
