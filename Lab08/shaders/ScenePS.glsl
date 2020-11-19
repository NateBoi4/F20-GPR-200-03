#version 450

// Code by Nathan Boisvert 2020
// This file contains the Fragment Shader for the Scene Pass in my Pipeline for drawing my Geometry
// This shader is responsible for outputting the results of a Per-Vertex coloring as well as Per-Fragment coloring, reflectance, and texturing

#ifdef GL_ES
precision highp float;
#endif //GL_ES

layout (location = 0) out vec4 rtFragColor;

uniform int uID;
uniform vec3 uLightPos;
uniform sampler2D uTexSun;
uniform sampler2D uTexOptic;
uniform sampler2D uTexLightning;
uniform sampler2D uTexIce;


in vec4 vColor;
in vec4 vNormal;
in vec2 vTexcoord;
in vec4 vPosition;

void main()
{
	//rtFragColor = vec4(0.5, 0.0, 0.25, 1.0);
	
	//Array of solid colors
	const vec4 colors[4] = vec4[4](vec4(1.0, 0.0, 0.0, 1.0), vec4(0.0, 1.0, 0.0, 1.0), vec4(0.0, 0.5, 0.5, 1.0), vec4(1.0));
	
	//TESTING OUTPUT FOR SCENE
	//rtFragColor = vColor;
	vec4 N = normalize(vNormal);
	//PER-FRAGMENT: calulate final color here using inputs
	//rtFragColor = vec4(N.xyz * 0.5 + 0.5, 1.0);
	//rtFragColor = vNormal;
	
	//Use solid colors as final color.
	//rtFragColor = colors[uID];
	
	//PER-FRAGMENT Lambertian Reflectance
	//Made references from lab 04 as well as https://www.learnopengles.com/tag/lambertian-reflectance/
	//Source was used to get appropriate method to do per-fragment shading for the lambertian reflectance
	float intensityInv = 0.01;
	float dist = length(uLightPos - vPosition.xyz);
	vec3 lightVector = normalize(uLightPos - vPosition.xyz);
	float diffuse = max(0.0, dot(vNormal.xyz, lightVector));
	float attenuation = 1.0 / ((1.0 + dist * intensityInv) * (1.0 + dist * intensityInv));
	diffuse *= attenuation;
	rtFragColor = vColor * diffuse;
	
	//Use a texture as the final color
	vec2 uv = vTexcoord;
	
	//Array of textures
	const vec4 textures[4] = vec4[4](texture(uTexSun, uv), texture(uTexOptic, uv), texture(uTexLightning, uv), texture(uTexIce, uv));
	
	//rtFragColor = textures[uID];
}