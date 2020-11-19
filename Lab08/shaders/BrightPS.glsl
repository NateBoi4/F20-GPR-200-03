#version 450

// Code by Nathan Boisvert 2020
// This file contains the Fragment Shader of the Bright Pass in my Pipeline which adds luminace to my output.
// This shader performs the calculations for the luminace effect and applies the result to the sampled texture from the previous pass.

layout (location = 0) out vec4 rtFragColor;

uniform sampler2D uTex;

in vec2 vTexcoord;

//Bright Pass method achieved through luminance taken from Lab 06: https://www.shadertoy.com/view/3sycR1
//Multipass pipeline fragment shader that utilizes texture coordinate for NDC
void main()
{
	// UV for input image
    vec2 uv = vTexcoord;
    vec4 col = texture(uTex, uv);
    
    //TEST UV
    //rtFragColor = texture(uTex, uv);
    
    //Reference: https://en.wikipedia.org/wiki/Relative_luminance
    //Luminance float calculated from RGB components of sampled texture. 
    //A reflection of the luminosity function: https://en.wikipedia.org/wiki/Luminosity_function
    float luminance = (col.r * 0.2126) + (col.g * 0.7152) + (col.b * 0.0722);
    
    //Uses luminance to perform a bright pass which emphasizes light and minimizes darkness
    //From places with great light intensity.
    //Luminance multiplication is performed multiple times to strengthen effect.
    col.rgb *= luminance;
    col.rgb *= luminance;
    col.rgb *= luminance;
    
    rtFragColor = col;
    
    //TEST OUTPUT
    //rtFragColor = vec4(1.0);
}