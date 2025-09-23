
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

	trans.Pos.X = get_global_id(0) * 3;
	trans.Pos.Y = 0;
	trans.Pos.Z = 3;

	trans.Rot.X = get_global_id(0) * 0.2;
	trans.Rot.Y = 0;
	trans.Rot.Z = 0;

	trans.Rot.SinX = sincos(trans.Rot.X, &trans.Rot.CosX);
	trans.Rot.SinY = sincos(trans.Rot.Y, &trans.Rot.CosY);
	trans.Rot.SinZ = sincos(trans.Rot.Z, &trans.Rot.CosZ);

	bufferO[get_global_id(0)] = trans;
}
