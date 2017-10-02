#version 150

// Texture mapping vertex shader
//
// Contributor:  Sanket Sheth (sas6792@g.rit.edu)

// INCOMING DATA

uniform sampler2D tex_2ds; //from texture.cpp
uniform sampler2D tex_2df; //from texture.cpp
uniform float ka1; //from texture.cpp
uniform float kd1; //from texture.cpp
uniform float ks1; //from texture.cpp
uniform float specularexp1; //from texture.cpp 
uniform vec4 lightsourcecolor1; //from texture.cpp
uniform vec4 ambilightcolor1; //from texture.cpp

in vec2 texCoord; //from vertex shader
in vec3 norm1; //from vertex shader
in vec3 pos1; //from vertex shader
in vec3 lightdir1; //from vertex shader

// Here is where you should add the variables you need in order
// to propogate data from the vertex shader to the fragment shader
// so that it can do the shading and texture mapping computations

// OUTGOING DATA

out vec4 finalColor; //final shading calculated color for each pixel

void main()
{	

    // Replace this code with your implementation of this shader

	if(gl_FrontFacing){     //check to see if shader is facing front
    	//if front than smiley
	vec3 n,l,v,r;  //all vector calculations
	n=normalize(norm1);
	l=normalize(lightdir1-pos1);
	v=normalize(pos1);
	r=(normalize(reflect(l,n))); //Exact reflection over l and n
	vec4 amb,diff,spec;
	amb=texture2D( tex_2ds, texCoord)*ka1*ambilightcolor1; //ambient light total calculation using texture as primary component
	float dotln=dot(n,l);
	diff=texture2D( tex_2ds, texCoord)*kd1*max(0.0,dotln); //diffuse light total calculation using texture as primary component
	vec4 fdiff = diff*lightsourcecolor1; //diffuse with light source color
	float dotvr=dot(v,r);
	float powvr=pow(max(0.0,dotvr),specularexp1);
	spec=texture2D( tex_2ds, texCoord)*ks1*powvr; //specular light total calculation using texture as primary component
	vec4 fspec = spec *lightsourcecolor1;	 //specular with light source color
		

 	finalColor = amb+fdiff+fspec; //total of all three colors to get shading final value
	}
	else{
        //else it is facing back and hence frowny face
	vec3 n,l,v,r; //all vector calculations
	n=normalize(norm1);
	l=normalize(lightdir1-pos1);
	v=normalize(pos1);
	r=(normalize(reflect(l,n))); //Exact reflection over l and n
	vec4 amb,diff,spec;
	amb=texture2D( tex_2df, texCoord)*ka1*ambilightcolor1; //ambient light total calculation using texture as primary component
	float dotln=dot(n,l);
	diff=texture2D( tex_2df, texCoord)*kd1*max(0.0,dotln); //diffuse light total calculation using texture as primary component
	vec4 fdiff = diff*lightsourcecolor1; //diffuse with light source color
	float dotvr=dot(v,r);
	float powvr=pow(max(0.0,dotvr),specularexp1);
	spec=texture2D( tex_2df, texCoord)*ks1*powvr; //specular light total calculation using texture as primary component
	vec4 fspec = spec *lightsourcecolor1; //specular with light source color


	finalColor = amb+fdiff+fspec; //total of all three colors to get shading final value
	}
}
