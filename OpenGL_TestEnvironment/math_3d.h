#ifndef MATH_3D_H
#define MATH_3D_H

#include <stdio.h>
#include <math.h>

#define ToRadian(x) ((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

struct Vector3f
{
	float x, y, z;

	Vector3f() { };

	Vector3f(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}


};

#endif