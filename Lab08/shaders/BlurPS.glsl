#version 450

layout (location = 0) out vec4 rtFragColor;

uniform sampler2D uTex;

in vec2 vTexcoord;

vec4 createRow(in float a, in float b, in float c, in float y, in vec2 resInv, in vec2 fragCoord) 
{
    vec4 currentRow = (a * texture(uTex, (fragCoord + vec2(2.0, y)) * resInv) 
                    + b * texture(uTex, (fragCoord + vec2(1.0, y)) * resInv) 
                    + c * texture(uTex, (fragCoord + vec2(0.0, y)) * resInv)
        		    + b * texture(uTex, (fragCoord + vec2(-1.0, y)) * resInv) 
                    + a * texture(uTex, (fragCoord + vec2(-2.0, y)) * resInv));
    return currentRow;
}

void main()
{
	//Inverse of texture resolution in the xy plane
    vec2 uv = vTexcoord;
    vec2 resInv = 1.0 / uv;
    
    //Reciprocal of weight of sums of a 5x5 kernel.
    float fraction = 1.0 / 256.0;
    
    //Array of the weights that are in the 5x5 kernel
    float weights[6] = float[6](1.0, 4.0, 6.0, 16.0, 24.0, 36.0);
    
    //First row of a 5x5 Kernel with weights of 1 4 6 4 1 located 2.0 pixels above current pixel
    vec4 firstRow = createRow(weights[0], weights[1], weights[2], 2.0, resInv, gl_FragCoord.xy);
    
    //Second row of a 5x5 Kernel with weights of 4 16 24 16 4 located 1.0 pixels above current pixel
    vec4 secondRow = createRow(weights[1], weights[3], weights[4], 1.0, resInv, gl_FragCoord.xy);
    
    //Third row of a 5x5 Kernel with weights of 6 24 36 24 6 located on same y-axis as current pixel
    //Pixel that is weighted by 36 IS the current pixel.
    vec4 thirdRow = createRow(weights[2], weights[4], weights[5], 0.0, resInv, gl_FragCoord.xy);
    
    //Fourth row of a 5x5 Kernel with weights of 4 16 24 16 4 located 1.0 pixels below current pixel
    vec4 fourthRow = createRow(weights[1], weights[3], weights[4], -1.0, resInv, gl_FragCoord.xy);
    
    //First row of a 5x5 Kernel with weights of 1 4 6 4 1 located 2.0 pixels below current pixel
    vec4 fifthRow = createRow(weights[0], weights[1], weights[2], -2.0, resInv, gl_FragCoord.xy);
    
    //Combine all resulting blurred rows and multiply against the reciprocal of the sum of weights
    rtFragColor = fraction * (firstRow + secondRow + thirdRow + fourthRow + fifthRow);
}
