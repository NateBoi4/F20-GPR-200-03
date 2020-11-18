#version 450


#ifdef GL_ES
precision highp float;
#endif //GL_ES

layout (location = 0) out vec4 rtFragColor;

// VARYING
// PER-VERTEX: recieve final color
in vec4 vColor;
in vec4 vPosClip;

//PER-FRAGMENT: recieving stuff used for final color
in vec4 vNormal;
in vec2 vTexcoord;

uniform vec2 uResolution;
uniform sampler2D uTex;
uniform sampler2D uTexOrig;

void main()
{

	//PER-VERTEX: input is just final color
	//rtFragColor = vColor;
	//vec4 N = normalize(vNormal);
	//PER-FRAGMENT: calulate final color here using inputs
	//rtFragColor = vec4(1.0);
	//rtFragColor = vPosClip;
	
	//vec2 uv = vTexcoord;
	//vec4 col = texture(uTex, uv);
	//vec4 colOrig = texture(uTexOrig, uv);
	
	
	// MANUAL PERSPECTIVE DIVIDE
	vec4 posNDC = vPosClip / vPosClip.w;
	//rtFragColor = posNDC;
	// [-1, +1] contains visible space
	
	// SCREEN SPACE
	vec4 posScreen = posNDC * 0.5 + 0.5;
	//rtFragColor = posScreen;
	// [-1, +1] -> [0, 1]
	
	vec4 col = texture(uTex, posScreen.xy);
	vec4 colOrig = texture(uTexOrig, posScreen.xy);
	
	// test: remove blue to see RGY gradient
	//rtFragColor.b = 0.0;
	//rtFragColor = col;
	//rtFragColor = colOrig;
	rtFragColor = col + colOrig;
	//rtFragColor = mix(col, colOrig, col.a);
	//rtFragColor = (1.0 - (1.0 - colOrig) * (1.0 - col));
}