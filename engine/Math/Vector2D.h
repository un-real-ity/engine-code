#pragma once
#include <math.h>

struct Vector2D
{
public:
	Vector2D() : x(0), y(0) { }
	Vector2D(float x_, float y_) : x(x_), y(y_) { }
	
	float x, y;

	float SizeSq() const
	{
		return x * x + y * y;
	}

	float Size() const
	{
		return sqrt(SizeSq());
	}

	Vector2D scale(float s) const
	{
		return scale(s, s);
	}

	Vector2D scale(float sx, float sy) const
	{
		return Vector2D(x * sx, y * sy);
	}

	Vector2D translate(float dx, float dy) const
	{
		return Vector2D(x + dx, y + dy);
	}

	Vector2D translate(Vector2D delta) const
	{
		return translate(delta.x, delta.y);
	}

	Vector2D rotate(float angleInRadian) const
	{
		float c = cos(angleInRadian);
		float s = sin(angleInRadian);

		return Vector2D(c * x - s * y, s * x + c * y);
	}
};
