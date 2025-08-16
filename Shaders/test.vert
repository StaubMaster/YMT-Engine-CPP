#version 430



uniform vec3[3] view = { vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1) };

uniform vec3[3] trans = { vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1) };



layout(location = 0) in vec3 VPos;
layout(location = 1) in vec2 VTex;

out ColorBlock {
	vec3 Color;
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
	//p_out.z = p_inn.z * depthFactor[5] - depthFactor[6];
	p_out.z = 0;
	p_out.w = p_inn.z;

	//p_out.x = p_out.x * screenRatios[1].x;
	//p_out.y = p_out.y * screenRatios[1].y;

	return p_out;
}

void main()
{
	vs_out.Color = vec3(VTex.x, (VTex.x + VTex.y) * 0.5, VTex.y);

	vec3 pos = VPos;
	pos = DSA(pos, trans[1], trans[2]) + trans[0];
	//pos = ASD(pos - view[0], view[1], view[2]);
	gl_Position = proj(pos);
}
