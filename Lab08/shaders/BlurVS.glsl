#version 450

layout (location = 0) in vec4 aPosition;

out vec2 vTexcoord;

uniform mat4 uModelMat;
uniform mat4 uViewMat;
uniform mat4 uProjMat;


void main()
{
	gl_Position = uProjMat * uViewMat * uModelMat * aPosition;
}
