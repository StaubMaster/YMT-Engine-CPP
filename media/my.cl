
kernel void testFunc(
	global int * bufI,
	global int * bufO,
	global int * svmI,
	global int * svmO,
	global int * valI,
	global int * valO
)
{
	bufO[get_global_id(0)] = bufI[get_global_id(0)] + get_global_id(0);
	svmO[get_global_id(0)] = svmI[get_global_id(0)] + get_global_id(0);
	valO[get_global_id(0)] = valI[get_global_id(0)] + get_global_id(0);
}
