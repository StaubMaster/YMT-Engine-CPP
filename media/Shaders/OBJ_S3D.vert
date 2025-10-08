#version 330



struct Trans3D
{
	vec3 Pos;
	mat3 Rot;
};

struct SizeRatio2D
{
	vec2 Size;
	vec2 Ratio;
};

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



uniform SizeRatio2D ViewPortSizeRatio;

uniform Trans3D View;

uniform DepthData Depth;



layout(location = 0) in vec4	VPos;
layout(location = 1) in vec3	VTex;
layout(location = 2) in vec3	VNorm;

layout(location = 3) in vec3	VCol;

layout(location = 4) in vec3	VAmbientColor;
layout(location = 5) in vec3	VDiffuseColor;
layout(location = 6) in float	VSpecularPower;
layout(location = 7) in vec3	VSpecularColor;

layout(location = 20) in vec3	IPos;
layout(location = 21) in mat3	IRot;



out Vert {
	vec3	Original;
	vec3	Absolute;
	vec3	Relative;

	vec3	Normal;
	vec3	Tex;

	vec3	Col;

	vec3	AmbientColor;
	vec3	DiffuseColor;
	float	SpecularPower;
	vec3	SpecularColor;
} vs_out;



vec4 proj(in vec3 p_inn)
{
	vec4 p_out;

	p_out.x = p_inn.x;
	p_out.y = p_inn.y;
	p_out.z = p_inn.z * Depth.Factors[5] - Depth.Factors[6];
	p_out.w = p_inn.z;

	p_out.x = p_out.x * ViewPortSizeRatio.Ratio.x;
	p_out.y = p_out.y * ViewPortSizeRatio.Ratio.y;

	return p_out;
}

void main()
{
	vec3 pos;
	vs_out.Original = VPos.xyz;
	vs_out.Absolute = (vs_out.Original * IRot) + IPos;
	vs_out.Relative = (vs_out.Absolute - View.Pos) * View.Rot;
	gl_Position = proj(vs_out.Relative);

	//vs_out.Normal = DSA(VNorm, ISin, ICos);
	vs_out.Normal = VNorm * IRot;
	vs_out.Tex = VTex;
	vs_out.Col = VCol;

	vs_out.AmbientColor = VAmbientColor;
	vs_out.DiffuseColor = VDiffuseColor;
	vs_out.SpecularPower = VSpecularPower;
	vs_out.SpecularColor = VSpecularColor;
}
