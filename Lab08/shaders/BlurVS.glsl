#version 450

// Code by Nathan Boisvert 2020
// This file contains the Vertex Shader to the Blur Pass in my Pipeline which applies a Gaussian Blur effect to my output.
// This shader is a very basic Vertex Shader.

layout (location = 0) in vec4 aPosition;

//Basic setup for multipass pipeline vertex shader
void main()
{
	gl_Position = aPosition;
}
