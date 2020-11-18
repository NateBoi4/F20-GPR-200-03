#version 450


#ifdef GL_ES
precision highp float;
#endif //GL_ES

layout (location = 0) out vec4 rtFragColor;

//uniform sampler2D uTexture;
uniform int uID;
uniform vec3 uLightPos;
uniform sampler2D uTex;

// VARYING
// PER-VERTEX: recieve final color
in vec4 vColor;

//PER-FRAGMENT: recieving stuff used for final color
in vec4 vNormal;
in vec2 vTexcoord;
in vec4 vPosition;

void main()
{
	//rtFragColor = vec4(0.5, 0.0, 0.25, 1.0);
	
	const vec4 colors[4] = vec4[4](vec4(1.0, 0.0, 0.0, 1.0), vec4(0.0, 1.0, 0.0, 1.0), vec4(0.0, 0.5, 0.5, 1.0), vec4(1.0));
	
	//PER-VERTEX: input is just final color
	//rtFragColor = vColor;
	vec4 N = normalize(vNormal);
	//PER-FRAGMENT: calulate final color here using inputs
	//rtFragColor = vec4(N.xyz * 0.5 + 0.5, 1.0);
	//rtFragColor = vNormal;
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
	
	//rtFragColor = texture(uTex, uv);
}