#version 450

layout (location = 0) in vec4 aPosition;
layout (location = 1) in vec3 aNormal;

// TRANSFORM UNIFORMS
uniform mat4 uModelMat;
uniform mat4 uViewMat;
uniform mat4 uProjMat;
uniform mat4 uViewProjMat;
uniform int uID;


out vec4 vColor;
out vec4 vNormal;
out vec2 vTexcoord;
out vec4 vPosition;

void main()
{
	// POSITION PIPELINE
	mat4 modelViewMat = uViewMat * uModelMat;
	vec4 pos_camera = modelViewMat * aPosition;
	vec4 pos_clip = uProjMat * pos_camera;
	gl_Position = pos_clip;
	vPosition = pos_camera;
	
	// TESTING OUTPUT
	mat3 normalMat = transpose(inverse(mat3(modelViewMat)));
	vec3 norm_camera = normalMat * aNormal;
	//vec3 norm_camera = mat3(modelViewMat) * aNormal;
	
	
	// Final color as solid color. PER-VERTEX
	//vColor = vec4(1.0, 0.5, 0.0, 1.0);
	const vec4 colors[4] = vec4[4](vec4(1.0, 0.0, 0.0, 1.0), vec4(0.0, 1.0, 0.0, 1.0), vec4(0.0, 0.0, 1.0, 1.0), vec4(1.0));
	vColor = colors[uID];
	
	vTexcoord = aPosition.xy * 0.5 + 0.5;
	
	//TESTING OUTPUT
	//vColor = vec4(aNormal * 0.5 + 0.5, 1.0);
	
	//TESTING OUTPUT
	//vNormal = vec4(aNormal, 0.0);
	vNormal = vec4(norm_camera, 0.0);
	
}