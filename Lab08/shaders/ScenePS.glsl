#version 450


#ifdef GL_ES
precision highp float;
#endif //GL_ES

layout (location = 0) out vec4 rtFragColor;
//out vec4 rtFragColor;

// VARYING
// PER-VERTEX: recieve final color
in vec4 vColor;

//PER-FRAGMENT: recieving stuff used for final color
in vec4 vNormal;

void main()
{
	//rtFragColor = vec4(0.5, 0.0, 0.25, 1.0);
	
	//PER-VERTEX: input is just final color
	//rtFragColor = vColor;
	vec4 N = normalize(vNormal);
	//PER-FRAGMENT: calulate final color here using inputs
	rtFragColor = vec4(N.xyz * 0.5 + 0.5, 1.0);
}