#version 330



struct Angle3D
{
	vec3 Sin;
	vec3 Cos;
};

struct Trans3D
{
	vec3 Pos;
	Angle3D Rot;
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
layout(location = 4) in vec3 ISin;
layout(location = 5) in vec3 ICos;



out Vert {
	vec3 Original;
	vec3 Absolute;
	vec3 Relative;

	vec3 Normal;
	vec2 Tex;
} vs_out;



void rot(inout float pls, inout float mns, in float fsin, in float fcos)
{
	float tmp;
	tmp = fcos * pls - fsin * mns;
	mns = fcos * mns + fsin * pls;
	pls = tmp;
}

vec3 ASD(in vec3 p, in vec3 wSin, in vec3 wCos)
{
	vec3 n = p;
	rot(n.x, n.z, wSin.x, wCos.x);
	rot(n.y, n.z, wSin.y, wCos.y);
	rot(n.y, n.x, wSin.z, wCos.z);
	return n;
}

vec3 DSA(in vec3 p, in vec3 wSin, in vec3 wCos)
{
	vec3 n = p;
	rot(n.x, n.y, wSin.z, wCos.z);
	rot(n.z, n.y, wSin.y, wCos.y);
	rot(n.z, n.x, wSin.x, wCos.x);
	return n;
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
	vs_out.Absolute = DSA(vs_out.Original, ISin, ICos) + IPos;
	vs_out.Relative = ASD(vs_out.Absolute - View.Pos, View.Rot.Sin, View.Rot.Cos);
	gl_Position = proj(vs_out.Relative);

	vs_out.Normal = VNorm;
	vs_out.Tex = VTex;
}
