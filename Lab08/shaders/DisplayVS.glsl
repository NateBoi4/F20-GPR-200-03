#version 450

layout (location = 0) in vec4 aPosition;

// TRANSFORM UNIFORMS
uniform mat4 uModelMat;
uniform mat4 uViewMat;
uniform mat4 uProjMat;
uniform mat4 uViewProjMat;

out vec4 vPosClip;
out vec2 vTexcoord;
in vec4 vNormal;

void main()
{
	// TESTING DISPLAY
	//mat4 modelViewMat = uViewMat * uModelMat;
	//vec4 pos_camera = modelViewMat * aPosition;
	//vec4 pos_clip = uProjMat * pos_camera;
	gl_Position = aPosition;
	//w = 1.0 because point if orthographic
	//gl_Position = aPosition;
	//w = 1.0 because point
	
	vPosClip = gl_Position;
	
	vTexcoord = aPosition.xy * 0.5 + 0.5;
	
	
	// NOT PART OF VS
	// NDC = CLIP / CLIP.W
	// W = 1.0
	// visible region is contained within [-1, +1]
	
}