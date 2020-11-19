#version 450

// Code by Nathan Boisvert 2020
// This file contains the Vertex Shader for the Bright Pass in my Pipeline which adds luminace to my output.
// This shader provides a basic setup for a Vertex shader being processed by the texture coordinates

layout (location = 0) in vec4 aPosition;

out vec2 vTexcoord;

//Basic setup for multipass pipeline vertex shader as processed by texture coordinate
void main()
{
	gl_Position = aPosition;
	
	vTexcoord = aPosition.xy * 0.5 + 0.5;
}