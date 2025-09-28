#version 330



struct RangeData
{
	float Min;
	float Len;
	float Max;
};

struct DepthData
{
	float[7]	Factors;
	RangeData	Range;
	vec3		Color;
};



uniform DepthData Depth;

uniform sampler2DArray texture0;



in Vert {
	vec3 Original;
	vec3 Absolute;
	vec3 Relative;

	vec3 Normal;
	vec2 Tex;
} fs_inn;



out vec4 Color;



float CalcDepthFactor()
{
	float depth_factor;

	depth_factor = gl_FragCoord.z;
	depth_factor = Depth.Factors[4] / (Depth.Factors[3] - (depth_factor * Depth.Factors[2]));

//	depth_factor = length(fs_inn.Relative);

	depth_factor = (depth_factor - Depth.Factors[0]) / Depth.Factors[1];
	gl_FragDepth = depth_factor;

	depth_factor = (depth_factor - Depth.Range.Min) / Depth.Range.Len;
	depth_factor = min(max(depth_factor, 0), 1);

	return depth_factor;
}

void main()
{
	float depth_factor = CalcDepthFactor();

	vec3 col = texture(texture0, vec3(fs_inn.Tex, 0)).rgb;

	col = (col * (1.0 - depth_factor)) + (depth_factor * Depth.Color);

	Color = vec4(col, 1);
}
