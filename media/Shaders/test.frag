#version 430

uniform float[7]	depthFactor;
const float[3]	depthFadeRange = { 0.8, 0.2, 1.0 };
const vec3		depthFadeColor = vec3(0.5, 0.5, 0.5);

uniform sampler2DArray texture0;



in ColorBlock {
	vec3 Color;
} fs_inn;

out vec4 Color;



void main()
{
	float depth_factor;

	depth_factor = gl_FragDepth;
	depth_factor = depthFactor[4] / (depthFactor[3] - depth_factor * depthFactor[2]);

	depth_factor = (depth_factor - depthFactor[0]) / depthFactor[1];

	depth_factor = (depth_factor - depthFadeRange[0]) / depthFadeRange[1];
	depth_factor = min(max(depth_factor, 0), 1);



	vec3 tex_pos = vec3(fs_inn.Color.xy, 0.0);
	vec4 tex_col = texture(texture0, tex_pos);

	//vec3 col = fs_inn.Color;
	vec3 col = tex_col.rgb;

	//	depth
	col = (col * (1.0 - depth_factor)) + (depth_factor * depthFadeColor);

	Color = vec4(col, 1);
}
