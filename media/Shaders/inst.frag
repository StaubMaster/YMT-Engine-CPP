#version 330

uniform float[7]	DepthFactors;
uniform float[7]	depthFactor;
const float[3]	depthFadeRange = float[3]( 0.8, 0.2, 1.0 );
const vec3		depthFadeColor = vec3(0.5, 0.5, 0.5);

uniform sampler2DArray texture0;



in Vert {
	vec3 Original;
	vec3 Absolute;
	vec3 Relative;

	vec3 Normal;
	vec2 Tex;
} fs_inn;

out vec4 Color;



void main()
{
	vec3 col = texture(texture0, vec3(fs_inn.Tex, 0)).rgb;



	float depth_factor;

	//depth_factor = gl_FragDepth;
	depth_factor = gl_FragCoord.z;
//	depth_factor = depthFactor[4] / (depthFactor[3] - (depth_factor * depthFactor[2]));
	depth_factor = DepthFactors[4] / (DepthFactors[3] - (depth_factor * DepthFactors[2]));

	//depth_factor = length(fs_inn.Relative);

//	depth_factor = (depth_factor - depthFactor[0]) / depthFactor[1];
	depth_factor = (depth_factor - DepthFactors[0]) / DepthFactors[1];
	gl_FragDepth = depth_factor;

	//depth_factor = (depth_factor - depthFadeRange[0]) / depthFadeRange[1];
	//depth_factor = min(max(depth_factor, 0), 1);

	//col = vec3(1.0 - depth_factor);
	col = (col * (1.0 - depth_factor)) + (depth_factor * depthFadeColor);



	Color = vec4(col, 1);
}
