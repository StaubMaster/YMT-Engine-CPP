#version 430



in ColorBlock {
	vec3 Color;
} fs_inn;

out vec4 Color;



void main()
{
	Color = vec4(fs_inn.Color, 1);
}
