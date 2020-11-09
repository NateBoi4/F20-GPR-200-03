#version 450


//MAIN DUTY: PROCESS ATTRIBUTES
// e.g. 3D position in space
// e.g. normal
// e.g. 2D uv: texture coordinate
layout (location = 0) in vec4 aPosition;
layout (location = 1) in vec3 aNormal;
//in vec4 aPosition;

layout (location = 2) in vec4 aTexcoord;

// TRANSFORM UNIFORMS
uniform mat4 uModelMat;
uniform mat4 uViewMat;
uniform mat4 uProjMat;
uniform mat4 uViewProjMat;

// VARYING

// PER-VERTEX: send final color
out vec4 vColor;

//PER-FRAGMENT: send stuff to the FS to calculate final color
out vec4 vNormal;

void main()
{
	// REQUIRED: set this value:
	// problem: gl_position is in "clip-space"
	// problem: aPosition is in "object-space"
	//gl_Position = aPosition;
	
	// position in world-space (wrong)
	//vec4 pos_world = uModelMat * aPosition;
	//gl_Position = pos_world;
	
	// position in camera-space (also wrong)
	//vec4 pos_camera = uViewMat * uModelMat * aPosition;
	//vec4 pos_camera = uViewMat * pos_world;
	//gl_Position = pos_camera;
	
	// position in clip space (finally!)
	//vec4 pos_clip = uProjMat * uViewMat * uModelMat * aPosition;
	//vec4 pos_clip = uViewProjMat * pos_world;
	
	// POSITION PIPELINE
	mat4 modelViewMat = uViewMat * uModelMat;
	vec4 pos_camera = modelViewMat * aPosition;
	vec4 pos_clip = uProjMat * pos_camera;
	gl_Position = pos_clip;
	
	// NORMAL PIPELINE
	mat3 normalMat = transpose(inverse(mat3(modelViewMat)));
	vec3 norm_camera = normalMat * aNormal;
	//vec3 norm_camera = mat3(modelViewMat) * aNormal;
	
	
	// OPTIONAL: set varyings
	//vColor = vec4(1.0, 0.5, 0.0, 1.0);
	
	//DEBUGGING:
	
	//PER-VERTEX: calculate and output final color
	//vColor = vec4(aNormal * 0.5 + 0.5, 1.0);
	
	//PER-FRAGMENT: pass things that FS needs to calculate final color
	//vNormal = vec4(aNormal, 0.0);
	vNormal = vec4(norm_camera, 0.0);
	
}