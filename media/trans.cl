
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

	trans.Rot.X = 0;
	trans.Rot.Y = 0;
	trans.Rot.Z = 0;

	trans.Rot.SinX = 0;
	trans.Rot.SinY = 0;
	trans.Rot.SinZ = 0;

	trans.Rot.CosX = 1;
	trans.Rot.CosY = 1;
	trans.Rot.CosZ = 1;

	bufferO[get_global_id(0)] = trans;
}
