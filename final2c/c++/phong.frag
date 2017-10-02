#version 150

// Phong fragment shader
//
// Contributor:  Sanket Sheth(sas6792@g.rit.edu)

// INCOMING DATA

// Here is where you should add the variables you need in order
// to propogate data from the vertex shader to the fragment shader
// so that it can do the shading computations
uniform vec4 ambicolor; //from lightning.cpp
uniform vec4 diffcolor; //from lightning.cpp
uniform vec4 speccolor; //from lightning.cpp
uniform float ka; //from lightning.cpp
uniform float kd; //from lightning.cpp
uniform float ks; //from lightning.cpp
uniform float specularexp; //from lightning.cpp
uniform vec4 lightsourcecolor; //from lightning.cpp
uniform vec4 ambilightcolor; //from lightning.cpp

in vec3 norm; //from vertex shader
in vec3 pos; //from vertex shader
in vec3 lightdir; //from vertex shader



// OUTGOING DATA
out vec4 finalColor; //final color values

void main()
{
	vec3 n,l,v,r; //different vector calculations
	n=normalize(norm);
	l=normalize(lightdir-pos);
	v=normalize(pos);
	r=(normalize(reflect(l,n))); //exact reflection of l and n 
	vec4 amb,diff,spec;
	amb=ambicolor*ka*ambilightcolor; //ambient shading value
	float dotln=dot(n,l);
	diff=diffcolor*kd*max(0.0,dotln); //diffuse shading value 
	vec4 fdiff = diff*lightsourcecolor; //diffuse shading with light source color
	float dotvr=dot(v,r);
	float powvr=pow(max(0.0,dotvr),specularexp);
	spec=speccolor*ks*powvr; //specular shading value
	vec4 fspec = spec *lightsourcecolor; //specular shading with light source color
	
	
    // Replace this code with your implementation of this shader
    finalColor = amb+fdiff+fspec; //total of all three to get final shading value for each pixel
}
