#version 450

// Code by Nathan Boisvert 2020
// This file contains the Fragment Shader for the Display Pass in my Pipeline which displays the full screen image.
// This shader calculates the screen-space UV by manually performing the Perspective divide and converting NDC space to screen space
// Then this shader takes the original image from Scene Pass and blends it with the output of the Blur Pass to generate the bloom effect.

#ifdef GL_ES
precision highp float;
#endif //GL_ES

layout (location = 0) out vec4 rtFragColor;

in vec4 vPosClip;

//PER-FRAGMENT: recieving stuff used for final color
in vec4 vNormal;
in vec2 vTexcoord;

uniform sampler2D uTex;
uniform sampler2D uTexOrig;

void main()
{

	//TESTING DISPLAY OUTPUT
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
	
	//rtFragColor = col;
	//rtFragColor = colOrig;
	rtFragColor = col + colOrig; //Additive method for blending
	//rtFragColor = mix(col, colOrig, colOrig.a); //Mixing method for blending
	//rtFragColor = (1.0 - (1.0 - colOrig) * (1.0 - col)); //Screen method for blending
}