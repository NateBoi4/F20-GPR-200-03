#version 450

layout (location = 0) out vec4 rtFragColor;

uniform sampler2D uTex;

in vec2 vTexcoord;


void main()
{
	// UV for input image
    vec2 uv = vTexcoord;
    
    rtFragColor = texture(uTex, uv);
    
    //Reference: https://en.wikipedia.org/wiki/Relative_luminance
    //Luminance float calculated from RGB components of sampled texture. 
    //A reflection of the luminosity function: https://en.wikipedia.org/wiki/Luminosity_function
    float luminance = (rtFragColor.r * 0.2126) + (rtFragColor.g * 0.7152) + (rtFragColor.b * 0.0722);
    
    //Uses luminance to perform a bright pass which emphasizes light and minimizes darkness
    //From places with great light intensity.
    //Luminance multiplication is performed multiple times to strengthen effect.
    rtFragColor.rgb *= luminance;
    rtFragColor.rgb *= luminance;
    rtFragColor.rgb *= luminance;
}