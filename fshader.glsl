#version 150

in  vec4 color;
out vec4 fColor;
uniform vec4 vertexColor = {0.0, 0.0, 0.0, 1.0};
void main() 
{ 
	//No fragment processing simply output the interpolated vertex color.
    fColor = vertexColor;
}

