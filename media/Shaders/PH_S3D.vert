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



layout(location = 0) in vec3 VPos;
layout(location = 1) in vec3 VNorm;
layout(location = 2) in vec2 VTex;

layout(location = 3) in vec3 IPos;
layout(location = 4) in mat3 IRot;



out Vert {
	vec3 Original;
	vec3 Absolute;
	vec3 Relative;

	vec3 Normal;
	vec2 Tex;
} vs_out;



vec3 ASD(in vec3 p, in vec3 wSin, in vec3 wCos)
{
	mat3 matX = {
		{ +wCos.x , 0 , -wSin.x },
		{ 0 , 1 , 0 },
		{ +wSin.x , 0 , +wCos.x }
	};

	mat3 matY = {
		{ 1 , 0 , 0 },
		{ 0 , +wCos.y , -wSin.y },
		{ 0 , +wSin.y , +wCos.y }
	};

	mat3 matZ = {
		{ +wCos.z , +wSin.z , 0 },
		{ -wSin.z , +wCos.z , 0 },
		{ 0 , 0 , 1 }
	};

	return p * (matX * matY * matZ);
}

vec3 DSA(in vec3 p, in vec3 wSin, in vec3 wCos)
{
	mat3 matZ = {
		{ +wCos.z , -wSin.z , 0 },
		{ +wSin.z , +wCos.z , 0 },
		{ 0 , 0 , 1 }
	};

	mat3 matY = {
		{ 1 , 0 , 0 },
		{ 0 , +wCos.y , +wSin.y },
		{ 0 , -wSin.y , +wCos.y }
	};

	mat3 matX = {
		{ +wCos.x , 0 , +wSin.x },
		{ 0 , 1 , 0 },
		{ -wSin.x , 0 , +wCos.x }
	};

	return p * (matZ * matY * matX);
}

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
	vs_out.Original = VPos;
	//vs_out.Absolute = DSA(vs_out.Original, ISin, ICos) + IPos;
	//vs_out.Relative = ASD(vs_out.Absolute - View.Pos, View.Rot.Sin, View.Rot.Cos);

	//vs_out.Absolute = (vs_out.Original * IRot) + IPos;
	vs_out.Absolute = vs_out.Original + IPos;

	vs_out.Relative = (vs_out.Absolute - View.Pos) * View.Rot;
	//vs_out.Relative = (vs_out.Absolute - View.Pos);

	gl_Position = proj(vs_out.Relative);

	//vs_out.Normal = -DSA(VNorm, ISin, ICos);
	vs_out.Normal = -(VNorm * View.Rot);
	vs_out.Tex = VTex;
}
