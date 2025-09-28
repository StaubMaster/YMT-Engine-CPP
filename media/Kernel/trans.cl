
typedef struct
{
	float X;
	float Y;
	float Z;
} Point3D;

typedef struct
{
	float SinX;
	float SinY;
	float SinZ;
	float CosX;
	float CosY;
	float CosZ;
	float X;
	float Y;
	float Z;
} Angle3D;

typedef struct
{
	Point3D Pos;
	Angle3D Rot;
} Trans3D;



kernel void TransInit(
	global Trans3D * bufferO
)
{
	Trans3D trans;

	trans.Pos.X = (get_global_id(0) - 8.0 + 0.5) * 3;
	trans.Pos.Y = (get_global_id(1) - 8.0 + 0.5) * 3;
	trans.Pos.Z = (get_global_id(2) - 8.0 + 0.5) * 3;

	trans.Rot.X = 0.0;
	trans.Rot.Y = 0.0;
	trans.Rot.Z = 0.0;

	trans.Rot.SinX = sincos(trans.Rot.X, &trans.Rot.CosX);
	trans.Rot.SinY = sincos(trans.Rot.Y, &trans.Rot.CosY);
	trans.Rot.SinZ = sincos(trans.Rot.Z, &trans.Rot.CosZ);

	bufferO[(16 * (16 * (get_global_id(0)) + get_global_id(1)) + get_global_id(2))] = trans;
}



void rot(float * pls, float * mns, float fsin, float fcos)
{
	float temp;
	temp = fcos * (*pls) - fsin * (*mns);
	*mns = fcos * (*mns) + fsin * (*pls);
	*pls = temp;
}

kernel void TransSpinCenter(
	global Trans3D * buffer
)
{
	Trans3D trans = buffer[get_global_id(0)];

	float angle = 0.01f;
	float sin0, cos0;
	sin0 = sincos(angle, &cos0);
	rot(&trans.Pos.X, &trans.Pos.Z, sin0, cos0);

	buffer[get_global_id(0)] = trans;
}
