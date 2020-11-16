#version 450

layout (location = 0) in vec4 aPosition;

out vec2 vTexcoord;


void main()
{
	gl_Position = aPosition;
}
