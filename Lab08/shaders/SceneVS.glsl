#version 450


//MAIN DUTY: PROCESS ATTRIBUTES
// e.g. 3D position in space
// e.g. normal
// e.g. 2D uv: texture coordinate
layout (location = 0) in vec4 aPosition;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec4 aTexcoord;

// TRANSFORM UNIFORMS
uniform mat4 uModelMat;
uniform mat4 uViewMat;
uniform mat4 uProjMat;
uniform mat4 uViewProjMat;
uniform int uID;

// VARYING

// PER-VERTEX: send final color
out vec4 vColor;

//PER-FRAGMENT: send stuff to the FS to calculate final color
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
	
	// NORMAL PIPELINE
	mat3 normalMat = transpose(inverse(mat3(modelViewMat)));
	vec3 norm_camera = normalMat * aNormal;
	//vec3 norm_camera = mat3(modelViewMat) * aNormal;
	
	
	// OPTIONAL: set varyings
	//vColor = vec4(1.0, 0.5, 0.0, 1.0);
	const vec4 colors[4] = vec4[4](vec4(1.0, 0.0, 0.0, 1.0), vec4(0.0, 1.0, 0.0, 1.0), vec4(0.0, 0.0, 1.0, 1.0), vec4(1.0));
	vColor = colors[uID];
	
	//DEBUGGING:
	
	//PER-VERTEX: calculate and output final color
	//vColor = vec4(aNormal * 0.5 + 0.5, 1.0);
	
	//PER-FRAGMENT: pass things that FS needs to calculate final color
	//vNormal = vec4(aNormal, 0.0);
	vNormal = vec4(norm_camera, 0.0);
	vTexcoord = aPosition.xy * 0.5 + 0.5;
	
}